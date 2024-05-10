/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Plane
*/

#include "Plane.hpp"

bool RayTracer::Plane::hit(const Math::Ray3D &ray, double tmin, double tmax, hits &hit) const
{
    float denom = ray.getDirection().dot(_normal);

    if (std::abs(denom) < 1e-6) {
        return false;
    }

    float t = (_position - ray.getOrigin()).dot(_normal) / denom;

    if (t < tmin || t > tmax) {
        return false;
    }

    Math::Vector3D intersection_point = ray.getOrigin() + ray.getDirection() * t;

    // Check if the ray is hitting the plane from the opposite side
    if (denom < 0) {
        hit.normal = -_normal; // Invert the normal
    } else {
        hit.normal = _normal;
    }

    hit.t = t;
    hit.point = intersection_point;
    hit.material = _material;

    return true;
}

RayTracer::Plane::~Plane()
{
}
