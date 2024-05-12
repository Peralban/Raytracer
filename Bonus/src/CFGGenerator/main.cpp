/*
** EPITECH PROJECT, 2024
** main.cpp
** File description:
** DESCRIPTION
*/

#include <iostream>
#include <libconfig.h++>
#include "CFGGenerator.hpp"

static void makeMaterial(libconfig::Setting &shape_material, Bonus::ParsingMaterial material)
{
    shape_material.add("type", libconfig::Setting::TypeString) = material.getType();
    if (material.getType() == "matte") {
        libconfig::Setting &color = shape_material.add("color", libconfig::Setting::TypeArray);
        color.add(libconfig::Setting::TypeInt) = material.getR();
        color.add(libconfig::Setting::TypeInt) = material.getG();
        color.add(libconfig::Setting::TypeInt) = material.getB();
    } else if (material.getType() == "metal") {
        libconfig::Setting &color = shape_material.add("color", libconfig::Setting::TypeArray);
        color.add(libconfig::Setting::TypeInt) = material.getR();
        color.add(libconfig::Setting::TypeInt) = material.getG();
        color.add(libconfig::Setting::TypeInt) = material.getB();
        shape_material.add("fuzziness", libconfig::Setting::TypeFloat) = material.getFuzz();
    } else if (material.getType() == "glass") {
        libconfig::Setting &albedo = shape_material.add("albedo", libconfig::Setting::TypeArray);
        albedo.add(libconfig::Setting::TypeFloat) = material.getAlbedoR();
        albedo.add(libconfig::Setting::TypeFloat) = material.getAlbedoG();
        albedo.add(libconfig::Setting::TypeFloat) = material.getAlbedoB();
        shape_material.add("refraction_index", libconfig::Setting::TypeFloat) = material.getRefIdx();
    } else if (material.getType() == "light") {
        libconfig::Setting &color = shape_material.add("color", libconfig::Setting::TypeArray);
        color.add(libconfig::Setting::TypeInt) = material.getR();
        color.add(libconfig::Setting::TypeInt) = material.getG();
        color.add(libconfig::Setting::TypeInt) = material.getB();
        shape_material.add("intensity", libconfig::Setting::TypeFloat) = material.getIntensity();
    }
}

static void writeSize(libconfig::Setting &shape_size, Bonus::ParsingShape shape)
{
    if (shape.getType() == "sphere") {
        shape_size.add("radius", libconfig::Setting::TypeFloat) = shape.getRadius();
    } else if (shape.getType() == "plane") {
        shape_size.add("normal", libconfig::Setting::TypeArray);
        shape_size["normal"].add(libconfig::Setting::TypeFloat) = shape.getNormalX();
        shape_size["normal"].add(libconfig::Setting::TypeFloat) = shape.getNormalY();
        shape_size["normal"].add(libconfig::Setting::TypeFloat) = shape.getNormalZ();
    } else if (shape.getType() == "cylinder") {
        shape_size.add("radius", libconfig::Setting::TypeFloat) = shape.getRadius();
    } else if (shape.getType() == "limited_cylinder") {
        shape_size.add("radius", libconfig::Setting::TypeFloat) = shape.getRadius();
        shape_size.add("height", libconfig::Setting::TypeFloat) = shape.getHeight();
    } else if (shape.getType() == "cone") {
        shape_size.add("angle", libconfig::Setting::TypeFloat) = shape.getAngle();
    } else if (shape.getType() == "limited_cone") {
        shape_size.add("angle", libconfig::Setting::TypeFloat) = shape.getAngle();
        shape_size.add("height", libconfig::Setting::TypeFloat) = shape.getHeight();
    } else if (shape.getType() == "parallelepiped") {
        shape_size.add("size", libconfig::Setting::TypeArray);
        shape_size["size"].add(libconfig::Setting::TypeFloat) = shape.getSizeX();
        shape_size["size"].add(libconfig::Setting::TypeFloat) = shape.getSizeY();
        shape_size["size"].add(libconfig::Setting::TypeFloat) = shape.getSizeZ();
    } else if (shape.getType() == "tangle_cube") {
        shape_size.add("size", libconfig::Setting::TypeFloat) = shape.getSize();
    } else if (shape.getType() == "torus") {
        shape_size.add("max_radius", libconfig::Setting::TypeFloat) = shape.getMaxRadius();
        shape_size.add("min_radius", libconfig::Setting::TypeFloat) = shape.getMinRadius();
    }
}

void makeShape(libconfig::Setting &shapes, std::vector<Bonus::ParsingShape> shapesInfo)
{
    for (auto &shape : shapesInfo) {
        libconfig::Setting &shapeSetting = shapes.add(libconfig::Setting::TypeGroup);
        shapeSetting.add("type", libconfig::Setting::TypeString) = shape.getType();
        libconfig::Setting &shape_position = shapeSetting.add("position", libconfig::Setting::TypeArray);
        shape_position.add(libconfig::Setting::TypeFloat) = shape.getPositionX();
        shape_position.add(libconfig::Setting::TypeFloat) = shape.getPositionY();
        shape_position.add(libconfig::Setting::TypeFloat) = shape.getPositionZ();
        writeSize(shapeSetting, shape);
        shapeSetting.add("texture_path", libconfig::Setting::TypeString) = shape.getPath();
        libconfig::Setting &shape_material = shapeSetting.add("material", libconfig::Setting::TypeGroup);
        makeMaterial(shape_material, shape.getMaterial());
        libconfig::Setting &shape_transformations = shapeSetting.add("transformations", libconfig::Setting::TypeList);
        for (auto &transformation : shape.getTransformations()) {
            libconfig::Setting &transformationSetting = shape_transformations.add(libconfig::Setting::TypeGroup);
            transformationSetting.add("type", libconfig::Setting::TypeString) = transformation.getType();
            libconfig::Setting &transformation_position = transformationSetting.add("position", libconfig::Setting::TypeArray);
            transformation_position.add(libconfig::Setting::TypeFloat) = transformation.getPositionX();
            transformation_position.add(libconfig::Setting::TypeFloat) = transformation.getPositionY();
            transformation_position.add(libconfig::Setting::TypeFloat) = transformation.getPositionZ();
        }
    }
}

void makeObjPaths(libconfig::Setting &obj_paths, std::vector<std::string> objPaths)
{
    for (auto &objPath : objPaths) {
        obj_paths.add(libconfig::Setting::TypeString) = objPath;
    }
}

void makeCamera(libconfig::Setting &camera, Bonus::ParsingCamera cameraInfo)
{
    libconfig::Setting &camera_view_from = camera.add("view_from", libconfig::Setting::TypeArray);
    camera_view_from.add(libconfig::Setting::TypeFloat) = cameraInfo.getViewFromX();
    camera_view_from.add(libconfig::Setting::TypeFloat) = cameraInfo.getViewFromY();
    camera_view_from.add(libconfig::Setting::TypeFloat) = cameraInfo.getViewFromZ();
    libconfig::Setting &camera_view_at = camera.add("view_at", libconfig::Setting::TypeArray);
    camera_view_at.add(libconfig::Setting::TypeFloat) = cameraInfo.getViewAtX();
    camera_view_at.add(libconfig::Setting::TypeFloat) = cameraInfo.getViewAtY();
    camera_view_at.add(libconfig::Setting::TypeFloat) = cameraInfo.getViewAtZ();
    libconfig::Setting &camera_view_up = camera.add("view_up", libconfig::Setting::TypeArray);
    camera_view_up.add(libconfig::Setting::TypeFloat) = cameraInfo.getViewUpX();
    camera_view_up.add(libconfig::Setting::TypeFloat) = cameraInfo.getViewUpY();
    camera_view_up.add(libconfig::Setting::TypeFloat) = cameraInfo.getViewUpZ();
    libconfig::Setting &rotation = camera.add("rotation", libconfig::Setting::TypeArray);
    rotation.add(libconfig::Setting::TypeFloat) = cameraInfo.getRotationX();
    rotation.add(libconfig::Setting::TypeFloat) = cameraInfo.getRotationY();
    rotation.add(libconfig::Setting::TypeFloat) = cameraInfo.getRotationZ();
    camera.add("fov", libconfig::Setting::TypeFloat) = cameraInfo.getFov();
    camera.add("aperture", libconfig::Setting::TypeFloat) = cameraInfo.getAperture();
    camera.add("focus_distance", libconfig::Setting::TypeFloat) = cameraInfo.getFocusDist();
    libconfig::Setting &aspect_ratio = camera.add("aspect_ratio", libconfig::Setting::TypeArray);
    aspect_ratio.add(libconfig::Setting::TypeInt) = cameraInfo.getResolutionWidth();
    aspect_ratio.add(libconfig::Setting::TypeInt) = cameraInfo.getResolutionHeight();

}

void makeLight(libconfig::Setting &lights, std::vector<Bonus::ParsingLight> lightsInfo)
{
    for (auto &light : lightsInfo) {
        libconfig::Setting &lightSetting = lights.add(libconfig::Setting::TypeGroup);
        libconfig::Setting &light_position = lightSetting.add("position", libconfig::Setting::TypeArray);
        light_position.add(libconfig::Setting::TypeFloat) = light.getPositionX();
        light_position.add(libconfig::Setting::TypeFloat) = light.getPositionY();
        light_position.add(libconfig::Setting::TypeFloat) = light.getPositionZ();
        libconfig::Setting &light_color = lightSetting.add("color", libconfig::Setting::TypeArray);
        light_color.add(libconfig::Setting::TypeInt) = light.getColorR();
        light_color.add(libconfig::Setting::TypeInt) = light.getColorG();
        light_color.add(libconfig::Setting::TypeInt) = light.getColorB();
        lightSetting.add("intensity", libconfig::Setting::TypeFloat) = light.getIntensity();
        libconfig::Setting &light_rotation = lightSetting.add("rotation", libconfig::Setting::TypeArray);
        light_rotation.add(libconfig::Setting::TypeFloat) = light.getRotationX();
        light_rotation.add(libconfig::Setting::TypeFloat) = light.getRotationY();
        light_rotation.add(libconfig::Setting::TypeFloat) = light.getRotationZ();
        lightSetting.add("type", libconfig::Setting::TypeString) = light.getType();
    }
}

void makeBackground(libconfig::Setting &background, Bonus::ParsingBackground backgroundInfo)
{
    libconfig::Setting &background_color = background.add("color", libconfig::Setting::TypeArray);
    background_color.add(libconfig::Setting::TypeInt) = backgroundInfo.getColorR();
    background_color.add(libconfig::Setting::TypeInt) = backgroundInfo.getColorG();
    background_color.add(libconfig::Setting::TypeInt) = backgroundInfo.getColorB();
    background.add("texture_path", libconfig::Setting::TypeString) = backgroundInfo.getTexturePath();
}

void makePrecision(libconfig::Setting &precision, Bonus::ParsingPrecision precisionInfo)
{
    precision.add("samples", libconfig::Setting::TypeInt) = precisionInfo.getSamples();
    precision.add("number_of_bounces", libconfig::Setting::TypeInt) = precisionInfo.getNumberOfBounces();
    precision.add("enable_shadows", libconfig::Setting::TypeBoolean) = precisionInfo.getEnableShadows();
    precision.add("enable_reflection", libconfig::Setting::TypeBoolean) = precisionInfo.getEnableReflections();
    precision.add("enable_refraction", libconfig::Setting::TypeBoolean) = precisionInfo.getEnableRefractions();
}

int main()
{
    Bonus::CFGGenerator cfg_generator;
    cfg_generator.GetInfo();
    libconfig::Config cfg;
    libconfig::Setting &root = cfg.getRoot();

    libconfig::Setting &shapes = root.add("Shapes", libconfig::Setting::TypeList);
    libconfig::Setting &camera = root.add("Camera", libconfig::Setting::TypeGroup);
    libconfig::Setting &lights = root.add("Lights", libconfig::Setting::TypeList);
    libconfig::Setting &obj_paths = root.add("Obj_paths", libconfig::Setting::TypeList);
    libconfig::Setting &background = root.add("Background", libconfig::Setting::TypeGroup);
    libconfig::Setting &precision = root.add("Precision", libconfig::Setting::TypeGroup);
    try {
        // SHAPES
        makeShape(shapes, cfg_generator.getShapes());

        // OBJ PATHS
        makeObjPaths(obj_paths, cfg_generator.getObjPaths());

        // Cameras
        makeCamera(camera, cfg_generator.getCamera());

        // Lights
        makeLight(lights, cfg_generator.getLights());

        // Background
        makeBackground(background, cfg_generator.getBackground());

        // Precision
        makePrecision(precision, cfg_generator.getPrecision());
    } catch(const libconfig::ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine() << " - " << pex.getError() << std::endl;
        return(EXIT_FAILURE);
    }


    // Write out the new configuration
    try
    {
        cfg.writeFile(cfg_generator.getOutputFile().c_str());
        std::cerr << "New configuration successfully written to: " << cfg_generator.getOutputFile() << std::endl;
    }
    catch(const libconfig::FileIOException &fioex)
    {
        std::cerr << "Error while writing file: " << fioex.what() << std::endl;
        return(EXIT_FAILURE);
    }
    return(EXIT_SUCCESS);
}
