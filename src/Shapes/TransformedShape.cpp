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
        return std::optional<Math::Ray3D>();
    }
    std::optional<Math::Ray3D> hit = _shape->hit(transformed_ray.value());

    if (!hit) {
        return std::optional<Math::Ray3D>();
    }
    return std::optional(hit.value().transform(*_tr.get()));
}
