/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Factory
*/

#pragma once

#include <memory>
#include <functional>
#include <stdexcept>
#include "Interfaces/IShape.hpp"
#include "Shapes/Sphere.hpp"
#include "Shapes/Cone.hpp"
#include "Shapes/Torus.hpp"
#include "Shapes/Parallelepiped.hpp"
#include "Shapes/Plane.hpp"
#include "Shapes/CylinderInfinite.hpp"
#include "Shapes/CylinderLimited.hpp"
#include "Raytracer/Light.hpp"
#include "Raytracer/Camera.hpp"
#include "Interfaces/IMaterial.hpp"
#include "DataRetriever/Parsing.hpp"

/**
 * @brief Factory class for creating shshared_ptrapes, cameras, lights, and backgrounds for a ray tracer scene.
 */
namespace Factory {
    class SceneFactory {
    public:

        /**
         * @brief Default constructor.
         */
        SceneFactory();

        /**
         * @brief Destructor.
         */
        ~SceneFactory() = default;

        /**
         * @brief Creates a primitive shape.
         * @tparam Args - Type of arguments for creating the shape.
         * @param type - Type of primitive shape to create.
         * @param arg - Arguments for creating the shape.
         * @return std::shared_ptr<RayTracer::IShape> - Pointer to the created shape.
         */
        std::shared_ptr<RayTracer::IShape> createPrimitive(App::ParsingShape args);

        /**
         * @brief Creates a camera.
         * @return std::shared_ptr<RayTracer::Camera> - Pointer to the created camera.
         */
        static std::shared_ptr<RayTracer::Camera> createCamera(App::ParsingCamera camera);

        /**
         * @brief Creates a light.
         * @return std::shared_ptr<RayTracer::Light> - Pointer to the created light.
         */
        static std::shared_ptr<RayTracer::Light> createLight(App::ParsingLight &light);

        /**
         * @brief Creates a sphere shape.
         * @param sphere - Parsing data for creating the sphere.
         * @return std::shared_ptr<RayTracer::IShape> - Pointer to the created sphere shape.
         */
        std::shared_ptr<RayTracer::IShape> makeSphere(App::ParsingShape &sphere);

        /**
         * @brief Creates a plane shape.
         * @param plane - Parsing data for creating the plane.
         * @return std::shared_ptr<RayTracer::IShape> - Pointer to the created plane shape.
         */
        std::shared_ptr<RayTracer::IShape> makePlane(App::ParsingShape &plane);

        /**
         * @brief Creates a cone shape.
         * @param cone - Parsing data for creating the cone.
         * @return std::shared_ptr<RayTracer::IShape> - Pointer to the created cone shape.
         */
        std::shared_ptr<RayTracer::IShape> makeCone(App::ParsingShape &cone);

        /**
         * @brief Creates a parallelepiped shape.
         * @param cube - Parsing data for creating the parallelepiped.
         * @return std::shared_ptr<RayTracer::IShape> - Pointer to the created parallelepiped shape.
         */
        std::shared_ptr<RayTracer::IShape> makeParallelepiped(App::ParsingShape &parallelepiped);

        /**
         * @brief Creates a cylinder shape.
         * @param cylinder - Parsing data for creating the cylinder.
         * @return std::shared_ptr<RayTracer::IShape> - Pointer to the created cylinder shape.
         */
        std::shared_ptr<RayTracer::IShape> makeCylinder(App::ParsingShape &cylinder);

        /**
         * @brief Creates a limited cylinder shape.
         * @param limitedCylinder - Parsing data for creating the limited cylinder.
         * @return std::shared_ptr<RayTracer::IShape> - Pointer to the created limited cylinder shape.
         */
        std::shared_ptr<RayTracer::IShape> makeLimitedCylinder(App::ParsingShape &limitedCylinder);

        /**
         * @brief Creates a torus shape.
         * @param torus - Parsing data for creating the torus.
         * @return std::shared_ptr<RayTracer::IShape> - Pointer to the created torus shape.
         */
        std::shared_ptr<RayTracer::IShape> makeTorus(App::ParsingShape &torus);
    };

    class ErrorMaterial : public AError {
    public:
        /**
         * @brief Display an error message.
         * @param message The error message to display. Defaults to "Error invalid Material".
         */
        ErrorMaterial() : AError("Error invalid Material") {}
    };

    class ErrorFactory : public AError {
    public:
        /**
         * @brief Display an error message.
         * @param message The error message to display. Defaults to "Error creation of the factory".
         */
        ErrorFactory() : AError("Error creation of the factory") {}
    };
}
