/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Shear
*/

#include "Shear.hpp"
#include <iostream>

RayTracer::Shear::Shear()
:   Shear({0, 0, 0})
{
}

RayTracer::Shear::Shear(const Math::Vector3D &coords)
{
    if (!coords.x) {
        _xShear = coords.y;
        _yShear = coords.z;

        _shear_target = &Math::Point3D::x;
        _x_coord = &Math::Point3D::y;
        _y_coord = &Math::Point3D::z;
    } else if (!coords.y) {
        _xShear = coords.x;
        _yShear = coords.z;

        _shear_target = &Math::Point3D::y;
        _x_coord = &Math::Point3D::x;
        _y_coord = &Math::Point3D::z;
    } else {
        _xShear = coords.x;
        _yShear = coords.y;

        _shear_target = &Math::Point3D::z;
        _x_coord = &Math::Point3D::x;
        _y_coord = &Math::Point3D::y;
    }
}

Math::Point3D RayTracer::Shear::transformCoordinates(const Math::Point3D &p)
{
    Math::Point3D ret(p);

    ret.*_x_coord += _xShear * p.*_shear_target;
    ret.*_y_coord += _yShear * p.*_shear_target;

    return ret;
}

std::optional<Math::Point3D>
RayTracer::Shear::untransformCoordinates(const Math::Point3D &p)
{
    Math::Point3D ret(p);

    ret.*_x_coord -= _xShear * p.*_shear_target;
    ret.*_y_coord -= _yShear * p.*_shear_target;

    return ret;
}

void RayTracer::Shear::setinfo(const Math::Point3D &p)
{
    if (!_xShear) {
        _xShear = p.y;
        _yShear = p.z;

        _shear_target = &Math::Point3D::x;
        _x_coord = &Math::Point3D::y;
        _y_coord = &Math::Point3D::z;
    } else if (!_yShear) {
        _xShear = p.x;
        _yShear = p.z;

        _shear_target = &Math::Point3D::y;
        _x_coord = &Math::Point3D::x;
        _y_coord = &Math::Point3D::z;
    } else {
        _xShear = p.x;
        _yShear = p.y;

        _shear_target = &Math::Point3D::z;
        _x_coord = &Math::Point3D::x;
        _y_coord = &Math::Point3D::y;
    }
}


extern "C"
{
    RayTracer::Shear *entry_point()
    {
        return new RayTracer::Shear();
    }

    __attribute__((constructor)) void load()
    {
        std::cout << "Loading SDL2 Graphic" << std::endl;
    }

    __attribute__((destructor)) void unload()
    {
        std::cout << "Unloading SDL2 Graphic" << std::endl;
    }
}
