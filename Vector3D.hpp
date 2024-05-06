/*
** EPITECH PROJECT, 2024
** B-OOP-400-NAN-4-1-bsraytracer-florent.charpentier
** File description:
** Vector3D
*/

#ifndef VECTOR3D_HPP_
    #define VECTOR3D_HPP_

    #include <ostream>
    #include "Point3D.hpp"

namespace Math {
    class Point3D;
    class Vector3D {
        public:
            Vector3D();
            static Vector3D fromPoint(const Point3D &p);
            Vector3D(double x, double y, double z);
            ~Vector3D() = default;

            double sqLength() const noexcept;
            double length() const noexcept;

            Vector3D operator+(const Vector3D &other) const noexcept;
            Vector3D &operator+=(const Vector3D &other) noexcept;

            Vector3D operator-(const Vector3D &other) const noexcept;
            Vector3D &operator-=(const Vector3D &other) noexcept;

            Vector3D operator*(const Vector3D &other) const noexcept;
            Vector3D &operator*=(const Vector3D &other) noexcept;

            Vector3D operator/(const Vector3D &other) const noexcept;
            Vector3D &operator/=(const Vector3D &other) noexcept;


            Vector3D operator*(double scale) const noexcept;
            Vector3D &operator*=(double scale) noexcept;

            Vector3D operator/(double invScale) const;
            Vector3D &operator/=(double invScale);

            Vector3D operator-() const noexcept;

            double dot(const Vector3D &other) const noexcept;
            double square() const noexcept;

            double x;
            double y;
            double z;


            virtual void output(std::ostream &os) const noexcept;

        protected:
        private:
    };
}

std::ostream &operator<<(std::ostream &os, const Math::Vector3D &f);

#endif /* !VECTOR3D_HPP_ */
