/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Cylinder
*/

#include "Shapes/Cylinder.hpp"

RayTracer::Cylinder::Cylinder()
{

}

bool RayTracer::Cylinder::hit(const Math::Ray3D &ray, float tmin, float tmax, hits &hit) const
{
    return false;
}

RayTracer::Cylinder::~Cylinder() {}
