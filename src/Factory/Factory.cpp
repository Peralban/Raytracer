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
#include "Shapes/TransformedShape.hpp"
#include "Transformations/Translation.hpp"
#include "Transformations/Rotation.hpp"
#include "Transformations/Scale.hpp"
#include "Transformations/Shear.hpp"
#include "Core/DLLoader.hpp"
#include <cmath>

Factory::SceneFactory::SceneFactory() {}

std::shared_ptr<RayTracer::IShape> Factory::SceneFactory::createPrimitive(App::ParsingShape args)
{
    using CreateFunc = std::function<std::shared_ptr<RayTracer::IShape>(App::ParsingShape&)>;

    static const std::vector<std::pair<std::string, CreateFunc>> functionMap = {
        {"sphere", [this](App::ParsingShape& shapeArgs) {
            return makeSphere(shapeArgs); 
//        }},
//        {"cone", [this](App::ParsingShape& shapeArgs) {
//            return makeCone(shapeArgs);
//        }},
//        {"parallelepiped", [this](App::ParsingShape& shapeArgs) {
//            return makeParallelepiped(shapeArgs);
//        }},
//        {"cylinder", [this](App::ParsingShape& shapeArgs) {
//            return makeCylinder(shapeArgs);
//        }},
//        {"limited_cylinder", [this](App::ParsingShape& shapeArgs) {
//            return makeLimitedCylinder(shapeArgs);
//        }},
//        {"torus", [this](App::ParsingShape& shapeArgs) {
//            return makeTorus(shapeArgs);
//        }},
//        {"plane", [this](App::ParsingShape& shapeArgs) {
//            return makePlane(shapeArgs);
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

std::shared_ptr<RayTracer::Light> Factory::SceneFactory::createLight(App::ParsingLight &light)
{

    Math::Vector3D position = light.getPosition();
    Math::Vector3D color = light.getColor();
    float intensity = light.getIntensity();
    Math::Vector3D direction =  light.getDirection();
    std::string type = light.getType();

    (void)position;
    (void)color;
    (void)intensity;
    (void)direction;
    (void)type;
    return std::make_shared<RayTracer::Light>();
}

static std::shared_ptr<RayTracer::IMaterial> makeMaterial(App::ParsingMaterial material)
{
    std::string type = material.getType();
    Math::Vector3D color = material.getColor();
    Math::Vector3D material_color(color.x / 255, color.y / 255, color.z / 255);
    Core::DLLoader loader;

    if (type == "matte") {
        loader.loadLib(Factory::ALLPLUGINNAME[Factory::MATTE]);
        std::shared_ptr<RayTracer::Matte> matte(loader.getInstance<RayTracer::Matte>());
        matte->setinfo(material_color);
        return matte;
    }
    if (type == "metal") {
        loader.loadLib(Factory::ALLPLUGINNAME[Factory::METAL]);
        std::shared_ptr<RayTracer::Metal> metal(loader.getInstance<RayTracer::Metal>());
        metal->setinfo(material_color, material.getFuzziness());
        return metal;
    }
    if (type == "glass") {
        loader.loadLib(Factory::ALLPLUGINNAME[Factory::GLASS]);
        std::shared_ptr<RayTracer::Glass> glass(loader.getInstance<RayTracer::Glass>());
        glass->setinfo(material.getRefractiveIndex(), material.getAlbedo());
        return glass;
    }
    throw Factory::ErrorMaterial();
}

std::shared_ptr<RayTracer::IShape> Factory::SceneFactory::makeSphere(App::ParsingShape &sphere)
{
    Math::Vector3D center = sphere.getPosition();
    double radius = (double) sphere.getRadius();
    Core::DLLoader loader;
    try {
        loader.loadLib(ALLPLUGINNAME[SPHERE]);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return nullptr;
    }

    RayTracer::Sphere *shape = loader.getInstance<RayTracer::Sphere>();
    shape->setinfo(center, radius, makeMaterial(sphere.getMaterial()));
    std::shared_ptr<RayTracer::IShape> shape_ptr(shape);

    for (const auto &trans : sphere.getTransformations()) {
        if (trans.getType() == "translation") {
            loader.loadLib(ALLPLUGINNAME[TRANSLATION]);
            std::shared_ptr<RayTracer::Translation> translation(loader.getInstance<RayTracer::Translation>());
            translation->setinfo(trans.getPosition());
            shape_ptr = std::make_shared<RayTracer::TransformedShape>(shape_ptr, translation);
        } else if (trans.getType() == "rotation") {
            loader.loadLib(ALLPLUGINNAME[ROTATION]);
            std::shared_ptr<RayTracer::Rotation> rotation(loader.getInstance<RayTracer::Rotation>());
            rotation->setinfo(trans.getPosition());
            shape_ptr = std::make_shared<RayTracer::TransformedShape>(shape_ptr, rotation);
        } else if (trans.getType() == "scale") {
            loader.loadLib(ALLPLUGINNAME[SCALE]);
            std::shared_ptr<RayTracer::Scale> scale(loader.getInstance<RayTracer::Scale>());
            scale->setinfo(trans.getPosition());
            shape_ptr = std::make_shared<RayTracer::TransformedShape>(shape_ptr, scale);
        } else if (trans.getType() == "shear") {
            loader.loadLib(ALLPLUGINNAME[SHEAR]);
            std::shared_ptr<RayTracer::Shear> shear(loader.getInstance<RayTracer::Shear>());
            shear->setinfo(trans.getPosition());
            shape_ptr = std::make_shared<RayTracer::TransformedShape>(shape_ptr, shear);
        }
    }
    return shape_ptr;
}

//std::shared_ptr<RayTracer::IShape> Factory::SceneFactory::makePlane(App::ParsingShape &plane)
//{
//    Math::Vector3D pos = plane.getPosition();
//    Math::Vector3D norm = plane.getNormal();
//
//    std::shared_ptr <RayTracer::IShape> shape = std::make_shared<RayTracer::Plane>(pos, norm, makeMaterial(plane.getMaterial()));
//    if (plane.getTransformations().size() > 0) {
//        for (auto &trans: plane.getTransformations()) {
//            if (trans.getType() == "translation") {
//                std::shared_ptr <RayTracer::ITransformation> translation = std::make_shared<RayTracer::Translation>(
//                        trans.getPosition());
//                shape = std::make_shared<RayTracer::TransformedShape>(shape, translation);
//            } else if (trans.getType() == "rotation") {
//                std::shared_ptr <RayTracer::ITransformation> rotation = std::make_shared<RayTracer::Rotation>(
//                        trans.getPosition());
//                shape = std::make_shared<RayTracer::TransformedShape>(shape, rotation);
//            } else if (trans.getType() == "scale") {
//                std::shared_ptr <RayTracer::ITransformation> scale = std::make_shared<RayTracer::Scale>(
//                        trans.getPosition());
//                shape = std::make_shared<RayTracer::TransformedShape>(shape, scale);
//            } else if (trans.getType() == "shear") {
//                std::shared_ptr <RayTracer::ITransformation> shear = std::make_shared<RayTracer::Shear>(
//                        trans.getPosition());
//                shape = std::make_shared<RayTracer::TransformedShape>(shape, shear);
//            }
//        }
//    }
//    return shape;
//}
//
//std::shared_ptr<RayTracer::IShape> Factory::SceneFactory::makeCone(App::ParsingShape &cone)
//{
//    Math::Vector3D center = cone.getPosition();
//    double angle = (double) cone.getAngle();
//
//    std::shared_ptr<RayTracer::IShape> shape = std::make_shared<RayTracer::Cone>(center, angle * M_PI / 180, makeMaterial(cone.getMaterial()));
//    if (cone.getTransformations().size() > 0) {
//        for (auto &trans : cone.getTransformations()) {
//            if (trans.getType() == "translation") {
//                std::shared_ptr<RayTracer::ITransformation> translation = std::make_shared<RayTracer::Translation>(trans.getPosition());
//                shape = std::make_shared<RayTracer::TransformedShape>(shape, translation);
//            } else if (trans.getType() == "rotation") {
//                std::shared_ptr<RayTracer::ITransformation> rotation = std::make_shared<RayTracer::Rotation>(Math::Vector3D(trans.getPosition().x * M_PI / 180,
//                trans.getPosition().y * M_PI / 180, trans.getPosition().z * M_PI / 180));
//                shape = std::make_shared<RayTracer::TransformedShape>(shape, rotation);
//            } else if (trans.getType() == "scale") {
//                std::shared_ptr<RayTracer::ITransformation> scale = std::make_shared<RayTracer::Scale>(trans.getPosition());
//                shape = std::make_shared<RayTracer::TransformedShape>(shape, scale);
//            } else if (trans.getType() == "shear") {
//                std::shared_ptr<RayTracer::ITransformation> shear = std::make_shared<RayTracer::Shear>(trans.getPosition());
//                shape = std::make_shared<RayTracer::TransformedShape>(shape, shear);
//            }
//        }
//    }
//    return shape;
//}
//
//std::shared_ptr<RayTracer::IShape> Factory::SceneFactory::makeParallelepiped(App::ParsingShape &parallelepiped)
//{
//    Math::Vector3D center = parallelepiped.getPosition();
//    Math::Vector3D size = parallelepiped.getSize();
//
//    std::shared_ptr<RayTracer::IShape> shape = std::make_shared<RayTracer::Parallelepiped>(center, size.x, size.y, size.z, makeMaterial(parallelepiped.getMaterial()));
//    if (parallelepiped.getTransformations().size() > 0) {
//        for (auto &trans : parallelepiped.getTransformations()) {
//            if (trans.getType() == "translation") {
//                std::shared_ptr<RayTracer::ITransformation> translation = std::make_shared<RayTracer::Translation>(trans.getPosition());
//                shape = std::make_shared<RayTracer::TransformedShape>(shape, translation);
//            } else if (trans.getType() == "rotation") {
//                std::shared_ptr<RayTracer::ITransformation> rotation = std::make_shared<RayTracer::Rotation>(Math::Vector3D(trans.getPosition().x * M_PI / 180,
//                trans.getPosition().y * M_PI / 180, trans.getPosition().z * M_PI / 180));
//                shape = std::make_shared<RayTracer::TransformedShape>(shape, rotation);
//            } else if (trans.getType() == "scale") {
//                std::shared_ptr<RayTracer::ITransformation> scale = std::make_shared<RayTracer::Scale>(trans.getPosition());
//                shape = std::make_shared<RayTracer::TransformedShape>(shape, scale);
//            } else if (trans.getType() == "shear") {
//                std::shared_ptr<RayTracer::ITransformation> shear = std::make_shared<RayTracer::Shear>(trans.getPosition());
//                shape = std::make_shared<RayTracer::TransformedShape>(shape, shear);
//            }
//        }
//    }
//    return shape;
//}
//
//std::shared_ptr<RayTracer::IShape> Factory::SceneFactory::makeCylinder(App::ParsingShape &cylinder)
//{
//    Math::Vector3D center = cylinder.getPosition();
//    double radius = (double) cylinder.getRadius();
//
//    std::shared_ptr<RayTracer::IShape> shape = std::make_shared<RayTracer::CylinderInfinite>(center, radius, makeMaterial(cylinder.getMaterial()));
//    if (cylinder.getTransformations().size() > 0) {
//        for (auto &trans : cylinder.getTransformations()) {
//            if (trans.getType() == "translation") {
//                std::shared_ptr<RayTracer::ITransformation> translation = std::make_shared<RayTracer::Translation>(trans.getPosition());
//                shape = std::make_shared<RayTracer::TransformedShape>(shape, translation);
//            } else if (trans.getType() == "rotation") {
//                std::shared_ptr<RayTracer::ITransformation> rotation = std::make_shared<RayTracer::Rotation>(Math::Vector3D(trans.getPosition().x * M_PI / 180,
//                trans.getPosition().y * M_PI / 180, trans.getPosition().z * M_PI / 180));
//                shape = std::make_shared<RayTracer::TransformedShape>(shape, rotation);
//            } else if (trans.getType() == "scale") {
//                std::shared_ptr<RayTracer::ITransformation> scale = std::make_shared<RayTracer::Scale>(trans.getPosition());
//                shape = std::make_shared<RayTracer::TransformedShape>(shape, scale);
//            } else if (trans.getType() == "shear") {
//                std::shared_ptr<RayTracer::ITransformation> shear = std::make_shared<RayTracer::Shear>(trans.getPosition());
//                shape = std::make_shared<RayTracer::TransformedShape>(shape, shear);
//            }
//        }
//    }
//    return shape;
//}
//
//std::shared_ptr<RayTracer::IShape> Factory::SceneFactory::makeLimitedCylinder(App::ParsingShape &cylinder)
//{
//    Math::Vector3D center = cylinder.getPosition();
//    double radius = (double) cylinder.getRadius();
//    double height = (double) cylinder.getHeight();
//
//    std::shared_ptr<RayTracer::IShape> shape = std::make_shared<RayTracer::CylinderLimited>(center, radius, height, makeMaterial(cylinder.getMaterial()));
//    if (cylinder.getTransformations().size() > 0) {
//        for (auto &trans : cylinder.getTransformations()) {
//            if (trans.getType() == "translation") {
//                std::shared_ptr<RayTracer::ITransformation> translation = std::make_shared<RayTracer::Translation>(trans.getPosition());
//                shape = std::make_shared<RayTracer::TransformedShape>(shape, translation);
//            } else if (trans.getType() == "rotation") {
//                std::shared_ptr<RayTracer::ITransformation> rotation = std::make_shared<RayTracer::Rotation>(Math::Vector3D(trans.getPosition().x * M_PI / 180,
//                trans.getPosition().y * M_PI / 180, trans.getPosition().z * M_PI / 180));
//                shape = std::make_shared<RayTracer::TransformedShape>(shape, rotation);
//            } else if (trans.getType() == "scale") {
//                std::shared_ptr<RayTracer::ITransformation> scale = std::make_shared<RayTracer::Scale>(trans.getPosition());
//                shape = std::make_shared<RayTracer::TransformedShape>(shape, scale);
//            } else if (trans.getType() == "shear") {
//                std::shared_ptr<RayTracer::ITransformation> shear = std::make_shared<RayTracer::Shear>(trans.getPosition());
//                shape = std::make_shared<RayTracer::TransformedShape>(shape, shear);
//            }
//        }
//    }
//    return shape;
//}
//
//std::shared_ptr<RayTracer::IShape> Factory::SceneFactory::makeTorus(App::ParsingShape &torus)
//{
//    Math::Vector3D center = torus.getPosition();
//    Math::Vector3D size = torus.getSize();
//    float radius = size.x;
//    RayTracer::IMaterial *material = nullptr;
//
//    (void)center;
//    (void)radius;
//    (void)material;
//    return std::make_shared<RayTracer::Torus>();
//}
//