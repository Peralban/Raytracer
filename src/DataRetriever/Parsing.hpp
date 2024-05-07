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

namespace App {
    class ParsingMaterial {
    public:
        ParsingMaterial(std::string type, Math::Vector3D color)
            : _type(type), _color(color) {}

        std::string getType() { return _type; }

        Math::Vector3D getColor() { return _color; }

        void output(std::ostream &os) const noexcept;

    private:
        std::string _type;
        Math::Vector3D _color;
    };

    class ParsingTransformation {
    public:
        ParsingTransformation(std::string type, Math::Vector3D position)
            : _type(type), _position(position) {}

        std::string getType() { return _type; }

        Math::Vector3D getPosition() { return _position; }

        void output(std::ostream &os) const noexcept;

    private:
        std::string _type;
        Math::Vector3D _position;
    };

    class ParsingShape {
    public:
        ParsingShape(std::string type, Math::Vector3D position, Math::Vector3D size, std::string path,
                     ParsingMaterial material, std::vector<ParsingTransformation> transformations)
                : _type(type), _position(position), _size(size), _path(path),
                _material(material), _transformations(transformations) {}

        std::vector<ParsingTransformation> getTransformations() { return _transformations; }

        ParsingMaterial getMaterial() { return _material; }

        std::string getType() { return _type; }

        Math::Vector3D getPosition() { return _position; }

        Math::Vector3D getSize() { return _size; }

        std::string getPath() { return _path; }

        void output(std::ostream &os) const noexcept;

    private:
        std::string _type;
        Math::Vector3D _position;
        Math::Vector3D _size;
        std::string _path;
        ParsingMaterial _material;
        std::vector<ParsingTransformation> _transformations;
    };

    class ParsingLight {
    public:
        ParsingLight(Math::Vector3D position, Math::Vector3D color, float intensity,
        Math::Vector3D direction, std::string type)
            : _position(position), _color(color), _intensity(intensity), _direction(direction),
            _type(type) {}

        Math::Vector3D getPosition() { return _position; }

        Math::Vector3D getColor() { return _color; }

        float getIntensity() { return _intensity; }

        Math::Vector3D getDirection() { return _direction; }

        std::string getType() { return _type; }

        void output(std::ostream &os) const noexcept;

    private:
        Math::Vector3D _position;
        Math::Vector3D _color;
        float _intensity;
        Math::Vector3D _direction;
        std::string _type;
    };

    class ParsingCamera {
    public:
        ParsingCamera() = default;
        ParsingCamera(Math::Vector3D view_from, Math::Vector3D view_at, Math::Vector3D view_up, Math::Vector3D rotation,
        float fov, float aperture, float focus_dist, int resolutionWidth, int resolutionHeight)
            : _view_from(view_from), _view_at(view_at), _view_up(view_up), _rotation(rotation) ,_fov(fov), _aperture(aperture),
            _focus_dist(focus_dist), _resolution(resolutionWidth, resolutionHeight) {}

        Math::Vector3D getViewFrom() { return _view_from; }

        Math::Vector3D getViewAt() { return _view_at; }

        Math::Vector3D getViewUp() { return _view_up; }

        Math::Vector3D getRotation() { return _rotation; }

        float getFov() { return _fov; }

        float getAperture() { return _aperture; }

        float getFocusDist() { return _focus_dist; }

        std::pair<int, int> getResolution() { return _resolution; }

        void output(std::ostream &os) const noexcept;

    private:
        Math::Vector3D _view_from;
        Math::Vector3D _view_at;
        Math::Vector3D _view_up;
        Math::Vector3D _rotation;
        float _fov;
        float _aperture;
        float _focus_dist;
        std::pair<int, int> _resolution;
    };

    class ParsingBackground {
    public:
        ParsingBackground() = default;
        ParsingBackground(Math::Vector3D color, std::string path)
            : _color(color), _path(path) {}

        Math::Vector3D getColor() { return _color; }

        std::string getPath() { return _path; }

        void output(std::ostream &os) const noexcept;

    private:
        Math::Vector3D _color;
        std::string _path;
    };

    class ParsingPrecision {
    public:
        ParsingPrecision() = default;
        ParsingPrecision(int samples, int number_of_bounces, bool enable_shadows,
        bool enable_reflections, bool enable_refractions)
            : _samples(samples), _number_of_bounces(number_of_bounces), _enable_shadows(enable_shadows),
            _enable_reflections(enable_reflections), _enable_refractions(enable_refractions) {}

        int getSamples() { return _samples; }

        int getNumberOfBounces() { return _number_of_bounces; }

        bool getEnableShadows() { return _enable_shadows; }

        bool getEnableReflections() { return _enable_reflections; }

        bool getEnableRefractions() { return _enable_refractions; }

        void output(std::ostream &os) const noexcept;

    private:
        int _samples;
        int _number_of_bounces;
        bool _enable_shadows;
        bool _enable_reflections;
        bool _enable_refractions;
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

        std::vector<ParsingShape> getShapes() { return _shapes; }

        std::vector<ParsingLight> getLights() { return _lights; }

        std::vector<std::string> getObjFiles() { return _obj_files; }

        ParsingCamera getCamera() { return _camera; }

        void parseConfigFile();

        void parseShapes(const libconfig::Setting &shapes);

        void parseMaterials(const libconfig::Setting &materials);

        void parseLights(const libconfig::Setting &lights);

        void parseCamera(const libconfig::Setting &camera);

        void parseBackground(const libconfig::Setting &background);

        void parseObjFiles(const libconfig::Setting &obj_files);

        void parsePrecision(const libconfig::Setting &precision);

        void output(std::ostream &os) const noexcept;

    private:
        /**
         * @brief The path to the configuration file.
         */
        std::string _configFile;
        std::vector<ParsingShape> _shapes;
        std::vector<ParsingLight> _lights;
        std::vector<std::string> _obj_files;
        ParsingCamera _camera;
        ParsingBackground _background;
        ParsingPrecision _precision;
    };
}

std::ostream &operator<<(std::ostream &os, const App::ParsingTransformation &transformation);
std::ostream &operator<<(std::ostream &os, const App::ParsingShape &shape);
std::ostream &operator<<(std::ostream &os, const App::ParsingLight &light);
std::ostream &operator<<(std::ostream &os, const App::ParsingCamera &camera);
std::ostream &operator<<(std::ostream &os, const App::ParsingBackground &background);
std::ostream &operator<<(std::ostream &os, const App::ParsingPrecision &precision);
std::ostream &operator<<(std::ostream &os, const App::Parsing &parsing);
