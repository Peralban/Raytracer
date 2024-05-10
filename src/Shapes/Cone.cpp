/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Cone
*/

#include "Cone.hpp"

#define SQ(x) ((x)*(x))


RayTracer::Cone::Cone(const Math::Vector3D &origin, double angle, std::shared_ptr<IMaterial> material)
    : _origin(origin), _tan(std::tan(angle)), _sqtan(SQ(_tan)), _material(std::move(material))
{}


bool RayTracer::Cone::hit(const Math::Ray3D &ray, double tmin, double tmax, hits &hit) const
{
    Math::Vector3D oc = ray.getOrigin() - _origin;
    const Math::Vector3D &rayDir = ray.getDirection();

    double a = SQ(rayDir.x) - SQ(rayDir.y) * _sqtan + SQ(rayDir.z);
    double b = 2 * (
        oc.x * rayDir.x -
        oc.y * rayDir.y * _sqtan +
        oc.z * rayDir.z
    );
    double c = SQ(oc.x) - SQ(oc.y) * _sqtan + SQ(oc.z);

    double discriminant = b*b - 4*a*c;

    if (discriminant <= 0) {
        return false;
    }
    double t1 = (-b - sqrt(discriminant)) / (2.0 * a);
    double t2 = (-b + sqrt(discriminant)) / (2.0 * a);
    double hitTime;
    if (t1 < tmin) {
        hitTime = t2;
    } else {
        hitTime = std::min(t1, t2);
    }
    if (hitTime < tmin || hitTime > tmax) {
        return false;
    }
    hit.t = hitTime;
    hit.point = ray.pointOnRay(hit.t);
    hit.normal = __getNormalAt(hit.point);
    hit.material = _material;
    return true;
}

Math::Vector3D RayTracer::Cone::__getNormalAt(const Math::Point3D &point) const noexcept
{
    Math::Vector3D om{point.x - _origin.x, 0., point.z - _origin.z};
    const double y_diff = point.y - _origin.y;

    om.makeUnitVector();
    om.y = std::copysign(_tan, -y_diff);
    return om;
}
