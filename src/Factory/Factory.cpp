/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Factory
*/

#include "Factory.hpp"

Core::SceneFactory::SceneFactory() {}

template<typename Args>
std::unique_ptr<RayTracer::IShape> Core::SceneFactory::createPrimitive(PrimitiveType type, Args args)
{
    switch (type) {
        case PrimitiveType::SPHERE:
            return makeSphere(std::forward<Shape>(args));
        case PrimitiveType::PLANE:
            return makePlane(std::forward<Args>(args));
        case PrimitiveType::CONE:
            return makeCone(std::forward<Args>(args));
        case PrimitiveType::CUBE:
            return makeCube(std::forward<Args>(args));
        case PrimitiveType::CYLINDER:
            return makeCylinder(std::forward<Args>(args));
        case PrimitiveType::TORUS:
            return makeTorus(std::forward<Args>(args));
        case PrimitiveType::PRISM:
            return makePrism(std::forward<Args>(args));
        case PrimitiveType::OBJ:
            return makeObj(std::forward<Args>(args));
        default:
            throw std::runtime_error("Invalid primitive type");
    }
}

std::shared_ptr<RayTracer::Camera> Core::SceneFactory::createCamera(ParsingCamera camera)
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

std::unique_ptr<RayTracer::Background> Core::SceneFactory::createBackground()
{
    return std::make_unique<RayTracer::Background>();
}

std::unique_ptr<RayTracer::Light> Core::SceneFactory::createLight()
{
    return std::make_unique<RayTracer::Light>();
}

std::unique_ptr<RayTracer::IShape> Core::SceneFactory::makeSphere(ParsingSphere &sphere)
{
    Math::Vector3D center(0, 0, 0);
    float radius = 1.0f;
    RayTracer::IMaterial *material = nullptr;

    return std::make_unique<RayTracer::Sphere>(center, radius, material);
}

std::unique_ptr<RayTracer::IShape> Core::SceneFactory::makePlane(ParsingPlane &plane)
{
    return std::make_unique<RayTracer::Plane>();
}

std::unique_ptr<RayTracer::IShape> Core::SceneFactory::makeCone(ParsingCone &cone)
{
    Math::Vector3D center(0, 0, 0);
    float radius = 1.0f;
    float height = 1.0f;
    RayTracer::IMaterial *material = nullptr;

    return std::make_unique<RayTracer::Cone>(center, radius, height, material);
}

std::unique_ptr<RayTracer::IShape> Core::SceneFactory::makeCube(ParsingCube &cube)
{
    return std::make_unique<RayTracer::Cube>();
}
std::unique_ptr<RayTracer::IShape> Core::SceneFactory::makeCylinder(ParsingCylinder &cylinder)
{
    return std::make_unique<RayTracer::Cylinder>();
}
std::unique_ptr<RayTracer::IShape> Core::SceneFactory::makeTorus(ParsingTorus &torus)
{
    return std::make_unique<RayTracer::Torus>();
}
std::unique_ptr<RayTracer::IShape> Core::SceneFactory::makePrism(ParsingPrism &prism)
{
    return std::make_unique<RayTracer::Prism>();
}
std::unique_ptr<RayTracer::IShape> Core::SceneFactory::makeObj(ParsingObj &obj)
{
    return std::make_unique<RayTracer::Obj>();
}
