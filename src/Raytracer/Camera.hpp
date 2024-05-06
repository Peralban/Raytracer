/*
** EPITECH PROJECT, 2024
** B-OOP-400-NAN-4-1-bsraytracer-florent.charpentier
** File description:
** Camera
*/

#pragma once

#include "Math/Ray3D.hpp"
#include <cmath>

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
             * @brief Constructor for the Camera class.
             *
             * Initializes a new instance of the Camera class with a given view configuration.
             * ^ y
             *
             * @param viewFrom The position of the camera.
             * @param viewAt The point the camera is looking at, the look-at point.
             * @param viewUp The up vector of the camera
             * @param verticalFieldOfView The vertical field of view of the camera.
             * @param aspect The aspect ratio of the camera.
             */
            Camera(Math::Vector3D viewFrom, Math::Vector3D viewAt, Math::Vector3D viewUp, double verticalFieldOfView, double aspect, double aperture, double focusDistance);

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
            Math::Ray3D getRay(double s, double t) const;

            Math::Vector3D _origin; ///< The origin point of the camera in the 3D space.
            Math::Vector3D lowerLeftCorner; ///< The lower left corner of the camera's view.
            Math::Vector3D _horizontal; ///< The horizontal vector of the camera's view.
            Math::Vector3D _vertical; ///< The vertical vector of the camera's view.
            Math::Vector3D _u; // The u basis vector of the camera
            Math::Vector3D _v; // The v basis vector of the camera
            Math::Vector3D _w; // The w basis vector of the camera
            double _lensRadius;


        protected:
        private:
    };
}
