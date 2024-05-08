/*
** EPITECH PROJECT, 2024
** Parsing.hpp
** File description:
** DESCRIPTION
*/

/**
 * @file Parsing.hpp
 * @brief Defines the Parsing class and its nested exception classes.
 */

#pragma once

#include "Interfaces/IError.hpp"
#include "Math/Vector3D.hpp"
#include <libconfig.h++>
#include <vector>
#include <utility>

/**
 * @namespace App
 * @brief Main namespace for the application.
 */
namespace App {
    /**
     * @class ParsingMaterial
     * @brief Class representing a material in the parsing process.
     */
    class ParsingMaterial {
    public:
        /**
         * @brief Constructor for ParsingMaterial.
         * @param type The type of the material.
         * @param color The color of the material as a Vector3D.
         */
        ParsingMaterial(std::string type, Math::Vector3D color)
                : _type(type), _color(color) {}

        /**
         * @brief Getter for the type of the material.
         * @return The type of the material.
         */
        std::string getType() { return _type; }

        /**
         * @brief Getter for the color of the material.
         * @return The color of the material as a Vector3D.
         */
        Math::Vector3D getColor() { return _color; }

        /**
         * @brief Outputs the material data to the provided ostream.
         * @param os The ostream to output to.
         */
        void output(std::ostream &os) const

        noexcept;

    private:
        std::string _type; ///< The type of the material.
        Math::Vector3D _color; ///< The color of the material.
    };

    /**
     * @class ParsingTransformation
     * @brief Class representing a transformation in the parsing process.
     */
    class ParsingTransformation {
    public:
        /**
         * @brief Constructor for ParsingTransformation.
         * @param type The type of the transformation.
         * @param position The position of the transformation as a Vector3D.
         */
        ParsingTransformation(std::string type, Math::Vector3D position)
                : _type(type), _position(position) {}

        /**
         * @brief Getter for the type of the transformation.
         * @return The type of the transformation.
         */
        std::string getType() { return _type; }

        /**
         * @brief Getter for the position of the transformation.
         * @return The position of the transformation as a Vector3D.
         */
        Math::Vector3D getPosition() { return _position; }

        /**
         * @brief Outputs the transformation data to the provided ostream.
         * @param os The ostream to output to.
         */
        void output(std::ostream &os) const

        noexcept;

    private:
        std::string _type; ///< The type of the transformation.
        Math::Vector3D _position; ///< The position of the transformation.
    };

    /**
     * @class ParsingShape
     * @brief Class representing a shape in the parsing process.
     */
    class ParsingShape {
    public:
        /**
         * @brief Constructor for ParsingShape.
         * @param type The type of the shape.
         * @param position The position of the shape as a Vector3D.
         * @param size The size of the shape as a Vector3D.
         * @param path The path to the shape file.
         * @param material The material of the shape as a ParsingMaterial.
         * @param transformations The transformations of the shape as a vector of ParsingTransformation.
         */
        ParsingShape(std::string type, Math::Vector3D position, Math::Vector3D size, std::string path,
                     ParsingMaterial material, std::vector <ParsingTransformation> transformations)
                : _type(type), _position(position), _size(size), _path(path),
                  _material(material), _transformations(transformations) {}

        /**
         * @brief Getter for the transformations of the shape.
         * @return The transformations of the shape as a vector of ParsingTransformation.
         */
        std::vector <ParsingTransformation> getTransformations() { return _transformations; }

        /**
         * @brief Getter for the material of the shape.
         * @return The material of the shape as a ParsingMaterial.
         */
        ParsingMaterial getMaterial() { return _material; }

        /**
         * @brief Getter for the type of the shape.
         * @return The type of the shape.
         */
        std::string getType() { return _type; }

        /**
         * @brief Getter for the position of the shape.
         * @return The position of the shape as a Vector3D.
         */
        Math::Vector3D getPosition() { return _position; }

        /**
         * @brief Getter for the size of the shape.
         * @return The size of the shape as a Vector3D.
         */
        Math::Vector3D getSize() { return _size; }

        /**
         * @brief Getter for the path to the shape file.
         * @return The path to the shape file.
         */
        std::string getPath() { return _path; }

        /**
         * @brief Outputs the shape data to the provided ostream.
         * @param os The ostream to output to.
         */
        void output(std::ostream &os) const

        noexcept;

    private:
        std::string _type; ///< The type of the shape.
        Math::Vector3D _position; ///< The position of the shape.
        Math::Vector3D _size; ///< The size of the shape.
        std::string _path; ///< The path to the shape file.
        ParsingMaterial _material; ///< The material of the shape.
        std::vector <ParsingTransformation> _transformations; ///< The transformations of the shape.
    };

    /**
     * @class ParsingLight
     * @brief Class representing a light in the parsing process.
     */
    class ParsingLight {
    public:
        /**
         * @brief Constructor for ParsingLight.
         * @param position The position of the light as a Vector3D.
         * @param color The color of the light as a Vector3D.
         * @param intensity The intensity of the light.
         * @param direction The direction of the light as a Vector3D.
         * @param type The type of the light.
         */
        ParsingLight(Math::Vector3D position, Math::Vector3D color, float intensity,
                     Math::Vector3D direction, std::string type)
                : _position(position), _color(color), _intensity(intensity), _direction(direction),
                  _type(type) {}

        /**
         * @brief Getter for the position of the light.
         * @return The position of the light as a Vector3D.
         */
        Math::Vector3D getPosition() { return _position; }

        /**
         * @brief Getter for the color of the light.
         * @return The color of the light as a Vector3D.
         */
        Math::Vector3D getColor() { return _color; }

        /**
         * @brief Getter for the intensity of the light.
         * @return The intensity of the light.
         */
        float getIntensity() { return _intensity; }

        /**
         * @brief Getter for the direction of the light.
         * @return The direction of the light as a Vector3D.
         */
        Math::Vector3D getDirection() { return _direction; }

        /**
         * @brief Getter for the type of the light.
         * @return The type of the light.
         */
        std::string getType() { return _type; }

        /**
         * @brief Outputs the light data to the provided ostream.
         * @param os The ostream to output to.
         */
        void output(std::ostream &os) const

        noexcept;

    private:
        Math::Vector3D _position; ///< The position of the light.
        Math::Vector3D _color; ///< The color of the light.
        float _intensity; ///< The intensity of the light.
        Math::Vector3D _direction; ///< The direction of the light.
        std::string _type; ///< The type of the light.
    };

    /**
     * @class ParsingCamera
     * @brief Class representing a camera in the parsing process.
     */
    class ParsingCamera {
    public:
        /**
         * @brief Default constructor for ParsingCamera.
         */
        ParsingCamera() = default;

        /**
         * @brief Constructor for ParsingCamera.
         * @param view_from The view from position of the camera as a Vector3D.
         * @param view_at The view at position of the camera as a Vector3D.
         * @param view_up The view up position of the camera as a Vector3D.
         * @param rotation The rotation of the camera as a Vector3D.
         * @param fov The field of view of the camera.
         * @param aperture The aperture of the camera.
         * @param focus_dist The focus distance of the camera.
         * @param resolutionWidth The width of the resolution of the camera.
         * @param resolutionHeight The height of the resolution of the camera.
         */
        ParsingCamera(Math::Vector3D view_from, Math::Vector3D view_at, Math::Vector3D view_up, Math::Vector3D rotation,
                      float fov, float aperture, float focus_dist, int resolutionWidth, int resolutionHeight)
                : _view_from(view_from), _view_at(view_at), _view_up(view_up), _rotation(rotation), _fov(fov),
                  _aperture(aperture),
                  _focus_dist(focus_dist), _resolution(resolutionWidth, resolutionHeight) {}

        /**
         * @brief Getter for the view from position of the camera.
         * @return The view from position of the camera as a Vector3D.
         */
        Math::Vector3D getViewFrom() { return _view_from; }

        /**
         * @brief Getter for the view at position of the camera.
         * @return The view at position of the camera as a Vector3D.
         */
        Math::Vector3D getViewAt() { return _view_at; }

        /**
         * @brief Getter for the view up position of the camera.
         * @return The view up position of the camera as a Vector3D.
         */
        Math::Vector3D getViewUp() { return _view_up; }

        /**
         * @brief Getter for the rotation of the camera.
         * @return The rotation of the camera as a Vector3D.
         */
        Math::Vector3D getRotation() { return _rotation; }

        /**
         * @brief Getter for the field of view of the camera.
         * @return The field of view of the camera.
         */
        float getFov() { return _fov; }

        /**
         * @brief Getter for the aperture of the camera.
         * @return The aperture of the camera.
         */
        float getAperture() { return _aperture; }

        /**
         * @brief Getter for the focus distance of the camera.
         * @return The focus distance of the camera.
         */
        float getFocusDist() { return _focus_dist; }

        /**
         * @brief Getter for the resolution of the camera.
         * @return The resolution of the camera as a pair of integers.
         */
        std::pair<int, int> getResolution() { return _resolution; }

        /**
         * @brief Outputs the camera data to the provided ostream.
         * @param os The ostream to output to.
         */
        void output(std::ostream &os) const

        noexcept;

    private:
        Math::Vector3D _view_from; ///< The view from position of the camera.
        Math::Vector3D _view_at; ///< The view at position of the camera.
        Math::Vector3D _view_up; ///< The view up position of the camera.
        Math::Vector3D _rotation; ///< The rotation of the camera.
        float _fov; ///< The field of view of the camera.
        float _aperture; ///< The aperture of the camera.
        float _focus_dist; ///< The focus distance of the camera.
        std::pair<int, int> _resolution; ///< The resolution of the camera.
    };

    /**
     * @class ParsingBackground
     * @brief Class representing a background in the parsing process.
     */
    class ParsingBackground {
    public:
        /**
         * @brief Default constructor for ParsingBackground.
         */
        ParsingBackground() = default;

        /**
         * @brief Constructor for ParsingBackground.
         * @param color The color of the background as a Vector3D.
         * @param path The path to the background file.
         */
        ParsingBackground(Math::Vector3D color, std::string path)
                : _color(color), _path(path) {}

        /**
         * @brief Getter for the color of the background.
         * @return The color of the background as a Vector3D.
         */
        Math::Vector3D getColor() { return _color; }

        /**
         * @brief Getter for the path to the background file.
         * @return The path to the background file.
         */
        std::string getPath() { return _path; }

        /**
         * @brief Outputs the background data to the provided ostream.
         * @param os The ostream to output to.
         */
        void output(std::ostream &os) const

        noexcept;

    private:
        Math::Vector3D _color; ///< The color of the background.
        std::string _path; ///< The path to the background file.
    };

    /**
     * @class ParsingPrecision
     * @brief Class representing the precision settings in the parsing process.
     */
    class ParsingPrecision {
    public:
        /**
         * @brief Default constructor for ParsingPrecision.
         */
        ParsingPrecision() = default;

        /**
         * @brief Constructor for ParsingPrecision.
         * @param samples The number of samples for the precision.
         * @param number_of_bounces The number of bounces for the precision.
         * @param enable_shadows Boolean to enable or disable shadows.
         * @param enable_reflections Boolean to enable or disable reflections.
         * @param enable_refractions Boolean to enable or disable refractions.
         */
        ParsingPrecision(int samples, int number_of_bounces, bool enable_shadows,
                         bool enable_reflections, bool enable_refractions)
                : _samples(samples), _number_of_bounces(number_of_bounces), _enable_shadows(enable_shadows),
                  _enable_reflections(enable_reflections), _enable_refractions(enable_refractions) {}

        /**
         * @brief Getter for the number of samples.
         * @return The number of samples.
         */
        int getSamples() { return _samples; }

        /**
         * @brief Getter for the number of bounces.
         * @return The number of bounces.
         */
        int getNumberOfBounces() { return _number_of_bounces; }

        /**
         * @brief Getter for the shadows setting.
         * @return Boolean indicating if shadows are enabled.
         */
        bool getEnableShadows() { return _enable_shadows; }

        /**
         * @brief Getter for the reflections setting.
         * @return Boolean indicating if reflections are enabled.
         */
        bool getEnableReflections() { return _enable_reflections; }

        /**
         * @brief Getter for the refractions setting.
         * @return Boolean indicating if refractions are enabled.
         */
        bool getEnableRefractions() { return _enable_refractions; }

        /**
         * @brief Outputs the precision settings data to the provided ostream.
         * @param os The ostream to output to.
         */
        void output(std::ostream &os) const

        noexcept;

    private:
        int _samples; ///< The number of samples for the precision.
        int _number_of_bounces; ///< The number of bounces for the precision.
        bool _enable_shadows; ///< Boolean to enable or disable shadows.
        bool _enable_reflections; ///< Boolean to enable or disable reflections.
        bool _enable_refractions; ///< Boolean to enable or disable refractions.
    };

    /**
     * @class Parsing
     * @brief A class for parsing command line arguments.
     *
     * This class provides functionality for checking the validity of command line arguments.
     * It also defines several nested exception classes for handling specific types of parsing errors.
     */
    class Parsing {
    public:
        /**
         * @class TooManyArguments
         * @brief Exception class for handling too many arguments error.
         *
         * This class is used to throw and handle exceptions when too many command line arguments are provided.
         */
        class ErrorTooManyArguments : public AError {
        public:
            /**
             * @brief Display an error message.
             * @param message The error message to display. Defaults to "Too many arguments".
             */
            ErrorTooManyArguments() : AError("Too many arguments") {}
        };

        /**
         * @class TooFewArguments
         * @brief Exception class for handling too few arguments error.
         *
         * This class is used to throw and handle exceptions when too few command line arguments are provided.
         */
        class ErrorTooFewArguments : public AError {
        public:
            /**
             * @brief Display an error message.
             * @param message The error message to display. Defaults to "Too few arguments".
             */
            ErrorTooFewArguments() : AError("Too few arguments") {}
        };

        /**
         * @class InvalidArgument
         * @brief Exception class for handling invalid argument error.
         *
         * This class is used to throw and handle exceptions when an invalid command line argument is provided.
         */
        class ErrorCFGFile : public AError {
        public:
            /**
             * @brief Display an error message.
             * @param message The error message to display. Defaults to "Error in treatment of the configuration file".
             */
            ErrorCFGFile() : AError("Error in treatment of the configuration file") {}
        };

        class ErrorInvalidType : public AError {
        public:
            /**
             * @brief Display an error message.
             * @param message The error message to display. Defaults to "Invalid type of file".
             */
            ErrorInvalidType() : AError("Invalid type of file") {}
        };

        class ErrorNoCFGFile : public AError {
        public:
            /**
             * @brief Display an error message.
             * @param message The error message to display. Defaults to "Invalid type of file".
             */
            ErrorNoCFGFile() : AError("CFG file not found") {}
        };

        /**
         * @brief Default constructor for the Parsing class.
         */
        Parsing() = default;

        /**
         * @brief Default destructor for the Parsing class.
         */
        ~Parsing() = default;

        Parsing(int ac, char **av) { checkArguments(ac, av); }

        /**
         * @brief Check the validity of command line arguments. Throws an exception if the arguments are invalid.
         * or complete _configFile with the path to the configuration file.
         * @param ac The number of command line arguments.
         * @param av The array of command line arguments.
         * @throws TooManyArguments if too many arguments are provided. @see TooManyArguments
         * @throws TooFewArguments if too few arguments are provided. @see TooFewArguments
         * @throws InvalidArgument if an invalid argument is provided. @see InvalidArgument
         */
        void checkArguments(int ac, char **av);

        /**
         * @brief Get the path to the configuration file.
         * @return The path to the configuration file.
         */
        std::string getConfigFile() { return _configFile; }

        /**
        * @brief Get the shapes parsed from the configuration file.
        * @return A vector of ParsingShape objects.
        */
        std::vector <ParsingShape> getShapes() { return _shapes; }

        /**
         * @brief Get the lights parsed from the configuration file.
         * @return A vector of ParsingLight objects.
         */
        std::vector <ParsingLight> getLights() { return _lights; }

        /**
         * @brief Get the object files parsed from the configuration file.
         * @return A vector of strings representing the paths to the object files.
         */
        std::vector <std::string> getObjFiles() { return _obj_files; }

        /**
         * @brief Get the camera parsed from the configuration file.
         * @return A ParsingCamera object.
         */
        ParsingCamera getCamera() { return _camera; }

        /**
         * @brief Get the precision parsed from the configuration file.
         * @return A ParsingCamera object.
         */
        ParsingPrecision getPrecision() { return _precision; }

        /**
         * @brief Get the background from the configuration file.
         * @return A ParsingCamera object.
         */
        ParsingPrecision getBackground() { return _background; }

        /**
         * @brief Parse the configuration file.
         * This function should be called after the configuration file path has been set.
         */
        void parseConfigFile();

        /**
         * @brief Parse the shapes from the configuration file.
         * @param shapes A libconfig::Setting representing the shapes in the configuration file.
         */
        void parseShapes(const libconfig::Setting &shapes);

        /**
         * @brief Parse the materials from the configuration file.
         * @param materials A libconfig::Setting representing the materials in the configuration file.
         */
        void parseMaterials(const libconfig::Setting &materials);

        /**
         * @brief Parse the lights from the configuration file.
         * @param lights A libconfig::Setting representing the lights in the configuration file.
         */
        void parseLights(const libconfig::Setting &lights);

        /**
         * @brief Parse the camera from the configuration file.
         * @param camera A libconfig::Setting representing the camera in the configuration file.
         */
        void parseCamera(const libconfig::Setting &camera);

        /**
         * @brief Parse the background from the configuration file.
         * @param background A libconfig::Setting representing the background in the configuration file.
         */
        void parseBackground(const libconfig::Setting &background);

        /**
         * @brief Parse the object files from the configuration file.
         * @param obj_files A libconfig::Setting representing the object files in the configuration file.
         */
        void parseObjFiles(const libconfig::Setting &obj_files);

        /**
         * @brief Parse the precision settings from the configuration file.
         * @param precision A libconfig::Setting representing the precision settings in the configuration file.
         */
        void parsePrecision(const libconfig::Setting &precision);

        /**
         * @brief Output the parsed data to the provided ostream.
         * @param os The ostream to output to.
         */
        void output(std::ostream &os) const

        noexcept;

    private:
        std::string _configFile; ///< The path to the configuration file.
        std::vector <ParsingShape> _shapes; ///< The shapes parsed from the configuration file.
        std::vector <ParsingLight> _lights; ///< The lights parsed from the configuration file.
        std::vector <std::string> _obj_files; ///< The object files parsed from the configuration file.
        ParsingCamera _camera; ///< The camera parsed from the configuration file.
        ParsingBackground _background; ///< The background parsed from the configuration file.
        ParsingPrecision _precision; ///< The precision settings parsed from the configuration file.
    };
}
// Overloaded output operators for various classes
std::ostream &operator<<(std::ostream &os, const App::ParsingTransformation &transformation);
std::ostream &operator<<(std::ostream &os, const App::ParsingShape &shape);
std::ostream &operator<<(std::ostream &os, const App::ParsingLight &light);
std::ostream &operator<<(std::ostream &os, const App::ParsingCamera &camera);
std::ostream &operator<<(std::ostream &os, const App::ParsingBackground &background);
std::ostream &operator<<(std::ostream &os, const App::ParsingPrecision &precision);
std::ostream &operator<<(std::ostream &os, const App::Parsing &parsing);
