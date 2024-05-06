/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IShape
*/

#include "Sphere.hpp"
#include <cmath>
#include <utility>

RayTracer::Sphere::Sphere(const Math::Vector3D &center, float radius, IMaterial *material)
    : center(center), radius(radius), material(material)
{}

bool RayTracer::Sphere::hit(const Math::Ray3D &ray, float tmin, float tmax, hits &hit) const
{
    Math::Vector3D oc = ray.getOrigin() - center;
    float a = ray.getDirection().dot(ray.getDirection());
    float b = 2.0 * oc.dot(ray.getDirection());
    float c = oc.dot(oc) - radius * radius;
    float discriminant = b*b - 4*a*c;
    // get of the solution for the point on the sphere next to us
    if (discriminant > 0) {
        double temp = (-b - sqrt(discriminant)) / (2.0 * a);
        if (temp < tmax && temp > tmin) {
            hit.t = temp;
            hit.point = ray.pointOnRay(hit.t);
            hit.normal = (hit.point - center) / radius;
            hit.material = material;
            return true;
        }
        // get the solution of the point on the sphere behind the sphere
        // can be considered as useless
        temp = (-b + sqrt(discriminant)) / (2.0 * a);
        if (temp < tmax && temp > tmin) {
            hit.t = temp;
            hit.point = ray.pointOnRay(hit.t);
            hit.normal = (hit.point - center) / radius;
            hit.material = material;
            return true;
        }
    }
    return false;
}

