/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Cone
*/


#pragma once

#include <cmath>
#include "Math/Vector3D.hpp"
#include "Interfaces/IShape.hpp"

namespace RayTracer {
    class Cone : public IShape {
        public:
            Cone() = default;

            Cone(const Math::Vector3D &origin, double angle, std::shared_ptr<IMaterial> material);

            ~Cone() = default;

            bool hit(const Math::Ray3D &ray, double tmin, double tmax, hits &hit) const override;

            void setinfo(const Math::Vector3D &origin, double angle, std::shared_ptr<IMaterial> material);
        private:
            Math::Vector3D _origin;
            double _tan; ///< The tangent of the angle
            double _sqtan; ///< The square of the tangent of the angle
            std::shared_ptr<IMaterial> _material;

            Math::Vector3D __getNormalAt(const Math::Point3D &point) const noexcept;

    };
}
