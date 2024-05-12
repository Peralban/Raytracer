/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** SolidColor
*/

#include "Interfaces/ITextures.hpp"

namespace RayTracer {
    class SolidColor : public ITextures {
    public:

        /**
         * @brief Default constructor for the SolidColor class.
         *
         * Initializes a new instance of the SolidColor class with default color.
         */
        SolidColor() = default;

        /**
         * @brief Constructor for the SolidColor class.
         *
         * Initializes a new instance of the SolidColor class with a given color.
         *
         * @param color The color of the texture.
         */
        SolidColor(const Math::Vector3D &color);

        /**
         * @brief Default destructor for the SolidColor class.
         */
        ~SolidColor() = default;

        /**
         * @brief Determines the color of the texture at a given point.
         *
         * This method calculates the color of the texture at a given point.
         *
         * @param u The u coordinate of the texture.
         * @param v The v coordinate of the texture.
         * @param p The point at which the texture is calculated.
         * @return The color of the texture at the given point.
         */
        Math::Vector3D get(double u, double v, const Math::Vector3D &p) const override;

    private:
        Math::Vector3D _color; ///< The color of the texture.
    };
}