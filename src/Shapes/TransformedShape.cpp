/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** TransformedShape
*/

#include "TransformedShape.hpp"

RayTracer::TransformedShape::TransformedShape(
    std::unique_ptr<IShape> shape,
    std::unique_ptr<ITransformation> tr
)
:   _shape(std::move(shape)),
    _tr(std::move(tr))
{
}

bool RayTracer::TransformedShape::hit(
    const Math::Ray3D &ray,
    float tmin,
    float tmax,
    hits &hit
) const
{
    std::optional<Math::Ray3D> transformed_ray = ray.untransformed(*_tr.get());

    if (!transformed_ray) {
        return false;
    }
    bool call_hit = _shape->hit(*transformed_ray, tmin, tmax, hit);

    if (!call_hit) {
        return false;
    }
    Math::Point3D normal_tip = hit.point + hit.normal;
    hit.point = _tr->transformCoordinates(hit.point);
    hit.normal = _tr->transformCoordinates(normal_tip) - hit.point;
    return true;
}
