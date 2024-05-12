/*
** EPITECH PROJECT, 2024
** B-OOP-400-NAN-4-1-bsraytracer-florent.charpentier
** File description:
** Ray3D
*/

#include <ostream>
#include <complex>
#include "Vector3D.hpp"
#include "Ray3D.hpp"
#include "Interfaces/ITransformation.hpp"

namespace Math {
    Ray3D::Ray3D() : _origin(), _direction() {}

    Ray3D::Ray3D(const Vector3D &origin, const Vector3D &direction)
        : _origin(origin), _direction(direction) {}

    Vector3D Ray3D::getOrigin() const
    {
        return _origin;
    }

    Vector3D Ray3D::getDirection() const
    {
        return _direction;
    }

    Vector3D Ray3D::pointOnRay(double t) const
    {
        return _origin + _direction * t;
    }

    Ray3D Ray3D::transformed(RayTracer::ITransformation &tr) const noexcept
    {
        Point3D ray_tip = _origin + _direction;
        Point3D transformed_origin = tr.transformCoordinates(_origin);
        Point3D transformed_tip = tr.transformCoordinates(ray_tip);

        return Ray3D(
            transformed_origin,
            transformed_tip - transformed_origin
        );
    }

    std::optional<Ray3D>
    Ray3D::untransformed(RayTracer::ITransformation &tr) const noexcept
    {
        Point3D ray_tip = _origin + _direction;

        std::optional<Point3D> transformed_orig = tr.untransformCoordinates(_origin);
        std::optional<Point3D> transformed_tip = tr.untransformCoordinates(ray_tip);

        if (transformed_orig && transformed_tip) {
            return Ray3D(*transformed_orig, *transformed_tip - *transformed_orig);
        } else {
            return std::optional<Ray3D>();
        }
    }
}
