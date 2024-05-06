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
    class Vector3D {
        public:
            Vector3D();
            //static Vector3D fromPoint(const Point3D &p);
            /**
             * @brief Constructor for the Vector3D class.
             *
             * Initializes a new instance of the Vector3D class with specified x, y, and z components.
             *
             * @param x The x-component of the vector.
             * @param y The y-component of the vector.
             * @param z The z-component of the vector.
             */
            Vector3D(double r, double g, double b);

            /**
             * @brief Default destructor for the Vector3D class.
             */
            ~Vector3D() = default;

            /**
             * @brief Calculates the square of the length of the vector.
             *
             * This method calculates the square of the length (magnitude) of the vector, which can be useful for performance optimizations as it avoids the need for a square root operation.
             *
             * @return The square of the length of the vector.
             */
            double sqLength() const noexcept;

            /**
             * @brief Calculates the length of the vector.
             *
             * This method calculates the length (magnitude) of the vector.
             *
             * @return The length of the vector.
             */
            double length() const noexcept;
            /**
             * @brief Overloads the addition operator for the Vector3D class.
             *
             * This method adds the x, y, and z components of the current vector and the other vector.
             *
             * @param other The other vector to add.
             * @return A new vector that is the result of the addition.
             */
            Vector3D operator+(const Vector3D &other) const noexcept;
            /**
             * @brief Overloads the addition assignment operator for the Vector3D class.
             *
             * This method adds the x, y, and z components of the other vector to the current vector.
             *
             * @param other The other vector to add.
             * @return The current vector after the addition.
             */
            Vector3D &operator+=(const Vector3D &other) noexcept;

            /**
             * @brief Overloads the subtraction operator for the Vector3D class.
             *
             * This method subtracts the x, y, and z components of the other vector from the current vector.
             *
             * @param other The other vector to subtract.
             * @return A new vector that is the result of the subtraction.
             */
            Vector3D operator-(const Vector3D &other) const noexcept;

            /**
             * @brief Overloads the subtraction assignment operator for the Vector3D class.
             *
             * This method subtracts the x, y, and z components of the other vector from the current vector.
             *
             * @param other The other vector to subtract.
             * @return The current vector after the subtraction.
             */
            Vector3D &operator-=(const Vector3D &other) noexcept;

            /**
             * @brief Overloads the multiplication operator for the Vector3D class.
             *
             * This method multiplies the x, y, and z components of the current vector and the other vector.
             *
             * @param other The other vector to multiply.
             * @return A new vector that is the result of the multiplication.
             */
            Vector3D operator*(const Vector3D &other) const noexcept;

            /**
             * @brief Overloads the multiplication assignment operator for the Vector3D class.
             *
             * This method multiplies the x, y, and z components of the other vector with the current vector.
             *
             * @param other The other vector to multiply.
             * @return The current vector after the multiplication.
             */
            Vector3D &operator*=(const Vector3D &other) noexcept;

            /**
             * @brief Overloads the division operator for the Vector3D class.
             *
             * This method divides the x, y, and z components of the current vector by the other vector.
             *
             * @param other The other vector to divide by.
             * @return A new vector that is the result of the division.
             */
            Vector3D operator/(const Vector3D &other) const noexcept;

            /**
             * @brief Overloads the division assignment operator for the Vector3D class.
             *
             * This method divides the x, y, and z components of the current vector by the other vector.
             *
             * @param other The other vector to divide by.
             * @return The current vector after the division.
             */
            Vector3D &operator/=(const Vector3D &other) noexcept;


            /**
             * @brief Overloads the multiplication operator for the Vector3D class.
             *
             * This method multiplies the x, y, and z components of the current vector by a scalar value.
             *
             * @param scale The scalar value to multiply the vector by.
             * @return A new vector that is the result of the multiplication.
             */
            Vector3D operator*(double scale) const noexcept;

            /**
             * @brief Overloads the multiplication assignment operator for the Vector3D class.
             *
             * This method multiplies the x, y, and z components of the current vector by a scalar value.
             *
             * @param scale The scalar value to multiply the vector by.
             * @return The current vector after the multiplication.
             */
            Vector3D &operator*=(double scale) noexcept;

            /**
             * @brief Overloads the division operator for the Vector3D class.
             *
             * This method divides the x, y, and z components of the current vector by a scalar value.
             *
             * @param invScale The scalar value to divide the vector by.
             * @return A new vector that is the result of the division.
             */
            Vector3D operator/(double invScale) const;

            /**
             * @brief Overloads the division assignment operator for the Vector3D class.
             *
             * This method divides the x, y, and z components of the current vector by a scalar value.
             *
             * @param invScale The scalar value to divide the vector by.
             * @return The current vector after the division.
             */
            Vector3D &operator/=(double invScale);

            /**
             * @brief Overloads the unary minus operator for the Vector3D class.
             *
             * This method negates the x, y, and z components of the current vector.
             *
             * @return A new vector that is the result of the negation.
             */
            Vector3D operator-() const noexcept;

            /**
             * @brief Calculates the dot product of the current vector and another vector.
             *
             * This method calculates the dot product of the current vector and another vector.
             *
             * @param other The other vector to calculate the dot product with.
             * @return The dot product of the two vectors.
             */
            double dot(const Vector3D &other) const noexcept;

            /**
             * @brief Calculates the square of the length of the vector.
             *
             * This method calculates the square of the length (magnitude) of the vector, which can be useful for performance optimizations as it avoids the need for a square root operation.
             *
             * @return The square of the length of the vector.
             */
            double square() const noexcept;

            /**
             * @brief Normalizes the current vector.
             *
             * This method normalizes the current vector, making it a unit vector.
             */
            void makeUnitVector();

            /**
             * @brief Returns a unit vector in the same direction as the current vector.
             *
             * This method returns a unit vector in the same direction as the current vector.
             *
             * @return A unit vector in the same direction as the current vector.
             */
            Vector3D getUnitVector() const noexcept;

            /**
             * @brief Outputs the vector to a given output stream.
             *
             * This is a virtual function that can be overridden by derived classes to customize the output format.
             *
             * @param not used
             */
            Vector3D getUnitVector();

            /**
             * @brief Outputs the vector to a given output stream.
             *
             * This is a virtual function that can be overridden by derived classes to customize the output format.
             *
             * @param other the vector to cross with
             */
            Vector3D cross(const Vector3D &other) const noexcept;

            double x; ///< The x-coordinate of the vector.
            double y; ///< The y-coordinate of the vector.
            double z; ///< The z-coordinate of the vector.

        /**
         * @brief Outputs the vector to a given output stream.
         *
         * This is a virtual function that can be overridden by derived classes to customize the output format.
         *
         * @param os The output stream to output the vector to.
         */
        virtual void output(std::ostream &os) const noexcept;

        protected:
        private:
    };
    /**
     * @brief Reflects a vector off a surface with a given normal.
     *
     * This function calculates the reflection of a vector v off a surface with a normal vector n.
     * The function is not a member of the Vector3D class.
     *
     * @param v The vector to reflect.
     * @param n The normal vector of the surface off which to reflect the vector.
     * @return The reflected vector.
     */
    Vector3D reflect(const Vector3D &v, const Vector3D &n);

    /**
     *  @brief Refracts a vector through a surface with a given normal.
     *
     *  This function calculates the refraction of a vector uv through a surface with a normal vector n.
     *  The function is not a member of the Vector3D class.
     *
     * @param uv incidence ray direction
     * @param n normal surface vector
     * @param niOverNt  the ratio of the refractive indices of the two media
     * @param refracted the refracted ray direction
     * @return true if the refraction is possible, false otherwise
     */
    bool refract(const Vector3D &uv, const Vector3D &n, double niOverNt, Vector3D &refracted);
}

/**
 * @brief Overloads the stream insertion operator for the Vector3D class.
 *
 * This function inserts a string representation of the Vector3D object into the output stream.
 *
 * @param os The output stream where the string representation of the Vector3D object will be inserted.
 * @param f The Vector3D object to be inserted into the output stream.
 * @return The output stream with the string representation of the Vector3D object inserted.
 */
std::ostream &operator<<(std::ostream &os, const Math::Vector3D &f);
