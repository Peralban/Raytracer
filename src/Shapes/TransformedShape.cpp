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

std::optional<Math::Ray> RayTracer::TransformedShape::hits(const Math::Ray &ray) override
{
    std::optional<Math::Ray> transformed_ray = ray.untransformed(*_tr.get());

    if (!transformed_ray) {
        return std::optional<Math::Ray>();
    }
    std::optional<Math::Ray> hit = _shape->hits(transformed_ray.value());

    if (!hit) {
        return std::optional<Math::Ray>();
    }
    return std::optional(hit.value().transform(*_tr.get()));
}
