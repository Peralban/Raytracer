#include "Parallelepiped.hpp"
#include <cmath>
#include <utility>

RayTracer::Parallelepiped::Parallelepiped(const Math::Vector3D &positionValue, float sizeXValue, float sizeYValue, float sizeZValue, std::shared_ptr<IMaterial> materialValue)
    : position(positionValue), sizeX(sizeXValue), sizeY(sizeYValue), sizeZ(sizeZValue), material(std::move(materialValue))
{}

bool RayTracer::Parallelepiped::hit(const Math::Ray3D &ray, double tmin, double tmax, hits &hit) const
{
    double tx1 = (position.x - ray.getOrigin().x) / ray.getDirection().x;
    double tx2 = (position.x + sizeX - ray.getOrigin().x) / ray.getDirection().x;

    double ty1 = (position.y - ray.getOrigin().y) / ray.getDirection().y;
    double ty2 = (position.y + sizeY - ray.getOrigin().y) / ray.getDirection().y;

    double tz1 = (position.z - ray.getOrigin().z) / ray.getDirection().z;
    double tz2 = (position.z + sizeZ - ray.getOrigin().z) / ray.getDirection().z;

    double tmin_temp = fmax(fmax(fmin(tx1, tx2), fmin(ty1, ty2)), fmin(tz1, tz2));
    double tmax_temp = fmin(fmin(fmax(tx1, tx2), fmax(ty1, ty2)), fmax(tz1, tz2));

    if (tmax_temp < 0)
        return false;

    if (tmin_temp > tmax_temp)
        return false;

    double t = tmin_temp >= tmin ? tmin_temp : tmax_temp;
    if (t < tmin || t > tmax)
        return false;

    hit.t = t;
    hit.point = ray.pointOnRay(hit.t);

    Math::Vector3D normal;

    if (tmin_temp == tx1) {
        normal = Math::Vector3D(-1, 0, 0);
    } else if (tmin_temp == tx2) {
        normal = Math::Vector3D(1, 0, 0);
    } else if (tmin_temp == ty1) {
        normal = Math::Vector3D(0, -1, 0);
    } else if (tmin_temp == ty2) {
        normal = Math::Vector3D(0, 1, 0);
    } else if (tmin_temp == tz1) {
        normal = Math::Vector3D(0, 0, -1);
    } else {
        normal = Math::Vector3D(0, 0, 1);
    }
    hit.normal = normal;
    hit.material = material;
    return true;
}
