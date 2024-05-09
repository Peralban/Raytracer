/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Plane
*/

#include "Plane.hpp"


RayTracer::Plane::Plane() {}


bool RayTracer::Plane::hit(const Math::Ray3D &ray, double tmin, double tmax, hits &hit) const
{
    (void)ray;
    (void)tmin;
    (void)tmax;
    (void)hit;
    return false;
}
