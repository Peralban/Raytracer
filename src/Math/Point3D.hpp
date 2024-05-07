/*
** EPITECH PROJECT, 2024
** B-OOP-400-NAN-4-1-bsraytracer-florent.charpentier
** File description:
** Point3D
*/

#ifndef POINT3D_HPP_
    #define POINT3D_HPP_

    #include "Vector3D.hpp"
    #include <ostream>

namespace Math {
    class Vector3D;
    class Point3D {
        public:
            Point3D();
            Point3D(double x, double y, double z);
            Point3D(const Vector3D &v);
            ~Point3D() = default;

            double x;
            double y;
            double z;

            Point3D operator+(const Vector3D &v) const noexcept;
            Point3D operator-(const Vector3D &v) const noexcept;
            Point3D &operator+=(const Vector3D &v) noexcept;
            Point3D &operator-=(const Vector3D &v) noexcept;

            Vector3D operator+(const Point3D &other) const noexcept;
            Vector3D operator-(const Point3D &other) const noexcept;


            std::ostream &output(std::ostream &os) const noexcept;

            static const Point3D zero;
            static const Point3D one;

        protected:
        private:
    };
}

std::ostream &operator<<(std::ostream &os, const Math::Point3D &p);

#endif /* !POINT3D_HPP_ */
