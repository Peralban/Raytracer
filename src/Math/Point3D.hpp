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

/**
 * @namespace Math
 * @brief Namespace for the math library.
 */
namespace Math {
    class Vector3D; // Forward declaration of Vector3D class

    /**
     * @class Point3D
     * @brief A class to represent a point in 3D space.
     *
     * This class represents a point in 3D space with x, y, and z coordinates.
     */
    class Point3D {
        public:
            /**
             * @brief Default constructor. Initializes the point at the origin.
             */
            Point3D();

            /**
             * @brief Constructor that initializes the point at the given coordinates.
             * @param x The x-coordinate of the point.
             * @param y The y-coordinate of the point.
             * @param z The z-coordinate of the point.
             */
            Point3D(double x, double y, double z);

            /**
             * @brief Constructor that initializes the point from a Vector3D.
             * @param v The Vector3D to initialize the point from.
             */
            Point3D(const Vector3D &v);

            /**
             * @brief Default destructor.
             */
            ~Point3D() = default;

            double x; ///< The x-coordinate of the point.
            double y; ///< The y-coordinate of the point.
            double z; ///< The z-coordinate of the point.

            /**
             * @brief Addition operator to add a Vector3D to this point.
             * @param v The Vector3D to add.
             * @return The resulting Point3D after addition.
             */
            Point3D operator+(const Vector3D &v) const noexcept;

            /**
             * @brief Subtraction operator to subtract a Vector3D from this point.
             * @param v The Vector3D to subtract.
             * @return The resulting Point3D after subtraction.
             */
            Point3D operator-(const Vector3D &v) const noexcept;

            /**
             * @brief Addition assignment operator to add a Vector3D to this point.
             * @param v The Vector3D to add.
             * @return A reference to this point after addition.
             */
            Point3D &operator+=(const Vector3D &v) noexcept;

            /**
             * @brief Subtraction assignment operator to subtract a Vector3D from this point.
             * @param v The Vector3D to subtract.
             * @return A reference to this point after subtraction.
             */
            Point3D &operator-=(const Vector3D &v) noexcept;

            /**
             * @brief Addition operator to add another Point3D to this point.
             * @param other The other Point3D to add.
             * @return The resulting Vector3D after addition.
             */
            Vector3D operator+(const Point3D &other) const noexcept;

            /**
             * @brief Subtraction operator to subtract another Point3D from this point.
             * @param other The other Point3D to subtract.
             * @return The resulting Vector3D after subtraction.
             */
            Vector3D operator-(const Point3D &other) const noexcept;

            /**
             * @brief Function to output the point to an output stream.
             * @param os The output stream to output to.
             * @return The output stream after outputting the point.
             */
            std::ostream &output(std::ostream &os) const noexcept;

            static const Point3D zero; ///< A Point3D at the origin.
            static const Point3D one;  ///< A Point3D at coordinates (1, 1, 1).

        protected:
        private:
    };
}

/**
 * @brief Overloaded stream insertion operator to output a Point3D to an output stream.
 * @param os The output stream to output to.
 * @param p The Point3D to output.
 * @return The output stream after outputting the Point3D.
 */
std::ostream &operator<<(std::ostream &os, const Math::Point3D &p);

#endif /* !POINT3D_HPP_ */
