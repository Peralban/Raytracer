/*
** EPITECH PROJECT, 2024
** ParsingManagement.cpp
** File description:
** DESCRIPTION
*/

/**
 * @file Parsing.cpp
 * @brief Parsing class implementation.
 * @see Parsing.hpp
 */

#include "Parsing.hpp"
#include <filesystem>

void App::Parsing::checkArguments(int ac, char **av)
{
    if (ac < 2)
        throw ErrorTooFewArguments();
    if (ac > 2)
        throw ErrorTooManyArguments();
    std::string file_path = av[1];
    if (file_path.find(".cfg") == std::string::npos)
        throw ErrorInvalidType();
    if (!std::filesystem::exists(file_path))
        throw ErrorNoCFGFile();
    libconfig::Config cfg;
    try {
        cfg.readFile(file_path.c_str());
        _configFile = file_path;
    } catch (const libconfig::FileIOException &fioex) {
        throw ErrorCFGFile();
    }
}

static Math::Vector3D createVector3D(const libconfig::Setting &setting)
{
    int a = setting[0];
    int b = setting[1];
    int c = setting[2];

    return Math::Vector3D(a, b, c);
}

static std::vector<App::ParsingTransformation> parseTransfo(const libconfig::Setting &transformations)
{
    std::vector<App::ParsingTransformation> transformations_vector;
    for (int j = 0; j < transformations.getLength(); j++) {
        const libconfig::Setting &transformation = transformations[j];
        std::string type = transformation["type"];
        Math::Vector3D pos = createVector3D(transformation["position"]);
        App::ParsingTransformation new_transformation(type, pos);
        transformations_vector.push_back(new_transformation);
    }
    return transformations_vector;
}

void App::Parsing::parseShapes(const libconfig::Setting &shapes)
{
    for (int i = 0; i < shapes.getLength(); i++) {
        const libconfig::Setting &shape = shapes[i];
        std::string type = shape["type"];
        Math::Vector3D pos = createVector3D(shape["position"]);
        Math::Vector3D size = createVector3D(shape["size"]);
        std::string texture_path = shape["texture_path"];
        const libconfig::Setting &materials = shape["materials"];
        std::string material_type = materials["type"];
        Math::Vector3D color = createVector3D(materials["color"]);
        ParsingShape new_shape(type, pos, size, texture_path,
        ParsingMaterial(material_type, color), parseTransfo(shape["transformations"]));
        _shapes.push_back(new_shape);
    }
}

void App::Parsing::parseLights(const libconfig::Setting &lights)
{
    for (int i = 0; i < lights.getLength(); i++) {
        const libconfig::Setting &light = lights[i];
        Math::Vector3D pos = createVector3D(light["position"]);
        Math::Vector3D color = createVector3D(light["color"]);
        float intensity = light["intensity"];
        Math::Vector3D direction = createVector3D(light["rotation"]);
        std::string type = light["type"];
        ParsingLight new_light(pos, color, intensity, direction, type);
        _lights.push_back(new_light);
    }

}

void App::Parsing::parseObjFiles(const libconfig::Setting &obj_files)
{
    for (int i = 0; i < obj_files.getLength(); i++) {
        const libconfig::Setting &obj_file = obj_files[i];
        std::string path = obj_file["path"];
        _obj_files.push_back(path);
    }
}

void App::Parsing::parseBackground(const libconfig::Setting &Background)
{
    Math::Vector3D color = createVector3D(Background["color"]);
    std::string texture_path = Background["texture_path"];
    _background = ParsingBackground(color, texture_path);
}

void App::Parsing::parsePrecision(const libconfig::Setting &precision)
{
    int samples = precision["samples"];
    int nb_bounces = precision["number_of_bounces"];
    bool enable_shadows = precision["enable_shadows"];
    bool enable_reflection = precision["enable_reflection"];
    bool enable_refraction = precision["enable_refraction"];
    _precision = ParsingPrecision(samples, nb_bounces, enable_shadows, enable_reflection, enable_refraction);
}

void App::Parsing::parseCamera(const libconfig::Setting &camera)
{
    Math::Vector3D view_from = createVector3D(camera["view_from"]);
    Math::Vector3D view_at = createVector3D(camera["view_at"]);
    Math::Vector3D view_up = createVector3D(camera["view_up"]);
    Math::Vector3D rotation = createVector3D(camera["rotation"]);
    float fov = camera["fov"];
    float aperture = camera["aperture"];
    float focus_dist = camera["focus_distance"];
    int resolutionWidth = camera["aspect_ratio"][0];
    int resolutionHeight = camera["aspect_ratio"][1];
    _camera = ParsingCamera(view_from, view_at, view_up, rotation, fov, aperture, focus_dist, resolutionWidth, resolutionHeight);
}

void App::Parsing::parseConfigFile()
{
    libconfig::Config cfg;
    try {
        cfg.readFile(_configFile.c_str());
    } catch (const libconfig::FileIOException &fioex) {
        throw ErrorCFGFile();
    }

    const libconfig::Setting &root = cfg.getRoot();
    parseShapes(root["Shapes"]);
    parseLights(root["Lights"]);
    parseObjFiles(root["Obj_paths"]);
    parseBackground(root["Background"]);
    parseCamera(root["Camera"]);
    parsePrecision(root["Precision"]);
}

void App::ParsingMaterial::output(std::ostream &os)  const noexcept
{
    os << "    {" << std::endl;
    os << "        Type: " << _type << std::endl;
    os << "        Color: " << _color << std::endl;
    os << "    }" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const App::ParsingMaterial &material)
{
    material.output(os);
    return os;
}

void App::ParsingTransformation::output(std::ostream &os)  const noexcept
{
    os << "    {" << std::endl;
    os << "        Type: " << _type << std::endl;
    os << "        Position: " << _position << std::endl;
    os << "    }" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const App::ParsingTransformation &transformation)
{
    transformation.output(os);
    return os;
}

void App::ParsingShape::output(std::ostream &os)  const noexcept
{
    os << "    Position: " << _position << std::endl;
    os << "    Size: " << _size << std::endl;
    os << "    Path: " << _path << std::endl;
    os << "    Material: " << std::endl << _material << std::endl;
    os << "    Transformations: " << std::endl;
    for (auto &transformation : _transformations) {
        os << transformation;
    }
}

std::ostream &operator<<(std::ostream &os, const App::ParsingShape &shape)
{
    shape.output(os);
    return os;
}

void App::ParsingLight::output(std::ostream &os)  const noexcept
{
    os << "    Position: " << _position  << std::endl;
    os << "    Color: " << _color << std::endl;
    os << "    Intensity: " << _intensity << std::endl;
    os << "    Direction: " << _direction << std::endl;
    os << "    Type: " << _type << std::endl;
}

std::ostream &operator<<(std::ostream &os, const App::ParsingLight &light)
{
    light.output(os);
    return os;
}

void App::ParsingCamera::output(std::ostream &os)  const noexcept
{
    os << "    View From: " << _view_from << std::endl;
    os << "    View At: " << _view_at << std::endl;
    os << "    View Up: " << _view_up << std::endl;
    os << "    Rotation: " << _rotation << std::endl;
    os << "    Fov: " << _fov << std::endl;
    os << "    Aperture: " << _aperture << std::endl;
    os << "    Focus Dist: " << _focus_dist << std::endl;
    os << "    Resolution: " << _resolution.first << " / " << _resolution.second << std::endl;
}

std::ostream &operator<<(std::ostream &os, const App::ParsingCamera &camera)
{
    camera.output(os);
    return os;
}

void App::ParsingBackground::output(std::ostream &os)  const noexcept
{
    os << "    Color: " << _color << std::endl;
    os << "    Path: " << _path << std::endl;
}

std::ostream &operator<<(std::ostream &os, const App::ParsingBackground &background)
{
    background.output(os);
    return os;
}

void App::ParsingPrecision::output(std::ostream &os)  const noexcept
{
    os << "    Samples: " << _samples << std::endl;
    os << "    Number of Bounces: " << _number_of_bounces << std::endl;
    os << "    Enable Shadows: " << _enable_shadows << std::endl;
    os << "    Enable Reflection: " << _enable_reflections << std::endl;
    os << "    Enable Refraction: " << _enable_refractions << std::endl;
}

std::ostream &operator<<(std::ostream &os, const App::ParsingPrecision &precision)
{
    precision.output(os);
    return os;
}

void App::Parsing::output(std::ostream &os)  const noexcept
{
    os << "Config File: " << _configFile << std::endl;
    os << "Shapes: " << std::endl;
    for (auto &shape : _shapes) {
        os << shape << std::endl;
    }
    os << "Lights: " << std::endl;
    for (auto &light : _lights) {
        os << light << std::endl;
    }
    os << "Obj Files: " << std::endl;
    for (auto &obj_file : _obj_files) {
        os << obj_file << std::endl;
    }
    os << std::endl;
    os << "Background: " << std::endl << _background << std::endl;
    os << "Camera: " << std::endl << _camera << std::endl;
    os << "Precision: " << std::endl << _precision << std::endl;
}

std::ostream &operator<<(std::ostream &os, const App::Parsing &parsing)
{
    parsing.output(os);
    return os;
}