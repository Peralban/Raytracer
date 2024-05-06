/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Cone
*/

#include "Cone.hpp"


RayTracer::Cone::Cone(const Math::Vector3D &center, float radius, float height, IMaterial *material)
    : _center(center), _radius(radius), _material(material), _height(height)
{}


bool RayTracer::Cone::hit(const Math::Ray3D &ray, float tmin, float tmax, hits &hit) const
{
    Math::Vector3D oc = ray.getOrigin() - _center;
    float a = pow(ray.getDirection().x, 2) + pow(ray.getDirection().y, 2) - pow(ray.getDirection().z, 2) / pow(_height, 2);
    float b = 2 * (oc.x * ray.getDirection().x + oc.y * ray.getDirection().y - oc.z * ray.getDirection().z / pow(_height, 2));
    float c = pow(oc.x, 2) + pow(oc.y, 2) - pow(oc.z, 2) / pow(_height, 2);
    float discriminant = b*b - 4*a*c;

    if (discriminant > 0) {
        double temp = (-b - sqrt(discriminant)) / (2.0 * a);
        if (temp < tmax && temp > tmin) {
            hit.t = temp;
            hit.point = ray.pointOnRay(hit.t);
            hit.normal = (hit.point - _center) / _height;
            hit.material = _material;
            return true;
        }
        temp = (-b + sqrt(discriminant)) / (2.0 * a);
        if (temp < tmax && temp > tmin) {
            hit.t = temp;
            hit.point = ray.pointOnRay(hit.t);
            hit.normal = (hit.point - _center) / _height;
            hit.material = _material;
            return true;
        }
    }
    return false;
}
