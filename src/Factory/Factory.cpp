/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Factory
*/

#include "Factory.hpp"

SceneFactory::SceneFactory() {}

template<typename Args>
std::unique_ptr<RayTracer::IShape> SceneFactory::createPrimitive(PrimitiveType type, Args args)
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

std::shared_ptr<RayTracer::Camera> SceneFactory::createCamera()
{
    Math::Vector3D viewFrom(0, 0, 0);
    Math::Vector3D viewAt(0, 0, -1);
    Math::Vector3D viewUp(0, 1, 0);
    double verticalFieldOfView = 90.0;
    double aspect = 16.0 / 9.0;
    double aperture = 0.1;
    double focusDistance = 10.0;

    return std::make_unique<RayTracer::Camera>(viewFrom, viewAt, viewUp, verticalFieldOfView, aspect, aperture, focusDistance);
}

std::unique_ptr<RayTracer::Background> SceneFactory::createBackground()
{
    return std::make_unique<RayTracer::Background>();
}

std::unique_ptr<RayTracer::Light> SceneFactory::createLight()
{
    return std::make_unique<RayTracer::Light>();
}

std::unique_ptr<RayTracer::IShape> SceneFactory::makeSphere(ParsingSphere &sphere)
{
    Math::Vector3D center(0, 0, 0);
    float radius = 1.0f;
    RayTracer::IMaterial *material = nullptr;

    return std::make_unique<RayTracer::Sphere>(center, radius, material);
}

std::unique_ptr<RayTracer::IShape> SceneFactory::makePlane(ParsingPlane &plane)
{
    return std::make_unique<RayTracer::Plane>();
}

std::unique_ptr<RayTracer::IShape> SceneFactory::makeCone(ParsingCone &cone)
{
    Math::Vector3D center(0, 0, 0);
    float radius = 1.0f;
    float height = 1.0f;
    RayTracer::IMaterial *material = nullptr;

    return std::make_unique<RayTracer::Cone>(center, radius, height, material);
}

std::unique_ptr<RayTracer::IShape> SceneFactory::makeCube(ParsingCube &cube)
{
    return std::make_unique<RayTracer::Cube>();
}
std::unique_ptr<RayTracer::IShape> SceneFactory::makeCylinder(ParsingCylinder &cylinder)
{
    return std::make_unique<RayTracer::Cylinder>();
}
std::unique_ptr<RayTracer::IShape> SceneFactory::makeTorus(ParsingTorus &torus)
{
    return std::make_unique<RayTracer::Torus>();
}
std::unique_ptr<RayTracer::IShape> SceneFactory::makePrism(ParsingPrism &prism)
{
    return std::make_unique<RayTracer::Prism>();
}
std::unique_ptr<RayTracer::IShape> SceneFactory::makeObj(ParsingObj &obj)
{
    return std::make_unique<RayTracer::Obj>();
}
