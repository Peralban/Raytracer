/*
** EPITECH PROJECT, 2024
** CFGGenerator.hpp
** File description:
** DESCRIPTION
*/

/**
 * @file CFGGenerator.hpp
 * @brief Contains the declarations of the classes used in the CFGGenerator.
 */

#pragma once

#include <iostream>
#include <vector>
#include <filesystem>

#define ALL_INDEXES 3
#define RESO_INDEX 2

namespace Bonus {
    /**
     * @enum ARRAY_TYPES
     * @brief Enum for the different types of arrays.
     */
    enum ARRAY_TYPES {
        C, // COLOR
        A, // AXIS
        RE  // RESOLUTION
    };

    /**
     * @enum COLORS
     * @brief Enum for the different colors.
     */
    enum COLORS {
        R,
        G,
        B
    };

    /**
     * @enum POSITIONS
     * @brief Enum for the different positions.
     */
    enum POSITIONS {
        X,
        Y,
        Z
    };

    /**
     * @enum RESOLUTION
     * @brief Enum for the different resolutions.
     */
    enum RESOLUTION {
        WIDTH,
        HEIGHT
    };

    /**
     * @class ParsingMaterial
     * @brief Class for parsing material.
     */
    class ParsingMaterial {
    public:
        /**
         * @brief Constructor for ParsingMaterial.
         * @param type The type of the material.
         * @param r The red color value.
         * @param g The green color value.
         * @param b The blue color value.
         */
        ParsingMaterial(std::string type, int r, int g, int b)
                : _type(type), _r(r), _g(g), _b(b) {}

        ParsingMaterial(std::string type, float fuzz, int r, int g, int b)
                : _type(type), _fuzz(fuzz), _r(r), _g(g), _b(b) {}

        ParsingMaterial(std::string type, float albedo_r, float albedo_g, float albedo_b, float ref_idx)
                : _type(type), _albedo_r(albedo_r), _albedo_g(albedo_g), _albedo_b(albedo_b), _ref_idx(ref_idx) {}

        std::string getType() { return _type; }

        /**
         * @brief Getter for the red color value.
         * @return The red color value.
         */
        int getR() { return _r; }

        /**
         * @brief Getter for the green color value.
         * @return The green color value.
         */
        int getG() { return _g; }

        /**
         * @brief Getter for the blue color value.
         * @return The blue color value.
         */
        int getB() { return _b; }

        float getFuzz() { return _fuzz; }

        float getAlbedoR() { return _albedo_r; }

        float getAlbedoG() { return _albedo_g; }

        float getAlbedoB() { return _albedo_b; }

        float getRefIdx() { return _ref_idx; }

    private:
        std::string _type;
        float _fuzz;
        int _r;
        int _g;
        int _b;
        float _albedo_r;
        float _albedo_g;
        float _albedo_b;
        float _ref_idx;
    };

    /**
     * @class ParsingTransformation
     * @brief Class for parsing transformations.
     */
    class ParsingTransformation {
    public:
        /**
         * @brief Constructor for ParsingTransformation.
         * @param type The type of the transformation.
         * @param position_x The x position of the transformation.
         * @param position_y The y position of the transformation.
         * @param position_z The z position of the transformation.
         */
        ParsingTransformation(std::string type, int position_x, int position_y, int position_z)
                : _type(type), _position_x(position_x), _position_y(position_y), _position_z(position_z) {}

        /**
         * @brief Getter for the type.
         * @return The type of the transformation.
         */
        std::string getType() { return _type; }

        /**
         * @brief Getter for the x position.
         * @return The x position of the transformation.
         */
        int getPositionX() { return _position_x; }

        /**
         * @brief Getter for the y position.
         * @return The y position of the transformation.
         */
        int getPositionY() { return _position_y; }

        /**
         * @brief Getter for the z position.
         * @return The z position of the transformation.
         */
        int getPositionZ() { return _position_z; }

    private:
        std::string _type; ///< The type of the transformation.
        int _position_x; ///< The x position of the transformation.
        int _position_y; ///< The y position of the transformation.
        int _position_z; ///< The z position of the transformation.
    };

    /**
     * @class ParsingShape
     * @brief Class for parsing shapes.
     */
    class ParsingShape {
    public:
        /**
         * @brief Constructor for ParsingShape.
         * @param type The type of the shape.
         * @param position_x The x position of the shape.
         * @param position_y The y position of the shape.
         * @param position_z The z position of the shape.
         * @param size_x The x size of the shape.
         * @param size_y The y size of the shape.
         * @param size_z The z size of the shape.
         * @param path The path of the shape.
         * @param material The material of the shape.
         * @param transformations The transformations of the shape.
         */
        ParsingShape(std::string type, int position_x, int position_y, int position_z,
                int size_x, int size_y, int size_z, std::string path, ParsingMaterial material, std::vector<ParsingTransformation> transformations)
                : _type(type), _position_x(position_x), _position_y(position_y), _position_z(position_z),
                  _size_x(size_x), _size_y(size_y), _size_z(size_z), _path(path), _material(material), _transformations(transformations) {}

        /**
         * @brief Getter for the type.
         * @return The type of the shape.
         */
        std::string getType() { return _type; }

        /**
         * @brief Getter for the x position.
         * @return The x position of the shape.
         */
        int getPositionX() { return _position_x; }

        /**
         * @brief Getter for the y position.
         * @return The y position of the shape.
         */
        int getPositionY() { return _position_y; }

        /**
         * @brief Getter for the z position.
         * @return The z position of the shape.
         */
        int getPositionZ() { return _position_z; }

        /**
         * @brief Getter for the x size.
         * @return The x size of the shape.
         */
        int getSizeX() { return _size_x; }

        /**
         * @brief Getter for the y size.
         * @return The y size of the shape.
         */
        int getSizeY() { return _size_y; }

        /**
         * @brief Getter for the z size.
         * @return The z size of the shape.
         */
        int getSizeZ() { return _size_z; }

        /**
         * @brief Getter for the path.
         * @return The path of the shape.
         */
        std::string getPath() { return _path; }

        /**
         * @brief Getter for the material.
         * @return The material of the shape.
         */
        ParsingMaterial getMaterial() { return _material; }

        /**
         * @brief Getter for the transformations.
         * @return The transformations of the shape.
         */
        std::vector<ParsingTransformation> getTransformations() { return _transformations; }

    private:
        std::string _type; ///< The type of the shape.
        int _position_x; ///< The x position of the shape.
        int _position_y; ///< The y position of the shape.
        int _position_z; ///< The z position of the shape.
        int _size_x; ///< The x size of the shape.
        int _size_y; ///< The y size of the shape.
        int _size_z; ///< The z size of the shape.
        std::string _path; ///< The path of the shape.
        ParsingMaterial _material; ///< The material of the shape.
        std::vector<ParsingTransformation> _transformations; ///< The transformations of the shape.
    };
} // namespace Bonus
