/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Glass material
*/


#pragma once

#include "Interfaces/IMaterial.hpp"
#include "Interfaces/ITextures.hpp"
#include <cmath>

namespace RayTracer {
    /**
     * @class Glass
     * @brief Represents a glass material in the 3D space.
     *
     * The Glass class is a type of material that has a refractive property. It extends the IMaterial interface.
     */
    class Glass : public IMaterial {

    public:

        /**
         * @brief Constructor for the Glass class.
         *
         * Initializes a new instance of the Glass class with a given refractive index.
         *
         * @param refractionIndex The refractive index of the material.
         */
        Glass(float refractionIndex, std::shared_ptr<ITextures> albedo);

        /**
         * @brief Default destructor for the Glass class.
         */
        ~Glass() = default;

        /**
         * @brief Determines the reflectance of the material.
         *
         * This method calculates the reflectance of the material using the Schlick's approximation.
         *
         * @param cosine The cosine of the angle between the ray and the normal.
         * @param refractionIndex The refractive index of the material.
         * @return The reflectance of the material.
         */
        float schlick(double cosine, float refractionIndex) const;

        /**
         * @brief Determines how a ray interacts with the glass material.
         *
         * This method is called when a ray hits a shape with this material. It calculates the scattered ray and the attenuation.
         *
         * @param ray The incoming ray.
         * @param hit The hit record containing details about the hit.
         * @param attenuation The attenuation of the ray's color due to the material.
         * @param scattered The scattered ray.
         * @return A boolean indicating whether the ray was scattered.
         */
        bool scatter(const Math::Ray3D &ray, const hits &hit, Math::Vector3D &attenuation,
                     Math::Ray3D &scattered) const override;

        /**
         * @brief Determines the emitted light of the material.
         *
         * This method calculates the emitted light of the material.
         *
         * @return The emitted light of the material.
         *
         * @note This method is not used for glass materials.
         *      It is only implemented to satisfy the IMaterial interface.
         *      It always returns a black color.
         */
        Math::Vector3D emitted([[maybe_unused]]double uPos, [[maybe_unused]]double vPos, [[maybe_unused]]const Math::Vector3D &point) const override {return {0, 0, 0};}

        private:
        float _refractionIndex; ///< The refractive index of the material. It is a value that determines how much light is bent when it enters the material.
        std::shared_ptr<ITextures> _albedo; ///< The albedo of the material.
    };
}
