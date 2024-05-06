/*
** EPITECH PROJECT, 2024
** B-OOP-400-NAN-4-1-bsraytracer-florent.charpentier
** File description:
** Camera
*/


#include "Camera.hpp"

/*
    ^   y
    |
    |
    |  / viewUp (vector)
    | /
    |/
    |--------------> x
   /|
  / |
 /  |
/   v   z (into the screen)


  Camera (viewFrom)
|------------------|  <- view plane at distance d from camera
|                  |
|                  |
|    viewAt -> X   |
|                  |
|                  |
|------------------|
*/


Math::Vector3D randomInUnitDisk()
{
    Math::Vector3D p;
    do {
        p = Math::Vector3D(drand48(), drand48(), 0) * 2.0 - Math::Vector3D(1, 1, 0);
    } while (p.dot(p) >= 1.0);
    return p;
}

RayTracer::Camera::Camera(Math::Vector3D viewFrom, Math::Vector3D viewAt, Math::Vector3D viewUp, double verticalFieldOfView, double aspect, double aperture, double focusDistance)
{
    double theta = verticalFieldOfView * M_PI / 180;
    double halfHeight = tan(theta / 2);
    double halfWidth = aspect * halfHeight;

    _origin = viewFrom;
    _w = (viewFrom - viewAt).getUnitVector();
    _u = viewUp.cross(_w).getUnitVector();
    _v = _w.cross(_u);

    lowerLeftCorner = _origin - (_u * halfWidth * focusDistance) - (_v * halfHeight * focusDistance) - (_w * focusDistance);
    _horizontal = _u * 2 * halfWidth * focusDistance;
    _vertical = _v * 2 * halfHeight * focusDistance;

    _lensRadius = aperture / 2;
}

Math::Ray3D RayTracer::Camera::getRay(double s, double t) const {
    Math::Vector3D rd = randomInUnitDisk() * _lensRadius;
    Math::Vector3D offset = (_u * rd.x )+ (_v * rd.y);
    return Math::Ray3D(_origin + offset, lowerLeftCorner + (_horizontal * s) + (_vertical * t) - _origin - offset);
}
