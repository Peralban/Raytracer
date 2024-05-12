/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Plane
*/

#include "Plane.hpp"

static void get_plane_uv(const Math::Vector3D &p, double &uPos, double &vPos)
{
    uPos = p.x;
    vPos = p.z;
}

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
    if (denom > 0) {
        hit.normal = -_normal; // Invert the normal
    } else {
        hit.normal = _normal;
    }

    hit.t = t;
    hit.point = intersection_point;
    hit.material = _material;
    get_plane_uv(hit.normal, hit.uPos, hit.vPos);
    return true;
}

RayTracer::Plane::~Plane()
{
}
