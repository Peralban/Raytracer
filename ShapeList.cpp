/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IShape
*/

#include "ShapeList.hpp"

#include <utility>

RayTracer::ShapeList::ShapeList(std::vector<std::shared_ptr<IShape>> shapes)
    : _shapes(std::move(shapes))
{
}

bool RayTracer::ShapeList::hit(const Math::Ray3D &ray, float tmin, float tmax, hits &hit) const
{
    hits temp;
    bool hitAnything = false;
    float closestSoFar = tmax;

    for (const auto &shape : _shapes) {
        if (shape->hit(ray, tmin, closestSoFar, temp)) {
            hitAnything = true;
            closestSoFar = temp.t;
            hit = temp;
        }
    }
    return hitAnything;
}
