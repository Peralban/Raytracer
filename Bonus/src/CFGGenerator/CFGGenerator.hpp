/*
** EPITECH PROJECT, 2024
** CFGGenerator.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include <iostream>
#include <vector>
#include <filesystem>

#define ALL_INDEXES 3
#define RESO_INDEX 2

namespace Bonus {
    enum ARRAY_TYPES {
        C, // COLOR
        A, // AXIS
        RE  // RESOLUTION
    };
    enum COLORS {
        R,
        G,
        B
    };
    enum POSITIONS {
        X,
        Y,
        Z
    };
    enum RESOLUTION {
        WIDTH,
        HEIGHT
    };
    class ParsingMaterial {
    public:
        ParsingMaterial(std::string type, int r, int g, int b)
                : _type(type), _r(r), _g(g), _b(b) {}

        std::string getType() { return _type; }

        int getR() { return _r; }

        int getG() { return _g; }

        int getB() { return _b; }

    private:
        std::string _type;
        int _r;
        int _g;
        int _b;
    };

    class ParsingTransformation {
    public:
        ParsingTransformation(std::string type, int position_x, int position_y, int position_z)
                : _type(type), _position_x(position_x), _position_y(position_y), _position_z(position_z) {}

        std::string getType() { return _type; }

        int getPositionX() { return _position_x; }

        int getPositionY() { return _position_y; }

        int getPositionZ() { return _position_z; }

    private:
        std::string _type;
        int _position_x;
        int _position_y;
        int _position_z;
    };

    class ParsingShape {
    public:
        ParsingShape(std::string type, int position_x, int position_y, int position_z,
                     int size_x, int size_y, int size_z, std::string path, ParsingMaterial material, std::vector<ParsingTransformation> transformations)
                : _type(type), _position_x(position_x), _position_y(position_y), _position_z(position_z),
                  _size_x(size_x), _size_y(size_y), _size_z(size_z), _path(path), _material(material), _transformations(transformations) {}

        std::string getType() { return _type; }

        int getPositionX() { return _position_x; }

        int getPositionY() { return _position_y; }

        int getPositionZ() { return _position_z; }

        int getSizeX() { return _size_x; }

        int getSizeY() { return _size_y; }

        int getSizeZ() { return _size_z; }

        std::string getPath() { return _path; }

        ParsingMaterial getMaterial() { return _material; }

        std::vector<ParsingTransformation> getTransformations() { return _transformations; }

    private:
        std::string _type;
        int _position_x;
        int _position_y;
        int _position_z;
        int _size_x;
        int _size_y;
        int _size_z;
        std::string _path;
        ParsingMaterial _material;
        std::vector<ParsingTransformation> _transformations;
    };

    class ParsingLight {
    public:
        ParsingLight(int position_x, int position_y, int position_z, int color_r, int color_g, int color_b,
                     float intensity, int rotation_x, int rotation_y, int rotation_z, std::string type)
                : _position_x(position_x), _position_y(position_y), _position_z(position_z),
                  _color_r(color_r), _color_g(color_g), _color_b(color_b), _intensity(intensity),
                  _rotation_x(rotation_x), _rotation_y(rotation_y), _rotation_z(rotation_z), _type(type) {}

        int getPositionX() { return _position_x; }

        int getPositionY() { return _position_y; }

        int getPositionZ() { return _position_z; }

        int getColorR() { return _color_r; }

        int getColorG() { return _color_g; }

        int getColorB() { return _color_b; }

        float getIntensity() { return _intensity; }

        int getRotationX() { return _rotation_x; }

        int getRotationY() { return _rotation_y; }

        int getRotationZ() { return _rotation_z; }

        std::string getType() { return _type; }

    private:
        int _position_x;
        int _position_y;
        int _position_z;
        int _color_r;
        int _color_g;
        int _color_b;
        float _intensity;
        int _rotation_x;
        int _rotation_y;
        int _rotation_z;
        std::string _type;
    };

    class ParsingCamera {
    public:
        ParsingCamera() = default;
        ParsingCamera(int view_from_x, int view_from_y, int view_from_z, int view_at_x,
                      int view_at_y, int view_at_z, int view_up_x, int view_up_y, int view_up_z, int rotation_x,
                      int rotation_y, int rotation_z, float fov, float aperture, float focus_dist, int resolution_width,
                      int resolution_height)
                : _view_from_x(view_from_x), _view_from_y(view_from_y), _view_from_z(view_from_z),
                  _view_at_x(view_at_x), _view_at_y(view_at_y), _view_at_z(view_at_z),
                  _view_up_x(view_up_x), _view_up_y(view_up_y), _view_up_z(view_up_z),
                  _rotation_x(rotation_x), _rotation_y(rotation_y), _rotation_z(rotation_z),
                  _fov(fov), _aperture(aperture), _focus_dist(focus_dist),
                  _resolution_width(resolution_width), _resolution_height(resolution_height) {}

        int getViewFromX() { return _view_from_x; }

        int getViewFromY() { return _view_from_y; }

        int getViewFromZ() { return _view_from_z; }

        int getViewAtX() { return _view_at_x; }

        int getViewAtY() { return _view_at_y; }

        int getViewAtZ() { return _view_at_z; }

        int getViewUpX() { return _view_up_x; }

        int getViewUpY() { return _view_up_y; }

        int getViewUpZ() { return _view_up_z; }

        int getRotationX() { return _rotation_x; }

        int getRotationY() { return _rotation_y; }

        int getRotationZ() { return _rotation_z; }

        float getFov() { return _fov; }

        float getAperture() { return _aperture; }

        float getFocusDist() { return _focus_dist; }

        int getResolutionWidth() { return _resolution_width; }

        int getResolutionHeight() { return _resolution_height; }

    private:
        int _view_from_x;
        int _view_from_y;
        int _view_from_z;
        int _view_at_x;
        int _view_at_y;
        int _view_at_z;
        int _view_up_x;
        int _view_up_y;
        int _view_up_z;
        int _rotation_x;
        int _rotation_y;
        int _rotation_z;
        float _fov;
        float _aperture;
        float _focus_dist;
        int _resolution_width;
        int _resolution_height;
    };

    class ParsingBackground {
    public:
        ParsingBackground() = default;
        ParsingBackground(int r, int g, int b, std::string path)
                : _r(r), _g(g), _b(b), _path(path) {}

        int getColorR() { return _r; }

        int getColorG() { return _g; }

        int getColorB() { return _b; }

        std::string getTexturePath() { return _path; }

    private:
        int _r;
        int _g;
        int _b;
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

    private:
        int _samples;
        int _number_of_bounces;
        bool _enable_shadows;
        bool _enable_reflections;
        bool _enable_refractions;
    };

    class CFGGenerator {
    public:
        CFGGenerator() = default;

        ~CFGGenerator() = default;

        void GetInfo();

        void askShape();

        void askCamera();

        void askLight();

        void askBackground();

        void askPrecision();

        void askObjFiles();

        Bonus::ParsingTransformation askTransformation();

        std::vector<ParsingShape> getShapes() { return _shapes; }

        std::vector<ParsingLight> getLights() { return _lights; }

        ParsingCamera getCamera() { return _camera; }

        ParsingBackground getBackground() { return _background; }

        ParsingPrecision getPrecision() { return _precision; }

        std::string getOutputFile() { return _output_file; }

        std::vector<std::string> getObjPaths() { return _obj_files; }

    private:
        std::vector<ParsingShape> _shapes;
        std::vector<ParsingLight> _lights;
        std::vector<std::string> _obj_files;
        ParsingCamera _camera;
        ParsingBackground _background;
        ParsingPrecision _precision;
        std::string _output_file;
    };
}
