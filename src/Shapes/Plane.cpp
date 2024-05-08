/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Plane
*/

#include "Plane.hpp"

bool RayTracer::Plane::hit(const Math::Ray3D &ray, float tmin, float tmax, hits &hit) const
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

    hit.t = t;
    hit.point = intersection_point;
    hit.normal = _normal;
    hit.material = _material;

    return true;
}

RayTracer::Plane::~Plane()
{
}