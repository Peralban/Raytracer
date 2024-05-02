/*
** EPITECH PROJECT, 2024
** B-OOP-400-NAN-4-1-bsraytracer-florent.charpentier
** File description:
** Vector3D
*/

#include <ostream>
#include <complex>
#include "Vector3D.hpp"
#include "Ray3D.hpp"

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
}