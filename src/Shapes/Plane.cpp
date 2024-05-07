/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Plane
*/

#include "Plane.hpp"


RayTracer::Plane::Plane() {}


bool RayTracer::Plane::hit(const Math::Ray3D &ray, float tmin, float tmax, hits &hit) const
{
    return false;
}

RayTracer::Plane::~Plane() {}
