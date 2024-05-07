/*
** EPITECH PROJECT, 2024
** B-OOP-400-NAN-4-1-bsraytracer-florent.charpentier
** File description:
** Point3D
*/

#include "Point3D.hpp"

const Math::Point3D Math::Point3D::zero(0, 0, 0);
const Math::Point3D Math::Point3D::one(1, 1, 1);

Math::Point3D::Point3D()
:   x(0),
    y(0),
    z(0)
{
}

Math::Point3D::Point3D(double ix, double iy, double iz)
:   x(ix),
    y(iy),
    z(iz)
{
}

Math::Point3D Math::Point3D::operator+(const Math::Vector3D &v) const noexcept
{
    return {
        this->x + v.x,
        this->y + v.y,
        this->z + v.z
    };
}
Math::Point3D &Math::Point3D::operator+=(const Math::Vector3D &v) noexcept
{
    this->x += v.x;
    this->y += v.y;
    this->z += v.z;

    return *this;
}

Math::Point3D Math::Point3D::operator-(const Math::Vector3D &v) const noexcept
{
    return {
        this->x - v.x,
        this->y - v.y,
        this->z - v.z
    };
}
Math::Point3D &Math::Point3D::operator-=(const Math::Vector3D &v) noexcept
{
    this->x -= v.x;
    this->y -= v.y;
    this->z -= v.z;

    return *this;
}

Math::Vector3D Math::Point3D::operator+(const Math::Point3D &other) const noexcept
{
    return {
        other.x - this->x,
        other.y - this->y,
        other.z - this->z
    };
}

Math::Vector3D Math::Point3D::operator-(const Math::Point3D &other) const noexcept
{
    return {
        this->x - other.x,
        this->y - other.y,
        this->z - other.z
    };
}


std::ostream &Math::Point3D::output(std::ostream &os) const noexcept
{
    os << "P3{" << this->x << ", " << this->y << ", " << this->z << "}";
    return os;
}

std::ostream &operator<<(std::ostream &os, const Math::Point3D &p)
{
    p.output(os);
    return os;
}
