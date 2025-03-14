/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IShape
*/

#include "ShapeList.hpp"

RayTracer::ShapeList::ShapeList(std::vector<std::shared_ptr<IShape>> shapesValue)
    : shapes(std::move(shapesValue))
{
}

bool RayTracer::ShapeList::hit(const Math::Ray3D &ray, double tmin, double tmax, hits &hit) const
{
    hits temp;
    bool hitAnything = false;
    float closestSoFar = tmax;

    for (const auto &shape : shapes) {
        if (shape->hit(ray, tmin, closestSoFar, temp)) {
            hitAnything = true;
            closestSoFar = temp.t;
            hit = temp;
        }
    }
    return hitAnything;
}
