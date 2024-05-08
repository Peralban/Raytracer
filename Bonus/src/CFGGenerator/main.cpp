/*
** EPITECH PROJECT, 2024
** main.cpp
** File description:
** DESCRIPTION
*/

#include <iostream>
#include <libconfig.h++>
#include "CFGGenerator.hpp"

void makeShape(libconfig::Setting &shapes, std::vector<Bonus::ParsingShape> shapesInfo)
{
    for (auto &shape : shapesInfo) {
        libconfig::Setting &shapeSetting = shapes.add(libconfig::Setting::TypeGroup);
        shapeSetting.add("type", libconfig::Setting::TypeString) = shape.getType();
        libconfig::Setting &shape_position = shapeSetting.add("position", libconfig::Setting::TypeArray);
        shape_position.add(libconfig::Setting::TypeInt) = shape.getPositionX();
        shape_position.add(libconfig::Setting::TypeInt) = shape.getPositionY();
        shape_position.add(libconfig::Setting::TypeInt) = shape.getPositionZ();
        libconfig::Setting &shape_size = shapeSetting.add("size", libconfig::Setting::TypeArray);
        shape_size.add(libconfig::Setting::TypeInt) = shape.getSizeX();
        shape_size.add(libconfig::Setting::TypeInt) = shape.getSizeY();
        shape_size.add(libconfig::Setting::TypeInt) = shape.getSizeZ();
        shapeSetting.add("texture_path", libconfig::Setting::TypeString) = shape.getPath();
        libconfig::Setting &shape_materials = shapeSetting.add("materials", libconfig::Setting::TypeGroup);
        shape_materials.add("type", libconfig::Setting::TypeString) = shape.getMaterial().getType();
        libconfig::Setting &shape_color = shape_materials.add("color", libconfig::Setting::TypeArray);
        shape_color.add(libconfig::Setting::TypeInt) = shape.getMaterial().getR();
        shape_color.add(libconfig::Setting::TypeInt) = shape.getMaterial().getG();
        shape_color.add(libconfig::Setting::TypeInt) = shape.getMaterial().getB();
        libconfig::Setting &shape_transformations = shapeSetting.add("transformations", libconfig::Setting::TypeList);
        for (auto &transformation : shape.getTransformations()) {
            libconfig::Setting &transformationSetting = shape_transformations.add(libconfig::Setting::TypeGroup);
            transformationSetting.add("type", libconfig::Setting::TypeString) = transformation.getType();
            libconfig::Setting &transformation_position = transformationSetting.add("position", libconfig::Setting::TypeArray);
            transformation_position.add(libconfig::Setting::TypeInt) = transformation.getPositionX();
            transformation_position.add(libconfig::Setting::TypeInt) = transformation.getPositionY();
            transformation_position.add(libconfig::Setting::TypeInt) = transformation.getPositionZ();
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
    camera_view_from.add(libconfig::Setting::TypeInt) = cameraInfo.getViewFromX();
    camera_view_from.add(libconfig::Setting::TypeInt) = cameraInfo.getViewFromY();
    camera_view_from.add(libconfig::Setting::TypeInt) = cameraInfo.getViewFromZ();
    libconfig::Setting &camera_view_at = camera.add("view_at", libconfig::Setting::TypeArray);
    camera_view_at.add(libconfig::Setting::TypeInt) = cameraInfo.getViewAtX();
    camera_view_at.add(libconfig::Setting::TypeInt) = cameraInfo.getViewAtY();
    camera_view_at.add(libconfig::Setting::TypeInt) = cameraInfo.getViewAtZ();
    libconfig::Setting &camera_view_up = camera.add("view_up", libconfig::Setting::TypeArray);
    camera_view_up.add(libconfig::Setting::TypeInt) = cameraInfo.getViewUpX();
    camera_view_up.add(libconfig::Setting::TypeInt) = cameraInfo.getViewUpY();
    camera_view_up.add(libconfig::Setting::TypeInt) = cameraInfo.getViewUpZ();
    libconfig::Setting &rotation = camera.add("rotation", libconfig::Setting::TypeArray);
    rotation.add(libconfig::Setting::TypeInt) = cameraInfo.getRotationX();
    rotation.add(libconfig::Setting::TypeInt) = cameraInfo.getRotationY();
    rotation.add(libconfig::Setting::TypeInt) = cameraInfo.getRotationZ();
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
        light_position.add(libconfig::Setting::TypeInt) = light.getPositionX();
        light_position.add(libconfig::Setting::TypeInt) = light.getPositionY();
        light_position.add(libconfig::Setting::TypeInt) = light.getPositionZ();
        libconfig::Setting &light_color = lightSetting.add("color", libconfig::Setting::TypeArray);
        light_color.add(libconfig::Setting::TypeInt) = light.getColorR();
        light_color.add(libconfig::Setting::TypeInt) = light.getColorG();
        light_color.add(libconfig::Setting::TypeInt) = light.getColorB();
        lightSetting.add("intensity", libconfig::Setting::TypeFloat) = light.getIntensity();
        libconfig::Setting &light_rotation = lightSetting.add("rotation", libconfig::Setting::TypeArray);
        light_rotation.add(libconfig::Setting::TypeInt) = light.getRotationX();
        light_rotation.add(libconfig::Setting::TypeInt) = light.getRotationY();
        light_rotation.add(libconfig::Setting::TypeInt) = light.getRotationZ();
        lightSetting.add("type", libconfig::Setting::TypeString) = light.getType();
    }
}

void makeBackground(libconfig::Setting &background, Bonus::ParsingBackground backgroundInfo)
{
    libconfig::Setting &background_color = background.add("color", libconfig::Setting::TypeArray);
    background_color.add(libconfig::Setting::TypeInt) = backgroundInfo.getColorR();
    background_color.add(libconfig::Setting::TypeInt) = backgroundInfo.getColorG();
    background_color.add(libconfig::Setting::TypeInt) = backgroundInfo.getColorB();
    background_color.add(libconfig::Setting::TypeInt) = 1;
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
