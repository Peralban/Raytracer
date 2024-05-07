/*
** EPITECH PROJECT, 2024
** CFGGenerator.cpp
** File description:
** DESCRIPTION
*/

#include "CFGGenerator.hpp"
#include <functional>
#include <type_traits>

template<typename T>
typename std::enable_if<!std::is_array<T>::value, void>::type
checkCin(T& value, std::string message, std::function<bool(T)> bool_condition) {
    while (!(std::cin >> value) || !bool_condition(value)) {
        std::cout << message;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

template<typename T, std::size_t N>
void checkCin(T (&value)[N], std::string message, std::function<bool(T)> bool_condition, Bonus::ARRAY_TYPES type) {
    for (std::size_t i = 0; i < N; i++) {
        std::string new_message = message + (type == Bonus::C ? (i == 0 ? "R: " : i == 1 ? "G: " : "B: ") : type == Bonus::A ? (i == 0 ? "X: " : i == 1 ? "Y: " : "Z: ") : i == 0 ? "Width: " : i == 1 ? "Height: " : "");
        checkCin<T>(value[i], message, bool_condition);
    }
}

void Bonus::CFGGenerator::GetInfo()
{
    std::string output_file;
    int number_of_shapes;
    int number_of_lights;
    int number_of_obj_files;

    std::cout << "Enter the name of the output file: ";
    std::cin >> output_file;
    _output_file = output_file;
    if (_output_file.size() < 4 || (output_file[output_file.size() - 1] != 'g' && output_file[output_file.size() - 2] != 'f' &&
    output_file[output_file.size() - 3] != 'c' && output_file[output_file.size() - 4] != '.'))
        _output_file += ".cfg";

    std::cout << "Enter the number of shapes: ";
    checkCin<int>(number_of_shapes, "Invalid position, please enter a valid integer: ", []([[maybe_unused]]int ex) { return ex >= 0; });
    for (int i = 0; i < number_of_shapes; i++)
        askShape();
    askCamera();
    std::cout << "Enter the number of lights: ";
    checkCin<int>(number_of_lights, "Invalid position, please enter a valid integer: ", []([[maybe_unused]]int ex) { return ex >= 0; });
    for (int i = 0; i < number_of_lights; i++)
        askLight();
    askBackground();
    askPrecision();
    std::cout << "Enter the number of obj files: ";
    checkCin<int>(number_of_obj_files, "Invalid position, please enter a valid integer: ", []([[maybe_unused]]int ex) { return ex >= 0; });
    for (int i = 0; i < number_of_obj_files; i++)
        askObjFiles();
}

void Bonus::CFGGenerator::askShape()
{
    std::string type;
    bool enable_transformation = false;
    int nb_transformations;
    int position[ALL_INDEXES];
    int size[ALL_INDEXES];
    std::string path;
    std::string material_type;
    int color[ALL_INDEXES];
    bool enable_texture = false;
    std::vector<ParsingTransformation> transformations;
    std::cout << "Enter the type of the shape: ";
    checkCin<std::string>(type, "Invalid type, please enter a valid type: ", []([[maybe_unused]]std::string ex) { return ex == "sphere" || ex == "cube" || ex == "cylinder" || ex == "cone"; });
    std::cout << "Enter the position of the shape (first the X and enter, then the Y and enter, then the Z and enter):";
    checkCin<int, ALL_INDEXES>(position, "Invalid position, please enter a valid position for the position ", []([[maybe_unused]]int ex) { return true; }, A);
    std::cout << "Enter the size of the shape (first the X and enter, then the Y and enter, then the Z and enter):";
    checkCin<int, ALL_INDEXES>(size, "Invalid size, please enter a valid size for the size ", []([[maybe_unused]]int ex) { return ex >= 0; }, A);
    std::cout << "Enable texture? (1 for yes, 0 for no): ";
    checkCin<bool>(enable_texture, "Invalid input, please enter a valid input (1 for yes, 0 for no): ", []([[maybe_unused]]bool ex) { return ex == 0 || ex == 1; });
    if (enable_texture) {
        std::cout << "Enter the path to the texture of the shape: ";
        std::cin >> path;
        checkCin<std::string>(path, "Invalid path, please enter a valid path: ", []([[maybe_unused]]std::string ex) { return std::filesystem::exists(ex); });
    } else {
        path = "none";
    }
    std::cout << "Enable transformations? (1 for yes, 0 for no): ";
    checkCin<bool>(enable_transformation, "Invalid input, please enter a valid input (1 for yes, 0 for no): ", []([[maybe_unused]]bool ex) { return ex == 0 || ex == 1; });
    if (enable_transformation) {
        std::cout << "Enter the number of transformations (int): ";
        checkCin<int>(nb_transformations, "Invalid number of transformations, please enter a valid number of transformations: ", []([[maybe_unused]]int ex) { return ex > 0; });
        for (int i = 0; i < nb_transformations; i++)
            transformations.push_back(askTransformation());
    }
    std::cout << "Enter the type of the material: ";
    checkCin<std::string>(material_type, "Invalid type, please enter a valid type: ", []([[maybe_unused]]std::string ex) { return ex == "matte" || ex == "metal" || ex == "glass"; });
    std::cout << "Enter the color of the material (first the R and enter, then the G and enter, then the B and enter):";
    checkCin<int, ALL_INDEXES>(color, "Invalid color, please enter a valid color for the color ", []([[maybe_unused]]int ex) { return ex >= 0 && ex <= 255; }, C);
    ParsingMaterial new_material(material_type, color[R], color[G], color[B]);
    ParsingShape new_shape(type, position[X], position[Y], position[Z], size[X], size[Y], size[Z], path, new_material, transformations);
    _shapes.push_back(new_shape);
}

void Bonus::CFGGenerator::askCamera()
{
    int view_from[ALL_INDEXES];
    int view_at[ALL_INDEXES];
    int view_up[ALL_INDEXES];
    int rotation[ALL_INDEXES];
    float fov;
    float aperture;
    float focus_dist;
    int resolution[RESO_INDEX];
    std::cout << "Enter the position of the camera (first the X and enter, then the Y and enter, then the Z and enter): ";
    checkCin<int, ALL_INDEXES>(view_from, "Invalid view_from, please enter a valid integer for the position ", []([[maybe_unused]]int ex) { return true; }, A);
    std::cout << "Enter the point the camera is looking at (first the X and enter, then the Y and enter, then the Z and enter): ";
    checkCin<int, ALL_INDEXES>(view_at, "Invalid view_at, please enter a valid integer for the position ", []([[maybe_unused]]int ex) { return true; }, A);
    std::cout << "Enter the up vector of the camera (first the X and enter, then the Y and enter, then the Z and enter): ";
    checkCin<int, ALL_INDEXES>(view_up, "Invalid view_up, please enter a valid integer for the position ", []([[maybe_unused]]int ex) { return true; }, A);
    std::cout << "Enter the rotation of the camera (first the X and enter, then the Y and enter, then the Z and enter): ";
    checkCin<int, ALL_INDEXES>(rotation, "Invalid rotation, please enter a valid integer for the rotation ", []([[maybe_unused]]int ex) { return true; }, A);
    std::cout << "Enter the field of view of the camera (float): ";
    checkCin<float>(fov, "Invalid fov, please enter a valid field of view: ", []([[maybe_unused]]float ex) { return ex >= 0; });
    std::cout << "Enter the aperture of the camera (float): ";
    checkCin<float>(aperture, "Invalid aperture, please enter a valid aperture: ", []([[maybe_unused]]float ex) { return ex >= 0; });
    std::cout << "Enter the focus distance of the camera (float): ";
    checkCin<float>(focus_dist, "Invalid focus distance, please enter a valid focus distance: ", []([[maybe_unused]]float ex) { return ex >= 0; });
    std::cout << "Enter the resolution of the camera (first the width and enter, then the height and enter): ";
    checkCin<int, RESO_INDEX>(resolution, "Invalid resolution, please enter a valid resolution for the ", []([[maybe_unused]]int ex) { return ex >= 0; }, RE);
    ParsingCamera new_camera(view_from[X], view_from[Y], view_from[Z],
    view_at[X], view_at[Y], view_at[Z], view_up[X], view_up[Y], view_up[Z],
    rotation[X], rotation[Y], rotation[Z], fov, aperture, focus_dist, resolution[WIDTH], resolution[HEIGHT]);
    _camera = new_camera;
}

void Bonus::CFGGenerator::askLight()
{
    int position[ALL_INDEXES];
    int color[ALL_INDEXES];
    float intensity;
    int rotation[ALL_INDEXES];
    std::string type;
    std::cout << "Enter the position of the light: ";
    std::cin >> position[X] >> position[Y] >> position[Z];
    checkCin<int, ALL_INDEXES>(position, "Invalid position, please enter a valid position for the position ", []([[maybe_unused]]int ex) {return true;}, A);
    std::cout << "Enter the color of the light: ";
    std::cin >> color[R] >> color[G] >> color[B];
    checkCin<int, ALL_INDEXES>(color, "Invalid color, please enter a valid color for the color ", []([[maybe_unused]]int ex) { return ex >= 0 && ex <= 255; }, C);
    std::cout << "Enter the intensity of the light: ";
    std::cin >> intensity;
    checkCin<float>(intensity, "Invalid intensity, please enter a valid intensity (between 0 and 1): ", []([[maybe_unused]]float ex) { return ex >= 0 && ex <= 1; });
    std::cout << "Enter the rotation of the light: ";
    std::cin >> rotation[X] >> rotation[Y] >> rotation[Z];
    checkCin<int, ALL_INDEXES>(rotation, "Invalid rotation, please enter a valid rotation for the rotation ", []([[maybe_unused]]int ex) { return true; }, A);
    std::cout << "Enter the type of the light: ";
    std::cin >> type;
    checkCin<std::string>(type, "Invalid type of light, please enter a valid type (point, directional or spot): ", []([[maybe_unused]]std::string ex) { return ex == "point" || ex == "directional" || ex == "spot"; });
    ParsingLight new_light(position[X], position[Y], position[Z], color[R], color[G], color[B], intensity, rotation[X], rotation[Y], rotation[Z], type);
    _lights.push_back(new_light);
}
//none
void Bonus::CFGGenerator::askBackground()
{
    int color[ALL_INDEXES];
    bool enable_background = false;
    std::string path;
    std::cout << "Enter the color of the background (first the R and enter, then the G and enter, then the B and enter): ";
    checkCin<int, ALL_INDEXES>(color, "Invalid color, please enter a valid color for the color ", []([[maybe_unused]]int ex) { return ex >= 0 && ex <= 255; }, C);
    std::cout << "Enable background from texture file? (1 for yes, 0 for no): ";
    checkCin<bool>(enable_background, "Invalid input, please enter a valid input (1 for yes, 0 for no): ", []([[maybe_unused]]bool ex) { return ex == 0 || ex == 1; });
    if (enable_background) {
        std::cout << "Enter the path of the background texture: ";
        std::cin >> path;
        checkCin<std::string>(path, "Invalid path, please enter a valid path: ", []([[maybe_unused]]std::string ex) { return std::filesystem::exists(ex); });
    } else {
        path = "none";
    }
    ParsingBackground new_background(color[R], color[G], color[B], path);
    _background = new_background;
}

void Bonus::CFGGenerator::askPrecision()
{
    int samples;
    int number_of_bounces;
    bool enable_shadows = true;
    bool enable_reflections = true;
    bool enable_refractions = true;
    std::cout << "Enter the number of samples (int): ";
    checkCin<int>(samples, "Invalid number of samples, please enter a valid number of samples: ", []([[maybe_unused]]int ex) { return ex > 0; });
    std::cout << "Enter the number of bounces (int): ";
    checkCin<int>(number_of_bounces, "Invalid number of bounces, please enter a valid number of bounces: ", []([[maybe_unused]]int ex) { return ex > 0; });
    std::cout << "Enable shadows? (1 for yes, 0 for no): ";
    checkCin<bool>(enable_shadows, "Invalid input, please enter a valid input (1 for yes, 0 for no): ", []([[maybe_unused]]bool ex) { return ex == 0 || ex == 1; });
    std::cout << "Enable reflections? (1 for yes, 0 for no): ";
    checkCin<bool>(enable_reflections, "Invalid input, please enter a valid input (1 for yes, 0 for no): ", []([[maybe_unused]]bool ex) { return ex == 0 || ex == 1; });
    std::cout << "Enable refractions? (1 for yes, 0 for no): ";
    checkCin<bool>(enable_refractions, "Invalid input, please enter a valid input (1 for yes, 0 for no): ", []([[maybe_unused]]bool ex) { return ex == 0 || ex == 1; });
    ParsingPrecision new_precision(samples, number_of_bounces, enable_shadows, enable_reflections, enable_refractions);
    _precision = new_precision;
}

void Bonus::CFGGenerator::askObjFiles()
{
    std::string path;
    std::cout << "Enter the path of the obj file: ";
    checkCin<std::string>(path, "Invalid path, please enter a valid path: ", []([[maybe_unused]]std::string ex) { return std::filesystem::exists(ex); });
    _obj_files.push_back(path);
}

Bonus::ParsingTransformation Bonus::CFGGenerator::askTransformation()
{
    std::string type;
    int value[ALL_INDEXES];
    std::cout << "Enter the type of the transformation (translate, rotate, scale, mirror, shear): ";
    checkCin<std::string>(type, "Invalid type of transformation, please enter a valid type: ", []([[maybe_unused]]std::string ex) { return ex == "translate" || ex == "rotate" || ex == "scale" || ex == "mirror" || ex == "shear"; });
    std::cout << "Enter the values of the transformation (first the X and enter, then the Y and enter, then the Z and enter): ";
    checkCin<int, ALL_INDEXES>(value, "Invalid values, please enter a valid value for the values ", []([[maybe_unused]]int ex) { return ex >= 0; }, A);
    return ParsingTransformation(type, value[X], value[Y], value[Z]);
}
