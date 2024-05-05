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

RayTracer::Camera::Camera(Math::Vector3D viewFrom, Math::Vector3D viewAt, Math::Vector3D viewUp, double verticalFieldOfView, double aspect)
{
    double theta = verticalFieldOfView * M_PI / 180;
    double halfHeight = tan(theta / 2);
    double halfWidth = aspect * halfHeight;

    Math::Vector3D w = (viewFrom - viewAt).getUnitVector();
    Math::Vector3D u = viewUp.cross(w).getUnitVector();
    Math::Vector3D v = w.cross(u);

    _origin = viewFrom;
    lowerLeftCorner = viewFrom - u * halfWidth - v * halfHeight - w;
    _horizontal = u * 2 * halfWidth;
    _vertical = v * 2 * halfHeight;
}

Math::Ray3D RayTracer::Camera::getRay(double u, double v) const {
    return Math::Ray3D(_origin, lowerLeftCorner + _horizontal * u + _vertical * v - _origin);
}
