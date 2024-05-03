/*
** EPITECH PROJECT, 2024
** B-OOP-400-NAN-4-1-bsraytracer-florent.charpentier
** File description:
** Camera
*/


#include "Camera.hpp"

RayTracer::Camera::Camera()
{
    _origin = Math::Vector3D(0, 0, 0);
    lowerLeftCorner = Math::Vector3D(-2, -1, -1);
    _horizontal = Math::Vector3D(4, 0, 0);
    _vertical = Math::Vector3D(0, 2, 0);
    _fov = 90;
}

Math::Ray3D RayTracer::Camera::getRay(double u, double v) const {
    return Math::Ray3D(_origin, lowerLeftCorner + _horizontal * u + _vertical * v - _origin);
}
