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

bool RayTracer::Cylinder::hit(const Math::Ray3D &ray, double tmin, double tmax, hits &hit) const
{
    (void)ray;
    (void)tmin;
    (void)tmax;
    (void)hit;
    return false;
}
