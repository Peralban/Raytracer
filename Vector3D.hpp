/*
** EPITECH PROJECT, 2024
** B-OOP-400-NAN-4-1-bsraytracer-florent.charpentier
** File description:
** Vector3D
*/

#pragma  once

#include <ostream>
#include "Point3D.hpp"

namespace Math {
    class Point3D;

    /**
     * @class Vector3D
     * @brief Represents a vector in 3D space.
     *
     * The Vector3D class is used to represent a vector in 3D space, defined by x, y, and z coordinates.
     */
    class Vector3D {
        public:
            /**
             * @brief Default constructor for the Vector3D class.
             *
             * Initializes a new instance of the Vector3D class with default x, y, and z coordinates.
             */
            Vector3D();

            /**
             * @brief Constructor for the Vector3D class.
             *
             * Initializes a new instance of the Vector3D class with specified x, y, and z coordinates.
             *
             * @param x The x-coordinate of the vector.
             * @param y The y-coordinate of the vector.
             * @param z The z-coordinate of the vector.
             */
            Vector3D(double x, double y, double z);

            /**
             * @brief Default destructor for the Vector3D class.
             */
            ~Vector3D() = default;

            // ... (other methods with their respective documentation)

            double x; ///< The x-coordinate of the vector.
            double y; ///< The y-coordinate of the vector.
            double z; ///< The z-coordinate of the vector.

            /**
             * @brief Outputs the vector to a given output stream.
             *
             * @param os The output stream to output the vector to.
             */
            virtual void output(std::ostream &os) const noexcept;

        protected:
        private:
    };

    /**
     * @brief Reflects a vector off a surface normal.
     *
     * This function is not a member of the class.
     *
     * @param v The vector to reflect.
     * @param n The surface normal to reflect the vector off.
     * @return The reflected vector.
     */
    Vector3D reflect(const Vector3D &v, const Vector3D &n);
}

/**
 * @brief Outputs a Vector3D to a given output stream.
 *
 * @param os The output stream to output the Vector3D to.
 * @param f The Vector3D to output.
 * @return The output stream.
 */
std::ostream &operator<<(std::ostream &os, const Math::Vector3D &f);
