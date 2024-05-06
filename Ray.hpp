/*
** EPITECH PROJECT, 2024
** B-OOP-400-NAN-4-1-bsraytracer-florent.charpentier
** File description:
** Ray
*/

#ifndef RAY_HPP_
    #define RAY_HPP_

    #include "Vector3D.hpp"
    #include "Point3D.hpp"
    #include "ITransformation.hpp"

namespace RayTracer {
    class ITransformation;
    class Ray {
        public:
            Ray();
            Ray(const Math::Point3D &orig, const Math::Vector3D &dir);
            ~Ray() = default;

            Math::Point3D orig;
            Math::Vector3D dir;

            Ray &transform(const ITransformation &tr);
            std::optional<Ray &> &untransform(const ITransformation &tr);

            Ray transformed(const ITransformation &tr) const;
            std::optional<Ray> untransformed(const ITransformation &tr) const;

        protected:
        private:
    };
}
#endif /* !RAY_HPP_ */
