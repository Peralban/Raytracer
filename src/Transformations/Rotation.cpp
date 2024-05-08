/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Rotation
*/

#include "Rotation.hpp"
#include <cmath>

RayTracer::Rotation::Rotation()
:   _angles({0, 0, 0})
{
}

RayTracer::Rotation::Rotation(const Math::Vector3D &angles)
:   _angles(angles)
{
}

Math::Point3D RayTracer::Rotation::transformCoordinates(const Math::Point3D &p)
{
    return p + _angles;
}

std::optional<Math::Point3D>
RayTracer::Rotation::untransformCoordinates(const Math::Point3D &p)
{
    return p - _angles;
}

constexpr inline void RayTracer::Rotation::__apply_one_2d_rotation(
    double angle,
    double &local_x,
    double &local_y
) noexcept
{
    double original_angle = __get_angle_of_points(local_x, local_y);
    double magnitude = __get_magnitude(local_x, local_y, original_angle);

    local_x = magnitude * cos(original_angle + angle);
    local_y = magnitude * sin(original_angle + angle);
}

constexpr inline double RayTracer::Rotation::__get_angle_of_points(
    double x,
    double y
) noexcept
{
    return std::atan2(y, x);
}

constexpr inline double RayTracer::Rotation::__get_magnitude(
    double x,
    double y,
    double angle
) noexcept
{
    if (x != 0) {
        return y / sin(angle);
    } else {
        return x / cos(angle);
    }
}
