/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Metal material
*/

#pragma once
#include "Interfaces/IMaterial.hpp"
#include "Interfaces/ITextures.hpp"

namespace RayTracer {
    /**
     * @class Metal
     * @brief Represents a metal material in the 3D space.
     *
     * The Metal class is a type of material that has a reflective property. It extends the IMaterial interface.
     */
    class Metal : public IMaterial {
    public:

         /**
         * @brief Constructor for the Metal class.
         *
         * Initializes a new instance of the Metal class with a given albedo and fuzziness.
         *
         * @param a The albedo of the material.
         * @param f The fuzziness of the material.
         */
        Metal(std::shared_ptr<ITextures> albedo, float f);

         /**
         * @brief Default destructor for the Metal class.
         */
        ~Metal() = default;

         /**
         * @brief Determines how a ray interacts with the metal material.
         *
         * This method is called when a ray hits a shape with this material.
         * It calculates the scattered ray and the attenuation.
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
        std::shared_ptr<ITextures> _albedo; ///< The albedo of the material.
        float _fuzziness; ///< The fuzziness of the material. It is a value between 0 and 1, 0 being a perfect mirror and 1 being a diffuse surface.
    };
}
