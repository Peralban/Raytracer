/*
** EPITECH PROJECT, 2024
** B-OOP-400-NAN-4-1-bsraytracer-florent.charpentier
** File description:
** Camera
*/

#pragma once

#include "Ray3D.hpp"

namespace RayTracer {
    // Forward declaration of Ray3D class
    class Ray3D;

    /**
     * @class Camera
     * @brief Represents a camera in the 3D space.
     *
     * The Camera class is responsible for generating rays that are cast into the scene.
     */
    class Camera {
        public:
            /**
             * @brief Default constructor for the Camera class.
             *
             * Initializes a new instance of the Camera class.
             */
            Camera();

            /**
             * @brief Default destructor for the Camera class.
             */
            ~Camera() = default;

            /**
             * @brief Generates a ray from the camera's position.
             *
             * @param u The horizontal component of the ray's direction.
             * @param v The vertical component of the ray's direction.
             * @return A Ray3D object representing the ray.
             */
            Math::Ray3D getRay(double u, double v) const;

            Math::Vector3D _origin; ///< The origin point of the camera in the 3D space.
            Math::Vector3D lowerLeftCorner; ///< The lower left corner of the camera's view.
            Math::Vector3D _horizontal; ///< The horizontal vector of the camera's view.
            Math::Vector3D _vertical; ///< The vertical vector of the camera's view.
            double _fov; ///< The field of view of the camera.

        protected:
        private:
    };
}
