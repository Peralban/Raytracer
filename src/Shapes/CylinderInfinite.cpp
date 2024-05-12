/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** CylinderInfinite
*/

#include "CylinderInfinite.hpp"
#include <iostream>
#include <cmath>
#include <utility>


RayTracer::CylinderInfinite::CylinderInfinite(const Math::Vector3D &centerValue, double radiusValue,  std::shared_ptr<IMaterial> materialValue)
    : center(centerValue), radius(radiusValue), material(std::move(materialValue))
{}

static void get_infinite_cylinder_uv(const Math::Vector3D &p, double &uPos, double &vPos)
{
    double phi = atan2(p.z, p.x);
    uPos = 1 - (phi + M_PI) / (2 * M_PI);
    vPos = p.y / 2.0 + 0.5;
}

bool RayTracer::CylinderInfinite::hit(const Math::Ray3D &ray, double tmin, double tmax, RayTracer::hits &hit) const {
    Math::Vector3D oc = ray.getOrigin() - center;
    Math::Vector3D direction = ray.getDirection();
    double a = direction.x * direction.x + direction.z * direction.z;
    double b = 2 * (oc.x * direction.x + oc.z * direction.z);
    double c = oc.x * oc.x + oc.z * oc.z - radius * radius;
    double discriminant = b * b - 4 * a * c;
    double temp = (-b - sqrt(discriminant)) / (2 * a);
    if (discriminant < 0)
        return false;
    if (temp < tmax && temp > tmin) {
        hit.t = temp;
        hit.point = ray.pointOnRay(hit.t);
        hit.normal = Math::Vector3D(hit.point.x - center.x, 0.0, hit.point.z - center.z) / radius;
        hit.material = material;
        get_infinite_cylinder_uv(hit.normal, hit.uPos, hit.vPos);
        return true;
    }
    return false;
}
