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

        ParsingMaterial(std::string type, float fuzz, int r, int g, int b)
                : _type(type), _fuzz(fuzz), _r(r), _g(g), _b(b) {}

        ParsingMaterial(std::string type, float albedo_r, float albedo_g, float albedo_b, float ref_idx)
                : _type(type), _albedo_r(albedo_r), _albedo_g(albedo_g), _albedo_b(albedo_b), _ref_idx(ref_idx) {}

        std::string getType() { return _type; }

        int getR() { return _r; }

        int getG() { return _g; }

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

    class ParsingTransformation {
    public:
        ParsingTransformation(std::string type, float position_x, float position_y, float position_z)
                : _type(type), _position_x(position_x), _position_y(position_y), _position_z(position_z) {}

        std::string getType() { return _type; }

        float getPositionX() { return _position_x; }

        float getPositionY() { return _position_y; }

        float getPositionZ() { return _position_z; }

    private:
        std::string _type;
        float _position_x;
        float _position_y;
        float _position_z;
    };

    class ParsingShape {
    public:
        ParsingShape(std::string type, float position_x, float position_y, float position_z, float size_x, float size_y, float size_z, float radius,
                     float normal_x, float normal_y, float normal_z, float angle, float height, float max_radius, float min_radius,
                     float size, std::string path, ParsingMaterial material, std::vector<ParsingTransformation> transformations) :
                _type(type), _position_x(position_x), _position_y(position_y), _position_z(position_z),
                _size_x(size_x), _size_y(size_y), _size_z(size_z), _radius(radius),
                _normal_x(normal_x), _normal_y(normal_y), _normal_z(normal_z), _angle(angle),
                _height(height), _max_radius(max_radius), _min_radius(min_radius), _size(size),
                _path(path), _material(material), _transformations(transformations) {}

        std::string getType() { return _type; }

        float getPositionX() { return _position_x; }

        float getPositionY() { return _position_y; }

        float getPositionZ() { return _position_z; }

        float getSizeX() { return _size_x; }

        float getSizeY() { return _size_y; }

        float getSizeZ() { return _size_z; }

        float getRadius() { return _radius; }

        float getNormalX() { return _normal_x; }

        float getNormalY() { return _normal_y; }

        float getNormalZ() { return _normal_z; }

        float getAngle() { return _angle; }

        float getHeight() { return _height; }

        float getMaxRadius() { return _max_radius; }

        float getMinRadius() { return _min_radius; }

        float getSize() { return _size; }

        std::string getPath() { return _path; }

        ParsingMaterial getMaterial() { return _material; }

        std::vector<ParsingTransformation> getTransformations() { return _transformations; }

    private:
        std::string _type;
        float _position_x;
        float _position_y;
        float _position_z;
        float _size_x;
        float _size_y;
        float _size_z;
        float _radius;
        float _normal_x;
        float _normal_y;
        float _normal_z;
        float _angle;
        float _height;
        float _max_radius;
        float _min_radius;
        float _size;
        std::string _path;
        ParsingMaterial _material;
        std::vector<ParsingTransformation> _transformations;
    };

    class ParsingLight {
    public:
        ParsingLight(float position_x, float position_y, float position_z, int color_r, int color_g, int color_b,
                     float intensity, float rotation_x, float rotation_y, float rotation_z, std::string type)
                : _position_x(position_x), _position_y(position_y), _position_z(position_z),
                  _color_r(color_r), _color_g(color_g), _color_b(color_b), _intensity(intensity),
                  _rotation_x(rotation_x), _rotation_y(rotation_y), _rotation_z(rotation_z), _type(type) {}

        float getPositionX() { return _position_x; }

        float getPositionY() { return _position_y; }

        float getPositionZ() { return _position_z; }

        int getColorR() { return _color_r; }

        int getColorG() { return _color_g; }

        int getColorB() { return _color_b; }

        float getIntensity() { return _intensity; }

        float getRotationX() { return _rotation_x; }

        float getRotationY() { return _rotation_y; }

        float getRotationZ() { return _rotation_z; }

        std::string getType() { return _type; }

    private:
        float _position_x;
        float _position_y;
        float _position_z;
        int _color_r;
        int _color_g;
        int _color_b;
        float _intensity;
        float _rotation_x;
        float _rotation_y;
        float _rotation_z;
        std::string _type;
    };

    class ParsingCamera {
    public:
        ParsingCamera() = default;
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

        float getViewFromX() { return _view_from_x; }

        float getViewFromY() { return _view_from_y; }

        float getViewFromZ() { return _view_from_z; }

        float getViewAtX() { return _view_at_x; }

        float getViewAtY() { return _view_at_y; }

        float getViewAtZ() { return _view_at_z; }

        float getViewUpX() { return _view_up_x; }

        float getViewUpY() { return _view_up_y; }

        float getViewUpZ() { return _view_up_z; }

        float getRotationX() { return _rotation_x; }

        float getRotationY() { return _rotation_y; }

        float getRotationZ() { return _rotation_z; }

        float getFov() { return _fov; }

        float getAperture() { return _aperture; }

        float getFocusDist() { return _focus_dist; }

        int getResolutionWidth() { return _resolution_width; }

        int getResolutionHeight() { return _resolution_height; }

    private:
        float _view_from_x;
        float _view_from_y;
        float _view_from_z;
        float _view_at_x;
        float _view_at_y;
        float _view_at_z;
        float _view_up_x;
        float _view_up_y;
        float _view_up_z;
        float _rotation_x;
        float _rotation_y;
        float _rotation_z;
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
