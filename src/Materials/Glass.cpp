/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Glass material
*/

#include "Glass.hpp"


RayTracer::Glass::Glass(float refractionIndexValue, Math::Vector3D albedoValue)
        : refractionIndex(refractionIndexValue), albedo(albedoValue)
{
}

float RayTracer::Glass::schlick(double cosine, float refractionIndexValue) const
{
    float r0 = (1 - refractionIndexValue) / (1 + refractionIndexValue);
    r0 = r0 * r0;
    return r0 + (1 - r0) * pow((1 - cosine), 5);
}

bool RayTracer::Glass::scatter(const Math::Ray3D &ray, const hits &hit, Math::Vector3D &attenuation, Math::Ray3D &scattered) const
{
    attenuation = albedo;

    Math::Vector3D outwardNormal;
    Math::Vector3D reflected = reflect(ray.getDirection(), hit.normal);
    Math::Vector3D refracted;

    double niOverNt;
    double reflectProb; //probability of the ray being reflected
    double cosine; //cosine of the angle between the ray and the normal

    //Here we determine if the ray is enter to the object or going outside

    //When the ray is going inside the object is send to the outside
    if (ray.getDirection().dot(hit.normal) > 0) {
        outwardNormal = -hit.normal;
        niOverNt = refractionIndex;
        cosine = refractionIndex * ray.getDirection().getUnitVector().dot(hit.normal);
    } else { //when the ray shoot into the object
        outwardNormal = hit.normal;
        niOverNt = 1.0 / refractionIndex;
        cosine = -ray.getDirection().getUnitVector().dot(hit.normal);
    }
    //Here we determine if the ray is reflected or refracted (fresnel equation)

    //If refracted ray exists
    if (refract(ray.getDirection(), outwardNormal, niOverNt, refracted)) {
        reflectProb = schlick(cosine, refractionIndex);
    } else { //the case of refracted ray not existing so the reflected ray is 100%
        reflectProb = 1.0;
    }
    //Here we determine if the ray is reflected or refracted
    if (drand48() < reflectProb) {
        scattered = Math::Ray3D(hit.point, reflected);
    } else { // if the ray is refracted
        scattered = Math::Ray3D(hit.point, refracted);
    }
    return true;
}
