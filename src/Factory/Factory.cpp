/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Factory
*/

/**
 * @file Factory.cpp
 * @brief Retrieve parsing data in order to create objects correctly.
 * @see Factory.hpp
 */

#include "Factory.hpp"
#include <algorithm>
#include "Materials/Matte.hpp"
#include "Materials/Metal.hpp"
#include "Materials/Glass.hpp"
#include "Materials/LightDirectional.hpp"
#include "Shapes/TransformedShape.hpp"
#include "Transformations/Translation.hpp"
#include "Transformations/Rotation.hpp"
#include "Transformations/Scale.hpp"
#include "Transformations/Shear.hpp"
#include "Textures/SolidColor.hpp"
#include "Textures/ChessBoardTexture.hpp"
#include "Textures/FromImage.hpp"
#include <cmath>

Factory::SceneFactory::SceneFactory() {}

std::shared_ptr<RayTracer::IShape> Factory::SceneFactory::createPrimitive(App::ParsingShape args)
{
    using CreateFunc = std::function<std::shared_ptr<RayTracer::IShape>(App::ParsingShape&)>;

    static const std::vector<std::pair<std::string, CreateFunc>> functionMap = {
        {"sphere", [this](App::ParsingShape& shapeArgs) {
            return makeSphere(shapeArgs); 
        }},
        {"cone", [this](App::ParsingShape& shapeArgs) {
            return makeCone(shapeArgs); 
        }},
        {"parallelepiped", [this](App::ParsingShape& shapeArgs) {
            return makeParallelepiped(shapeArgs);
        }},
        {"cylinder", [this](App::ParsingShape& shapeArgs) {
            return makeCylinder(shapeArgs); 
        }},
        {"limited_cylinder", [this](App::ParsingShape& shapeArgs) {
            return makeLimitedCylinder(shapeArgs);
        }},
        {"plane", [this](App::ParsingShape& shapeArgs) {
            return makePlane(shapeArgs); 
        }}
    };

    std::string shapeType = args.getType();
    std::transform(shapeType.begin(), shapeType.end(), shapeType.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
    for (const auto& pair : functionMap) {
        if (pair.first == shapeType) {
            return pair.second(args);
        }
    }

    throw Factory::ErrorFactory();
}

std::shared_ptr<RayTracer::Camera> Factory::SceneFactory::createCamera(App::ParsingCamera camera)
{
    Math::Vector3D viewFrom = camera.getViewFrom();
    Math::Vector3D viewAt = camera.getViewAt();
    Math::Vector3D viewUp = camera.getViewUp();
    double fov = static_cast<double>(camera.getFov());
    std::pair<int, int> res = camera.getResolution();
    double resolution = static_cast<double>(res.first) / res.second;
    double aperture = static_cast<double>(camera.getAperture());
    double focusDist = static_cast<double>(camera.getFocusDist());

    return std::make_shared<RayTracer::Camera>(viewFrom, viewAt, viewUp, fov, resolution, aperture, focusDist);
}

static std::shared_ptr<RayTracer::IMaterial> makeMaterial(App::ParsingMaterial material)
{
    std::string type = material.getType();
    Math::Vector3D color = material.getColor();
    Math::Vector3D material_color(color.x / 255, color.y / 255, color.z / 255);
    Math::Vector3D material_color1 = material.getColor1();
    Math::Vector3D material_color2 = material.getColor2();
    Math::Vector3D albedo = material.getAlbedo();
    bool hasTexture = material.hasTexture();
    std::string texture = material.getPath(); // path of texture  or chessboard

    if (type == "matte") {
        if (hasTexture && texture == "chessboard") {
            return std::make_shared<RayTracer::Matte>(std::make_shared<RayTracer::ChessBoardTexture>(material_color1, material_color2, material.getScale()));
        }
        if (hasTexture) {
            return std::make_shared<RayTracer::Matte>(std::make_shared<RayTracer::FromImage>(texture));
        }
        return std::make_shared<RayTracer::Matte>(std::make_shared<RayTracer::SolidColor>(material_color));
    }
    if (type == "metal") {
        if (hasTexture && texture == "chessboard") {
            return std::make_shared<RayTracer::Metal>(std::make_shared<RayTracer::ChessBoardTexture>(material_color1, material_color2, material.getScale()), material.getFuzziness());
        }
        if (hasTexture) {
            return std::make_shared<RayTracer::Metal>(std::make_shared<RayTracer::FromImage>(texture), material.getFuzziness());
        }
        return std::make_shared<RayTracer::Metal>(std::make_shared<RayTracer::SolidColor>(material_color), material.getFuzziness());
    }
    if (type == "glass") {
        if (hasTexture && texture == "chessboard") {
            return std::make_shared<RayTracer::Glass>(material.getRefractiveIndex(), std::make_shared<RayTracer::ChessBoardTexture>(material_color1, material_color2, material.getScale()));
        }
        if (hasTexture) {
            return std::make_shared<RayTracer::Glass>(material.getRefractiveIndex(), std::make_shared<RayTracer::FromImage>(texture));
        }
        return std::make_shared<RayTracer::Glass>(material.getRefractiveIndex(), std::make_shared<RayTracer::SolidColor>(albedo));
    }
    if (type == "light") {
        if (hasTexture && texture == "chessboard") {
            return std::make_shared<RayTracer::LightDirectional>(std::make_shared<RayTracer::ChessBoardTexture>(material_color1, material_color2, material.getScale()), material.getLightIntensity());
        }
        if (hasTexture) {
            return std::make_shared<RayTracer::LightDirectional>(std::make_shared<RayTracer::FromImage>(texture), material.getLightIntensity());
        }
        return std::make_shared<RayTracer::LightDirectional>(std::make_shared<RayTracer::SolidColor>(material_color), material.getLightIntensity());
    }
    throw Factory::ErrorMaterial();
}

std::shared_ptr<RayTracer::IShape> Factory::SceneFactory::makeSphere(App::ParsingShape &sphere)
{
    Math::Vector3D center = sphere.getPosition();
    double radius = (double) sphere.getRadius();

    if (sphere.getTransformations().size() > 0) {
        std::shared_ptr<RayTracer::IShape> shape = std::make_shared<RayTracer::Sphere>(center, radius, makeMaterial(sphere.getMaterial()));
        for (auto &trans : sphere.getTransformations()) {
            if (trans.getType() == "translation") {
                std::shared_ptr<RayTracer::ITransformation> translation = std::make_shared<RayTracer::Translation>(trans.getPosition());
                shape = std::make_shared<RayTracer::TransformedShape>(shape, translation);
            } else if (trans.getType() == "rotation") {
                std::shared_ptr<RayTracer::ITransformation> rotation = std::make_shared<RayTracer::Rotation>(Math::Vector3D(trans.getPosition().x * M_PI / 180,
                trans.getPosition().y * M_PI / 180, trans.getPosition().z * M_PI / 180));
                shape = std::make_shared<RayTracer::TransformedShape>(shape, rotation);
            } else if (trans.getType() == "scale") {
                std::shared_ptr<RayTracer::ITransformation> scale = std::make_shared<RayTracer::Scale>(trans.getPosition());
                shape = std::make_shared<RayTracer::TransformedShape>(shape, scale);
            } else if (trans.getType() == "shear") {
                std::shared_ptr<RayTracer::ITransformation> shear = std::make_shared<RayTracer::Shear>(trans.getPosition());
                shape = std::make_shared<RayTracer::TransformedShape>(shape, shear);
            }
        }
        return shape;
    }
    return std::make_shared<RayTracer::Sphere>(center, radius, makeMaterial(sphere.getMaterial()));
}

std::shared_ptr<RayTracer::IShape> Factory::SceneFactory::makePlane(App::ParsingShape &plane)
{
    Math::Vector3D pos = plane.getPosition();
    Math::Vector3D norm = plane.getNormal();

    std::shared_ptr <RayTracer::IShape> shape = std::make_shared<RayTracer::Plane>(pos, norm, makeMaterial(plane.getMaterial()));
    if (plane.getTransformations().size() > 0) {
        for (auto &trans: plane.getTransformations()) {
            if (trans.getType() == "translation") {
                std::shared_ptr <RayTracer::ITransformation> translation = std::make_shared<RayTracer::Translation>(
                        trans.getPosition());
                shape = std::make_shared<RayTracer::TransformedShape>(shape, translation);
            } else if (trans.getType() == "rotation") {
                std::shared_ptr <RayTracer::ITransformation> rotation = std::make_shared<RayTracer::Rotation>(
                        trans.getPosition());
                shape = std::make_shared<RayTracer::TransformedShape>(shape, rotation);
            } else if (trans.getType() == "scale") {
                std::shared_ptr <RayTracer::ITransformation> scale = std::make_shared<RayTracer::Scale>(
                        trans.getPosition());
                shape = std::make_shared<RayTracer::TransformedShape>(shape, scale);
            } else if (trans.getType() == "shear") {
                std::shared_ptr <RayTracer::ITransformation> shear = std::make_shared<RayTracer::Shear>(
                        trans.getPosition());
                shape = std::make_shared<RayTracer::TransformedShape>(shape, shear);
            }
        }
    }
    return shape;
}

std::shared_ptr<RayTracer::IShape> Factory::SceneFactory::makeCone(App::ParsingShape &cone)
{
    Math::Vector3D center = cone.getPosition();
    double angle = (double) cone.getAngle();

    std::shared_ptr<RayTracer::IShape> shape = std::make_shared<RayTracer::Cone>(center, angle * M_PI / 180, makeMaterial(cone.getMaterial()));
    if (cone.getTransformations().size() > 0) {
        for (auto &trans : cone.getTransformations()) {
            if (trans.getType() == "translation") {
                std::shared_ptr<RayTracer::ITransformation> translation = std::make_shared<RayTracer::Translation>(trans.getPosition());
                shape = std::make_shared<RayTracer::TransformedShape>(shape, translation);
            } else if (trans.getType() == "rotation") {
                std::shared_ptr<RayTracer::ITransformation> rotation = std::make_shared<RayTracer::Rotation>(Math::Vector3D(trans.getPosition().x * M_PI / 180,
                trans.getPosition().y * M_PI / 180, trans.getPosition().z * M_PI / 180));
                shape = std::make_shared<RayTracer::TransformedShape>(shape, rotation);
            } else if (trans.getType() == "scale") {
                std::shared_ptr<RayTracer::ITransformation> scale = std::make_shared<RayTracer::Scale>(trans.getPosition());
                shape = std::make_shared<RayTracer::TransformedShape>(shape, scale);
            } else if (trans.getType() == "shear") {
                std::shared_ptr<RayTracer::ITransformation> shear = std::make_shared<RayTracer::Shear>(trans.getPosition());
                shape = std::make_shared<RayTracer::TransformedShape>(shape, shear);
            }
        }
    }
    return shape;
}

std::shared_ptr<RayTracer::IShape> Factory::SceneFactory::makeParallelepiped(App::ParsingShape &parallelepiped)
{
    Math::Vector3D center = parallelepiped.getPosition();
    Math::Vector3D size = parallelepiped.getSize();

    std::shared_ptr<RayTracer::IShape> shape = std::make_shared<RayTracer::Parallelepiped>(center, size.x, size.y, size.z, makeMaterial(parallelepiped.getMaterial()));
    if (parallelepiped.getTransformations().size() > 0) {
        for (auto &trans : parallelepiped.getTransformations()) {
            if (trans.getType() == "translation") {
                std::shared_ptr<RayTracer::ITransformation> translation = std::make_shared<RayTracer::Translation>(trans.getPosition());
                shape = std::make_shared<RayTracer::TransformedShape>(shape, translation);
            } else if (trans.getType() == "rotation") {
                std::shared_ptr<RayTracer::ITransformation> rotation = std::make_shared<RayTracer::Rotation>(Math::Vector3D(trans.getPosition().x * M_PI / 180,
                trans.getPosition().y * M_PI / 180, trans.getPosition().z * M_PI / 180));
                shape = std::make_shared<RayTracer::TransformedShape>(shape, rotation);
            } else if (trans.getType() == "scale") {
                std::shared_ptr<RayTracer::ITransformation> scale = std::make_shared<RayTracer::Scale>(trans.getPosition());
                shape = std::make_shared<RayTracer::TransformedShape>(shape, scale);
            } else if (trans.getType() == "shear") {
                std::shared_ptr<RayTracer::ITransformation> shear = std::make_shared<RayTracer::Shear>(trans.getPosition());
                shape = std::make_shared<RayTracer::TransformedShape>(shape, shear);
            }
        }
    }
    return shape;
}

std::shared_ptr<RayTracer::IShape> Factory::SceneFactory::makeCylinder(App::ParsingShape &cylinder)
{
    Math::Vector3D center = cylinder.getPosition();
    double radius = (double) cylinder.getRadius();

    std::shared_ptr<RayTracer::IShape> shape = std::make_shared<RayTracer::CylinderInfinite>(center, radius, makeMaterial(cylinder.getMaterial()));
    if (cylinder.getTransformations().size() > 0) {
        for (auto &trans : cylinder.getTransformations()) {
            if (trans.getType() == "translation") {
                std::shared_ptr<RayTracer::ITransformation> translation = std::make_shared<RayTracer::Translation>(trans.getPosition());
                shape = std::make_shared<RayTracer::TransformedShape>(shape, translation);
            } else if (trans.getType() == "rotation") {
                std::shared_ptr<RayTracer::ITransformation> rotation = std::make_shared<RayTracer::Rotation>(Math::Vector3D(trans.getPosition().x * M_PI / 180,
                trans.getPosition().y * M_PI / 180, trans.getPosition().z * M_PI / 180));
                shape = std::make_shared<RayTracer::TransformedShape>(shape, rotation);
            } else if (trans.getType() == "scale") {
                std::shared_ptr<RayTracer::ITransformation> scale = std::make_shared<RayTracer::Scale>(trans.getPosition());
                shape = std::make_shared<RayTracer::TransformedShape>(shape, scale);
            } else if (trans.getType() == "shear") {
                std::shared_ptr<RayTracer::ITransformation> shear = std::make_shared<RayTracer::Shear>(trans.getPosition());
                shape = std::make_shared<RayTracer::TransformedShape>(shape, shear);
            }
        }
    }
    return shape;
}

std::shared_ptr<RayTracer::IShape> Factory::SceneFactory::makeLimitedCylinder(App::ParsingShape &cylinder)
{
    Math::Vector3D center = cylinder.getPosition();
    double radius = (double) cylinder.getRadius();
    double height = (double) cylinder.getHeight();

    std::shared_ptr<RayTracer::IShape> shape = std::make_shared<RayTracer::CylinderLimited>(center, radius, height, makeMaterial(cylinder.getMaterial()));
    if (cylinder.getTransformations().size() > 0) {
        for (auto &trans : cylinder.getTransformations()) {
            if (trans.getType() == "translation") {
                std::shared_ptr<RayTracer::ITransformation> translation = std::make_shared<RayTracer::Translation>(trans.getPosition());
                shape = std::make_shared<RayTracer::TransformedShape>(shape, translation);
            } else if (trans.getType() == "rotation") {
                std::shared_ptr<RayTracer::ITransformation> rotation = std::make_shared<RayTracer::Rotation>(Math::Vector3D(trans.getPosition().x * M_PI / 180,
                trans.getPosition().y * M_PI / 180, trans.getPosition().z * M_PI / 180));
                shape = std::make_shared<RayTracer::TransformedShape>(shape, rotation);
            } else if (trans.getType() == "scale") {
                std::shared_ptr<RayTracer::ITransformation> scale = std::make_shared<RayTracer::Scale>(trans.getPosition());
                shape = std::make_shared<RayTracer::TransformedShape>(shape, scale);
            } else if (trans.getType() == "shear") {
                std::shared_ptr<RayTracer::ITransformation> shear = std::make_shared<RayTracer::Shear>(trans.getPosition());
                shape = std::make_shared<RayTracer::TransformedShape>(shape, shear);
            }
        }
    }
    return shape;
}
