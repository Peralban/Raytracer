/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Cone
*/

#include "Torus.hpp"


RayTracer::Torus::Torus(const Math::Vector3D &center, float major_radius, float minor_radius, std::shared_ptr<IMaterial> material)
    : _center(center), _major_radius(major_radius), _minor_radius(minor_radius), _material(material)
{
}

int solve_cubic(float p, float q, float r, float solutions[3]) {
    // Coefficients for the quadratic equation derived from the cubic
    float a = 1.0f;
    float b = p;
    float c = q;
    float d = r;

    // Use Cardano's formula to solve the cubic
    float a_third = a / 3.0f;
    float b_a_third = b / a_third;
    float c_a_third = c / a_third;
    float d_a_third = d / a_third;

    float p_third = b_a_third - c_a_third / 3.0f;
    float q_third = (2.0f * c_a_third / 3.0f) - d_a_third / 2.0f;

    float discriminant = q_third * q_third + p_third * p_third * p_third;

    // Analyze the discriminant to determine the number of solutions
    int num_solutions;
    if (discriminant > 0.0f) {
        // One real solution and two complex solutions (not used here)
        float y1 = std::cbrt(-q_third + std::sqrt(discriminant)) + std::cbrt(-q_third - std::sqrt(discriminant));
        solutions[0] = a_third * (y1 - b_a_third);
        num_solutions = 1;
    } else if (discriminant == 0.0f) {
        // Two real solutions (one may be repeated) and one complex solution (not used here)
        float y1 = 2.0f * std::cbrt(-q_third);
        solutions[0] = a_third * (y1 - b_a_third);
        solutions[1] = a_third * (-y1 - b_a_third);
        num_solutions = 2;
    } else {
        // Three real solutions
        float angle = std::acos(-q_third / (2.0f * std::sqrt(-p_third * p_third * p_third)));
        float y1 = 2.0f * std::sqrt(-p_third) * std::cos(angle / 3.0f) + b_a_third;
        float y2 = 2.0f * std::sqrt(-p_third) * std::cos(angle / 3.0f + 2.0f * M_PI / 3.0f) + b_a_third;
        float y3 = 2.0f * std::sqrt(-p_third) * std::cos(angle / 3.0f - 2.0f * M_PI / 3.0f) + b_a_third;
        solutions[0] = y1;
        solutions[1] = y2;
        solutions[2] = y3;
        num_solutions = 3;
    }

    return num_solutions;
}


bool solve_quartic(float a, float b, float c, float d, float e, float f, double tmin, double tmax, float &t)
{
    // Coefficients for the cubic equation derived from the quartic
    float p = -3.0f * (b * b) / (2.0f * a) + c;
    float q = 2.0f * b * c / (3.0f * a) - d;
    float r = -(c * c) / (3.0f * a) + e;

    // Solve the cubic equation (methods like Cardano's formula can be used)
    float solutions[3];
    int num_solutions = solve_cubic(p, q, r, solutions);

    // Check for valid intersections within the specified range
    for (int i = 0; i < num_solutions; ++i) {
        float y = solutions[i];
        // Substitute y back into the quadratic equation (ax^2 + bx + c = 0)
        float z1 = y - b / (4.0f * a);
        float discriminant = z1 * z1 - f / a;

        // Check for real solutions within the range
        if (discriminant >= 0.0f) {
            float t1 = z1 + std::sqrt(discriminant) / (2.0f * a);
            float t2 = z1 - std::sqrt(discriminant) / (2.0f * a);

            // Ensure t1 <= t2
            if (t1 > t2) {
                std::swap(t1, t2);
            }

            // Check if the intersection is within the specified range
            if (t1 >= tmin && t1 <= tmax) {
                t = t1;
                return true;
            } else if (t2 >= tmin && t2 <= tmax) {
                t = t2;
                return true;
            }
        }
    }

    // No valid intersections found within the range
    return false;
}

bool RayTracer::Torus::hit(const Math::Ray3D &ray, double tmin, double tmax, hits &hit) const {
    // Pre-calculate constants
    float inv_minor_radius = 1.0f / _minor_radius;
    float inv_minor_radius_sq = inv_minor_radius * inv_minor_radius;
    float major_radius_sq = _major_radius * _major_radius;
    float major_radius_minor_radius_sq = major_radius_sq - _minor_radius * _minor_radius;

    // Pre-calculate some terms
    Math::Vector3D oc = ray.getOrigin() - _center;
    float oc_dot_dir = oc.dot(ray.getDirection());
    float oc_squared = oc.sqLength();
    float a_squared = ray.getDirection().sqLength();

    // Early rejection with AABB (if implemented)
    // ... (code for AABB check)

    // Coefficients of the quartic equation (without redundant calculations)
    float a = a_squared;
    float b = 2.0f * oc_dot_dir;
    float c = oc_squared - major_radius_minor_radius_sq;
    float d = b;
    float e = 2.0f * (oc_dot_dir - major_radius_sq * inv_minor_radius);
    float f = oc_squared + major_radius_minor_radius_sq;

    // Solve the quartic using a more robust method (consider tmin-aliasing)
    if (!solve_quartic(a, b, c, d, e, f, tmin, tmax, hit.t)) {
        return false;
    }

    // Intersection point and normal
    hit.point = ray.pointOnRay(hit.t);
    hit.normal = (hit.point - _center) * inv_minor_radius_sq;

    // Update hit information
    hit.material = _material;

    return true;
}

