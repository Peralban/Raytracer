/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** CylinderLimited
*/

#include "CylinderLimited.hpp"
#include <iostream>


RayTracer::CylinderLimited::CylinderLimited(const Math::Vector3D &centerValue, double radiusValue, double heightValue, std::shared_ptr<IMaterial> materialValue)
    : center(centerValue), radius(radiusValue), height(heightValue), material(std::move(materialValue))
{}

static void get_limit_cylinder_uv(const Math::Vector3D &p, double &uPos, double &vPos)
{
    double phi = atan2(p.z, p.x);
    uPos = 1 - (phi + M_PI) / (2 * M_PI);
    vPos = p.y / 2.0 + 0.5;
}

bool RayTracer::CylinderLimited::hit(const Math::Ray3D &ray, double tmin, double tmax, RayTracer::hits &hit) const {
    Math::Vector3D oc = ray.getOrigin() - center;
    Math::Vector3D direction = ray.getDirection();
    double a = direction.x * direction.x + direction.z * direction.z;
    double b = 2 * (oc.x * direction.x + oc.z * direction.z);
    double c = oc.x * oc.x + oc.z * oc.z - radius * radius;
    double discriminant = b * b - 4 * a * c;
    
    if (discriminant < 0)
        return false;
    double temp = (-b - sqrt(discriminant)) / (2 * a);
    if (temp < tmax && temp >= tmin) {
        double y = oc.y + temp * direction.y;
        if (y < 0 || y > height)
            return false;
        hit.t = temp;
        hit.point = ray.pointOnRay(hit.t);
        hit.normal = Math::Vector3D(hit.point.x - center.x, 0.0, hit.point.z - center.z) / radius;
        hit.material = material;
        get_limit_cylinder_uv(hit.normal, hit.uPos, hit.vPos);
        return true;
    }
    temp = (-b + sqrt(discriminant)) / (2 * a);
    if (temp < tmax && temp >= tmin) {
        double y = oc.y + temp * direction.y;
        if (y < 0 || y > height)
            return false;
        hit.t = temp;
        hit.point = ray.pointOnRay(hit.t);
        hit.normal = Math::Vector3D(hit.point.x - center.x, 0.0, hit.point.z - center.z) / radius;
        hit.material = material;
        get_limit_cylinder_uv(hit.normal, hit.uPos, hit.vPos);
        return true;
    }
    return false;
}
