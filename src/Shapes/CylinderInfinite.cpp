/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** CylinderInfinite
*/

#include "CylinderInfinite.hpp"
#include <iostream>
#include <utility>


RayTracer::CylinderInfinite::CylinderInfinite(const Math::Vector3D &centerValue, double radiusValue,  IMaterial *materialValue)
    : center(centerValue), radius(radiusValue), material(materialValue)
{}

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
        return true;
    }
    return false;
}
