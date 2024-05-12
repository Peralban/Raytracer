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

/**
 * @namespace Bonus
 * @brief Namespace for the bonus. Contains the classes for the CFGGenerator.
 */
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
     *
     * This class is used to parse the material properties from the input.
     * It stores the type of the material, its color, fuzziness, albedo, and refractive index.
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

        ParsingMaterial(std::string type, double intensity, int r, int g, int b)
                : _type(type), _intensity(intensity), _r(r), _g(g), _b(b) {}

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

        /**
         * @brief Getter for the green component of the albedo.
         * @return The green component of the albedo.
         */
        float getAlbedoG() { return _albedo_g; }

        /**
         * @brief Getter for the blue component of the albedo.
         * @return The blue component of the albedo.
         */
        float getAlbedoB() { return _albedo_b; }

        /**
         * @brief Getter for the refractive index of the material.
         * @return The refractive index of the material.
         */
        float getRefIdx() { return _ref_idx; }

        /**
         * @brief Getter for the intensity of the material.
         * @return The intensity of the material.
         */
        double getIntensity() { return _intensity; }

    private:
        std::string _type; ///< The type of the material.
        float _fuzz; ///< The fuzziness of the material.
        double _intensity; ///< The intensity of the material.
        int _r; ///< The red component of the material color.
        int _g; ///< The green component of the material color.
        int _b; ///< The blue component of the material color.
        float _albedo_r; ///< The red component of the albedo.
        float _albedo_g; ///< The green component of the albedo.
        float _albedo_b; ///< The blue component of the albedo.
        float _ref_idx; ///< The refractive index of the material.
    };

    /**
     * @class ParsingTransformation
     * @brief Class for parsing transformation data.
     *
     * This class is used to parse the transformation properties from the input.
     * It stores the type of the transformation and its position coordinates.
     */
    class ParsingTransformation {
    public:
        /**
         * @brief Parameterized constructor.
         *
         * Initializes a new instance of the ParsingTransformation class with the given type and position coordinates.
         *
         * @param type The type of the transformation.
         * @param position_x The x-coordinate of the transformation position.
         * @param position_y The y-coordinate of the transformation position.
         * @param position_z The z-coordinate of the transformation position.
         */
        ParsingTransformation(std::string type, float position_x, float position_y, float position_z)
                : _type(type), _position_x(position_x), _position_y(position_y), _position_z(position_z) {}

        /**
         * @brief Getter for the type.
         *
         * This function returns the type of the transformation.
         *
         * @return The type of the transformation.
         */
        std::string getType() { return _type; }

        /**
         * @brief Getter for the x-coordinate of the transformation position.
         *
         * This function returns the x-coordinate of the transformation position.
         *
         * @return The x-coordinate of the transformation position.
         */
        float getPositionX() { return _position_x; }

        /**
         * @brief Getter for the y-coordinate of the transformation position.
         *
         * This function returns the y-coordinate of the transformation position.
         *
         * @return The y-coordinate of the transformation position.
         */
        float getPositionY() { return _position_y; }

        /**
         * @brief Getter for the z-coordinate of the transformation position.
         *
         * This function returns the z-coordinate of the transformation position.
         *
         * @return The z-coordinate of the transformation position.
         */
        float getPositionZ() { return _position_z; }

    private:
        std::string _type; ///< The type of the transformation.
        float _position_x; ///< The x-coordinate of the transformation position.
        float _position_y; ///< The y-coordinate of the transformation position.
        float _position_z; ///< The z-coordinate of the transformation position.
    };

    /**
     * @class ParsingShape
     * @brief Class for parsing shapes.
     *
     * This class is used to parse the shape properties from the input.
     * It stores the type of the shape, its position, size, radius, normal, angle, height, maximum and minimum radius, size, path, material, and transformations.
     */
    class ParsingShape {
    public:
        /**
         * @brief Parameterized constructor.
         *
         * Initializes a new instance of the ParsingShape class with the given type, position, size, radius, normal, angle, height, maximum and minimum radius, size, path, material, and transformations.
         *
         * @param type The type of the shape.
         * @param position_x The x-coordinate of the shape position.
         * @param position_y The y-coordinate of the shape position.
         * @param position_z The z-coordinate of the shape position.
         * @param size_x The x-coordinate of the shape size.
         * @param size_y The y-coordinate of the shape size.
         * @param size_z The z-coordinate of the shape size.
         * @param radius The radius of the shape.
         * @param normal_x The x-coordinate of the shape normal.
         * @param normal_y The y-coordinate of the shape normal.
         * @param normal_z The z-coordinate of the shape normal.
         * @param angle The angle of the shape.
         * @param height The height of the shape.
         * @param max_radius The maximum radius of the shape.
         * @param min_radius The minimum radius of the shape.
         * @param size The size of the shape.
         * @param path The path of the shape.
         * @param material The material of the shape.
         * @param transformations The transformations of the shape.
         */
        ParsingShape(std::string type, float position_x, float position_y, float position_z, float size_x, float size_y, float size_z, float radius,
                     float normal_x, float normal_y, float normal_z, float angle, float height, float max_radius, float min_radius,
                     float size, std::string path, ParsingMaterial material, std::vector<ParsingTransformation> transformations) :
                _type(type), _position_x(position_x), _position_y(position_y), _position_z(position_z),
                _size_x(size_x), _size_y(size_y), _size_z(size_z), _radius(radius),
                _normal_x(normal_x), _normal_y(normal_y), _normal_z(normal_z), _angle(angle),
                _height(height), _max_radius(max_radius), _min_radius(min_radius), _size(size),
                _path(path), _material(material), _transformations(transformations) {}

        /**
         * @brief Getter for the type.
         * @return The type of the shape.
         */
        std::string getType() { return _type; }

        /**
         * @brief Getter for the x-coordinate of the shape position.
         * @return The x-coordinate of the shape position.
         */
        float getPositionX() { return _position_x; }

        /**
         * @brief Getter for the y-coordinate of the shape position.
         * @return The y-coordinate of the shape position.
         */
        float getPositionY() { return _position_y; }

        /**
         * @brief Getter for the z-coordinate of the shape position.
         * @return The z-coordinate of the shape position.
         */
        float getPositionZ() { return _position_z; }

        /**
         * @brief Getter for the x-coordinate of the shape size.
         * @return The x-coordinate of the shape size.
         */
        float getSizeX() { return _size_x; }

        /**
         * @brief Getter for the y-coordinate of the shape size.
         * @return The y-coordinate of the shape size.
         */
        float getSizeY() { return _size_y; }

        /**
         * @brief Getter for the z-coordinate of the shape size.
         * @return The z-coordinate of the shape size.
         */
        float getSizeZ() { return _size_z; }

        /**
         * @brief Getter for the radius of the shape.
         * @return The radius of the shape.
         */
        float getRadius() { return _radius; }

        /**
         * @brief Getter for the x-coordinate of the shape normal.
         * @return The x-coordinate of the shape normal.
         */
        float getNormalX() { return _normal_x; }

        /**
         * @brief Getter for the y-coordinate of the shape normal.
         * @return The y-coordinate of the shape normal.
         */
        float getNormalY() { return _normal_y; }

        /**
         * @brief Getter for the z-coordinate of the shape normal.
         * @return The z-coordinate of the shape normal.
         */
        float getNormalZ() { return _normal_z; }

        /**
         * @brief Getter for the angle of the shape.
         * @return The angle of the shape.
         */
        float getAngle() { return _angle; }

        /**
         * @brief Getter for the height of the shape.
         * @return The height of the shape.
         */
        float getHeight() { return _height; }

        /**
         * @brief Getter for the maximum radius of the shape.
         * @return The maximum radius of the shape.
         */
        float getMaxRadius() { return _max_radius; }

        /**
         * @brief Getter for the minimum radius of the shape.
         * @return The minimum radius of the shape.
         */
        float getMinRadius() { return _min_radius; }

        /**
         * @brief Getter for the size of the shape.
         * @return The size of the shape.
         */
        float getSize() { return _size; }

        /**
         * @brief Getter for the path of the shape.
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
        float _position_x; ///< The x-coordinate of the shape position.
        float _position_y; ///< The y-coordinate of the shape position.
        float _position_z; ///< The z-coordinate of the shape position.
        float _size_x; ///< The x-coordinate of the shape size.
        float _size_y; ///< The y-coordinate of the shape size.
        float _size_z; ///< The z-coordinate of the shape size.
        float _radius; ///< The radius of the shape.
        float _normal_x; ///< The x-coordinate of the shape normal.
        float _normal_y; ///< The y-coordinate of the shape normal.
        float _normal_z; ///< The z-coordinate of the shape normal.
        float _angle; ///< The angle of the shape.
        float _height; ///< The height of the shape.
        float _max_radius; ///< The maximum radius of the shape.
        float _min_radius; ///< The minimum radius of the shape.
        float _size; ///< The size of the shape.
        std::string _path; ///< The path of the shape.
        ParsingMaterial _material; ///< The material of the shape.
        std::vector<ParsingTransformation> _transformations; ///< The transformations of the shape.
    };

    /**
 * @class ParsingLight
 * @brief Class for parsing light data.
 *
 * This class is used to parse the light properties from the input.
 * It stores the position, color, intensity, rotation, and type of the light.
 */
    class ParsingLight {
    public:
        /**
         * @brief Parameterized constructor.
         *
         * Initializes a new instance of the ParsingLight class with the given position, color, intensity, rotation, and type.
         *
         * @param position_x The x-coordinate of the light position.
         * @param position_y The y-coordinate of the light position.
         * @param position_z The z-coordinate of the light position.
         * @param color_r The red component of the light color.
         * @param color_g The green component of the light color.
         * @param color_b The blue component of the light color.
         * @param intensity The intensity of the light.
         * @param rotation_x The x-coordinate of the light rotation.
         * @param rotation_y The y-coordinate of the light rotation.
         * @param rotation_z The z-coordinate of the light rotation.
         * @param type The type of the light.
         */
        ParsingLight(float position_x, float position_y, float position_z, int color_r, int color_g, int color_b,
                     float intensity, float rotation_x, float rotation_y, float rotation_z, std::string type)
                : _position_x(position_x), _position_y(position_y), _position_z(position_z),
                  _color_r(color_r), _color_g(color_g), _color_b(color_b), _intensity(intensity),
                  _rotation_x(rotation_x), _rotation_y(rotation_y), _rotation_z(rotation_z), _type(type) {}

        float getPositionX() { return _position_x; } ///< Getter for the x-coordinate of the light position.
        float getPositionY() { return _position_y; } ///< Getter for the y-coordinate of the light position.
        float getPositionZ() { return _position_z; } ///< Getter for the z-coordinate of the light position.
        int getColorR() { return _color_r; } ///< Getter for the red component of the light color.
        int getColorG() { return _color_g; } ///< Getter for the green component of the light color.
        int getColorB() { return _color_b; } ///< Getter for the blue component of the light color.
        float getIntensity() { return _intensity; } ///< Getter for the intensity of the light.
        float getRotationX() { return _rotation_x; } ///< Getter for the x-coordinate of the light rotation.
        float getRotationY() { return _rotation_y; } ///< Getter for the y-coordinate of the light rotation.
        float getRotationZ() { return _rotation_z; } ///< Getter for the z-coordinate of the light rotation.
        std::string getType() { return _type; } ///< Getter for the type of the light.

    private:
        float _position_x; ///< The x-coordinate of the light position.
        float _position_y; ///< The y-coordinate of the light position.
        float _position_z; ///< The z-coordinate of the light position.
        int _color_r; ///< The red component of the light color.
        int _color_g; ///< The green component of the light color.
        int _color_b; ///< The blue component of the light color.
        float _intensity; ///< The intensity of the light.
        float _rotation_x; ///< The x-coordinate of the light rotation.
        float _rotation_y; ///< The y-coordinate of the light rotation.
        float _rotation_z; ///< The z-coordinate of the light rotation.
        std::string _type; ///< The type of the light.
    };

/**
 * @class ParsingCamera
 * @brief Class for parsing camera data.
 *
 * This class is used to parse the camera properties from the input.
 * It stores the view from, view at, view up, rotation, field of view, aperture, focus distance, and resolution of the camera.
 */
    class ParsingCamera {
    public:
        /**
         * @brief Default constructor.
         *
         * Initializes a new instance of the ParsingCamera class.
         */
        ParsingCamera() = default;

        /**
         * @brief Parameterized constructor.
         *
         * Initializes a new instance of the ParsingCamera class with the given view from, view at, view up, rotation, field of view, aperture, focus distance, and resolution.
         *
         * @param view_from_x The x-coordinate of the view from.
         * @param view_from_y The y-coordinate of the view from.
         * @param view_from_z The z-coordinate of the view from.
         * @param view_at_x The x-coordinate of the view at.
         * @param view_at_y The y-coordinate of the view at.
         * @param view_at_z The z-coordinate of the view at.
         * @param view_up_x The x-coordinate of the view up.
         * @param view_up_y The y-coordinate of the view up.
         * @param view_up_z The z-coordinate of the view up.
         * @param rotation_x The x-coordinate of the rotation.
         * @param rotation_y The y-coordinate of the rotation.
         * @param rotation_z The z-coordinate of the rotation.
         * @param fov The field of view.
         * @param aperture The aperture.
         * @param focus_dist The focus distance.
         * @param resolution_width The width of the resolution.
         * @param resolution_height The height of the resolution.
         */
        ParsingCamera(float view_from_x, float view_from_y, float view_from_z, float view_at_x,
                      float view_at_y, float view_at_z, float view_up_x, float view_up_y, float view_up_z, float rotation_x,
                      float rotation_y, float rotation_z, float fov, float aperture, float focus_dist, float resolution_width,
                      float resolution_height)
                : _view_from_x(view_from_x), _view_from_y(view_from_y), _view_from_z(view_from_z),
                  _view_at_x(view_at_x), _view_at_y(view_at_y), _view_at_z(view_at_z),
                  _view_up_x(view_up_x), _view_up_y(view_up_y), _view_up_z(view_up_z),
                  _rotation_x(rotation_x), _rotation_y(rotation_y), _rotation_z(rotation_z),
                  _fov(fov), _aperture(aperture), _focus_dist(focus_dist),
                  _resolution_width(resolution_width), _resolution_height(resolution_height) {}

        float getViewFromX() { return _view_from_x; } ///< Getter for the x-coordinate of the view from.
        float getViewFromY() { return _view_from_y; } ///< Getter for the y-coordinate of the view from.
        float getViewFromZ() { return _view_from_z; } ///< Getter for the z-coordinate of the view from.
        float getViewAtX() { return _view_at_x; } ///< Getter for the x-coordinate of the view at.
        float getViewAtY() { return _view_at_y; } ///< Getter for the y-coordinate of the view at.
        float getViewAtZ() { return _view_at_z; } ///< Getter for the z-coordinate of the view at.
        float getViewUpX() { return _view_up_x; } ///< Getter for the x-coordinate of the view up.
        float getViewUpY() { return _view_up_y; } ///< Getter for the y-coordinate of the view up.
        float getViewUpZ() { return _view_up_z; } ///< Getter for the z-coordinate of the view up.
        float getRotationX() { return _rotation_x; } ///< Getter for the x-coordinate of the rotation.
        float getRotationY() { return _rotation_y; } ///< Getter for the y-coordinate of the rotation.
        float getRotationZ() { return _rotation_z; } ///< Getter for the z-coordinate of the rotation.
        float getFov() { return _fov; } ///< Getter for the field of view.
        float getAperture() { return _aperture; } ///< Getter for the aperture.
        float getFocusDist() { return _focus_dist; } ///< Getter for the focus distance.
        int getResolutionWidth() { return _resolution_width; } ///< Getter for the width of the resolution.
        int getResolutionHeight() { return _resolution_height; } ///< Getter for the height of the resolution.

    private:
        float _view_from_x; ///< The x-coordinate of the view from.
        float _view_from_y; ///< The y-coordinate of the view from.
        float _view_from_z; ///< The z-coordinate of the view from.
        float _view_at_x; ///< The x-coordinate of the view at.
        float _view_at_y; ///< The y-coordinate of the view at.
        float _view_at_z; ///< The z-coordinate of the view at.
        float _view_up_x; ///< The x-coordinate of the view up.
        float _view_up_y; ///< The y-coordinate of the view up.
        float _view_up_z; ///< The z-coordinate of the view up.
        float _rotation_x; ///< The x-coordinate of the rotation.
        float _rotation_y; ///< The y-coordinate of the rotation.
        float _rotation_z; ///< The z-coordinate of the rotation.
        float _fov; ///< The field of view.
        float _aperture; ///< The aperture.
        float _focus_dist; ///< The focus distance.
        int _resolution_width; ///< The width of the resolution.
        int _resolution_height; ///< The height of the resolution.
    };

    /**
     * @class ParsingBackground
     * @brief Class for parsing background data.
     *
     * This class is used to parse the background properties from the input.
     * It stores the color and texture path of the background.
     */
    class ParsingBackground {
    public:
        /**
         * @brief Default constructor.
         *
         * Initializes a new instance of the ParsingBackground class.
         */
        ParsingBackground() = default;

        /**
         * @brief Parameterized constructor.
         *
         * Initializes a new instance of the ParsingBackground class with the given color and texture path.
         *
         * @param r The red component of the background color.
         * @param g The green component of the background color.
         * @param b The blue component of the background color.
         * @param path The texture path of the background.
         */
        ParsingBackground(int r, int g, int b, std::string path)
                : _r(r), _g(g), _b(b), _path(path) {}

        int getColorR() { return _r; } ///< Getter for the red component of the background color.
        int getColorG() { return _g; } ///< Getter for the green component of the background color.
        int getColorB() { return _b; } ///< Getter for the blue component of the background color.
        std::string getTexturePath() { return _path; } ///< Getter for the texture path of the background.

    private:
        int _r; ///< The red component of the background color.
        int _g; ///< The green component of the background color.
        int _b; ///< The blue component of the background color.
        std::string _path; ///< The texture path of the background.
    };

    /**
     * @class ParsingPrecision
     * @brief Class for parsing precision data.
     *
     * This class is used to parse the precision properties from the input.
     * It stores the number of samples, number of bounces, and flags for enabling shadows, reflections, and refractions.
     */
    class ParsingPrecision {
    public:
        /**
         * @brief Default constructor.
         *
         * Initializes a new instance of the ParsingPrecision class.
         */
        ParsingPrecision() = default;

        /**
         * @brief Parameterized constructor.
         *
         * Initializes a new instance of the ParsingPrecision class with the given number of samples, number of bounces, and flags for enabling shadows, reflections, and refractions.
         *
         * @param samples The number of samples.
         * @param number_of_bounces The number of bounces.
         * @param enable_shadows Flag for enabling shadows.
         * @param enable_reflections Flag for enabling reflections.
         * @param enable_refractions Flag for enabling refractions.
         */
        ParsingPrecision(int samples, int number_of_bounces, bool enable_shadows,
                         bool enable_reflections, bool enable_refractions)
                : _samples(samples), _number_of_bounces(number_of_bounces), _enable_shadows(enable_shadows),
                  _enable_reflections(enable_reflections), _enable_refractions(enable_refractions) {}

        int getSamples() { return _samples; } ///< Getter for the number of samples.

        int getNumberOfBounces() { return _number_of_bounces; } ///< Getter for the number of bounces.

        bool getEnableShadows() { return _enable_shadows; } ///< Getter for the flag for enabling shadows.

        bool getEnableReflections() { return _enable_reflections; } ///< Getter for the flag for enabling reflections.

        bool getEnableRefractions() { return _enable_refractions; } ///< Getter for the flag for enabling refractions.

    private:
        int _samples; ///< The number of samples.
        int _number_of_bounces; ///< The number of bounces.
        bool _enable_shadows; ///< Flag for enabling shadows.
        bool _enable_reflections; ///< Flag for enabling reflections.
        bool _enable_refractions; ///< Flag for enabling refractions.
    };

    /**
     * @class CFGGenerator
     * @brief Class for generating the configuration.
     *
     * This class is used to generate the configuration for the ray tracing application.
     * It stores the shapes, lights, camera, background, precision, output file, and obj files.
     */
    class CFGGenerator {
    public:
        /**
         * @brief Default constructor.
         *
         * Initializes a new instance of the CFGGenerator class.
         */
        CFGGenerator() = default;

        /**
         * @brief Default destructor.
         *
         * Destroys the instance of the CFGGenerator class.
         */
        ~CFGGenerator() = default;

        /**
         * @brief Method to get information.
         *
         * This method is used to get information from the user.
         */
        void GetInfo();

        /**
         * @brief Method to ask for shape information.
         *
         * This method is used to ask the user for shape information.
         */
        void askShape();

        /**
         * @brief Method to ask for camera information.
         *
         * This method is used to ask the user for camera information.
         */
        void askCamera();

        /**
         * @brief Method to ask for light information.
         *
         * This method is used to ask the user for light information.
         */
        void askLight();

        /**
         * @brief Method to ask for background information.
         *
         * This method is used to ask the user for background information.
         */
        void askBackground();

        /**
         * @brief Method to ask for precision information.
         *
         * This method is used to ask the user for precision information.
         */
        void askPrecision();

        /**
         * @brief Method to ask for obj files.
         *
         * This method is used to ask the user for obj files.
         */
        void askObjFiles();

        /**
         * @brief Method to ask for transformation information.
         *
         * This method is used to ask the user for transformation information.
         *
         * @return The transformation information.
         */
        Bonus::ParsingTransformation askTransformation();

        /**
         * @brief Getter for the shapes.
         * @return The shapes.
         */
        std::vector<ParsingShape> getShapes() { return _shapes; }

        /**
         * @brief Getter for the lights.
         * @return The lights.
         */
        std::vector<ParsingLight> getLights() { return _lights; }

        /**
         * @brief Getter for the camera.
         * @return The camera.
         */
        ParsingCamera getCamera() { return _camera; }

        /**
         * @brief Getter for the background.
         * @return The background.
         */
        ParsingBackground getBackground() { return _background; }

        /**
         * @brief Getter for the precision.
         * @return The precision.
         */
        ParsingPrecision getPrecision() { return _precision; }

        /**
         * @brief Getter for the output file.
         * @return The output file.
         */
        std::string getOutputFile() { return _output_file; }

        /**
         * @brief Getter for the obj paths.
         * @return The obj paths.
         */
        std::vector<std::string> getObjPaths() { return _obj_files; }

    private:
        std::vector<ParsingShape> _shapes; ///< The shapes.
        std::vector<ParsingLight> _lights; ///< The lights.
        std::vector<std::string> _obj_files; ///< The obj files.
        ParsingCamera _camera; ///< The camera.
        ParsingBackground _background; ///< The background.
        ParsingPrecision _precision; ///< The precision.
        std::string _output_file; ///< The output file.
    };
}
