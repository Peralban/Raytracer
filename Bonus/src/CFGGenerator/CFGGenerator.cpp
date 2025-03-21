/*
** EPITECH PROJECT, 2024
** CFGGenerator.cpp
** File description:
** DESCRIPTION
*/

/**
 * @file CFGGenerator.cpp
 * @brief CFGGenerator class implementation
 */

#include "CFGGenerator.hpp"
#include <functional>
#include <type_traits>

/**
 * @brief Template function to check user input.
 *
 * This function checks the user input against a provided condition. If the input is not valid, it prompts the user with a message until a valid input is provided.
 *
 * @tparam T The type of the value to check.
 * @param value The value to check.
 * @param message The message to display if the input is not valid.
 * @param bool_condition The condition to check the input against.
 *
 * @note This function is enabled only when T is not an array type. This is controlled by the std::enable_if<!std::is_array<T>::value, void>::type mechanism.
 */
template<typename T>
typename std::enable_if<!std::is_array<T>::value, void>::type
checkCin(T& value, std::string message, std::function<bool(T)> bool_condition) {
    while (!(std::cin >> value) || !bool_condition(value)) {
        std::cout << message;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

/**
 * @brief Template function to check user input for an array.
 *
 * This function checks the user input for each element of an array against a provided condition. If the input is not valid, it prompts the user with a message until a valid input is provided.
 *
 * @tparam T The type of the values to check.
 * @tparam N The size of the array.
 * @param value The array of values to check.
 * @param message The message to display if the input is not valid.
 * @param bool_condition The condition to check the input against. (lambda function) (functional paradigm)
 * @param type The type of the array (used to customize the message).
 */
template<typename T, std::size_t N>
void checkCin(T (&value)[N], std::string message, std::function<bool(T)> bool_condition, Bonus::ARRAY_TYPES type) {
    for (std::size_t i = 0; i < N; i++) {
        std::string new_message = message;
        if (type == Bonus::RE) {
            if (i == 0)
                new_message += "Width: ";
            else
                new_message += "Height: ";
        } else if (type == Bonus::C) {
            if (i == 0)
                new_message += "R: ";
            else if (i == 1)
                new_message += "G: ";
            else
                new_message += "B: ";
        } else {
            if (i == 0)
                new_message += "X: ";
            else if (i == 1)
                new_message += "Y: ";
            else
                new_message += "Z: ";
        }
        checkCin<T>(value[i], message, bool_condition);
    }
}

/**
 * @brief Collects information from the user to generate a configuration.
 *
 * This function prompts the user for various parameters needed to generate a configuration for the ray tracing application.
 * It asks for the output file name, the number of shapes, lights, and obj files, and calls other functions to gather more specific information.
 * The gathered information is stored in member variables of the CFGGenerator class.
 */
void Bonus::CFGGenerator::GetInfo()
{
    std::string output_file;
    int number_of_shapes;
    int number_of_obj_files;

    // Prompt for the output file name
    std::cout << "Enter the name of the output file: ";
    std::cin >> output_file;
    _output_file = output_file;
    if (_output_file.size() < 4 || (output_file[output_file.size() - 1] != 'g' && output_file[output_file.size() - 2] != 'f' &&
    output_file[output_file.size() - 3] != 'c' && output_file[output_file.size() - 4] != '.'))
        _output_file += ".cfg";

    // Prompt for the number of shapes
    std::cout << "Enter the number of shapes: ";
    checkCin<int>(number_of_shapes, "Invalid position, please enter a valid integer: ", []([[maybe_unused]]int ex) { return ex >= 0; });
    for (int i = 0; i < number_of_shapes; i++)
        askShape(); // Ask for shape information
    askCamera(); // Ask for camera information
    askBackground(); // Ask for background information
    askPrecision(); // Ask for precision information

    // Prompt for the number of obj files
    std::cout << "Enter the number of obj files: ";
    checkCin<int>(number_of_obj_files, "Invalid position, please enter a valid integer: ", []([[maybe_unused]]int ex) { return ex >= 0; });
    for (int i = 0; i < number_of_obj_files; i++)
        askObjFiles(); // Ask for obj file information
}

static Bonus::ParsingMaterial askMaterial()
{
    int color[ALL_INDEXES];
    float albedo[ALL_INDEXES];
    bool enable_texture = false;
    std::string path;
    float fuzz;
    float ref_idx;
    double intensity;
    std::string material_type;
    int color1[ALL_INDEXES] = {0, 0, 0};
    int color2[ALL_INDEXES] = {0, 0, 0};
    double scale = 0;

    std::cout << "Enter the type of the material (matte, metal, glass, light): ";
    checkCin<std::string>(material_type, "Invalid type, please enter a valid type: ", []([[maybe_unused]]std::string ex) { return ex == "matte" || ex == "metal" || ex == "glass" || ex == "light"; });
    if (material_type == "matte") {
        std::cout << "Enter the color of the material (first the R and enter, then the G and enter, then the B and enter):";
        checkCin<int, ALL_INDEXES>(color, "Invalid color, please enter a valid color for the color ", []([[maybe_unused]]int ex) { return ex >= 0 && ex <= 255; }, Bonus::C);

        std::cout << "Enable texture? (1 for yes, 0 for no): ";
        checkCin<bool>(enable_texture, "Invalid input, please enter a valid input (1 for yes, 0 for no): ", []([[maybe_unused]]bool ex) { return ex == 0 || ex == 1; });
        if (enable_texture) {
            std::cout << "Enter the path to the texture of the shape or chessboard: ";
            checkCin<std::string>(path, "Invalid path, please enter a valid path: ", []([[maybe_unused]]std::string ex) { return ex == "chessboard" || std::filesystem::exists(ex); });
            std::cout << "Enter the scale of the texture (float): ";
            checkCin<double>(scale, "Invalid scale, please enter a valid scale: ", []([[maybe_unused]]double ex) { return ex >= 0; });
            if (path == "chessboard") {
                std::cout << "Enter the color of the first square (first the R and enter, then the G and enter, then the B and enter): ";
                checkCin<int, ALL_INDEXES>(color1, "Invalid color, please enter a valid color for the color ", []([[maybe_unused]]int ex) { return ex >= 0 && ex <= 255; }, Bonus::C);
                std::cout << "Enter the color of the second square (first the R and enter, then the G and enter, then the B and enter): ";
                checkCin<int, ALL_INDEXES>(color2, "Invalid color, please enter a valid color for the color ", []([[maybe_unused]]int ex) { return ex >= 0 && ex <= 255; }, Bonus::C);
            }
        } else {
            path = "none";
        }
        return Bonus::ParsingMaterial(material_type, color[Bonus::R], color[Bonus::G], color[Bonus::B], enable_texture, path, color1[Bonus::R], color1[Bonus::G], color1[Bonus::B], color2[Bonus::R], color2[Bonus::G], color2[Bonus::B], scale);
    } else if (material_type == "metal") {
        std::cout << "Enter the color of the material (first the R and enter, then the G and enter, then the B and enter):";
        checkCin<int, ALL_INDEXES>(color, "Invalid color, please enter a valid color for the color ", []([[maybe_unused]]int ex) { return ex >= 0 && ex <= 255; }, Bonus::C);
        std::cout << "Enter the fuzziness of the material (float between 0 and 1): ";
        checkCin<float>(fuzz, "Invalid fuzziness, please enter a valid fuzziness (between 0 and 1): ", []([[maybe_unused]]float ex) { return ex >= 0 && ex <= 1; });


        std::cout << "Enable texture? (1 for yes, 0 for no): ";
        checkCin<bool>(enable_texture, "Invalid input, please enter a valid input (1 for yes, 0 for no): ", []([[maybe_unused]]bool ex) { return ex == 0 || ex == 1; });
        std::cout << "Enter the scale of the texture (float): ";
        checkCin<double>(scale, "Invalid scale, please enter a valid scale: ", []([[maybe_unused]]double ex) { return ex >= 0; });
        if (enable_texture) {
            std::cout << "Enter the path to the texture of the shape or chessboard: ";
            checkCin<std::string>(path, "Invalid path, please enter a valid path: ", []([[maybe_unused]]std::string ex) { return ex == "chessboard" || std::filesystem::exists(ex); });
            if (path == "chessboard") {
                std::cout << "Enter the color of the first square (first the R and enter, then the G and enter, then the B and enter): ";
                checkCin<int, ALL_INDEXES>(color1, "Invalid color, please enter a valid color for the color ", []([[maybe_unused]]int ex) { return ex >= 0 && ex <= 255; }, Bonus::C);
                std::cout << "Enter the color of the second square (first the R and enter, then the G and enter, then the B and enter): ";
                checkCin<int, ALL_INDEXES>(color2, "Invalid color, please enter a valid color for the color ", []([[maybe_unused]]int ex) { return ex >= 0 && ex <= 255; }, Bonus::C);
            }
        } else {
            path = "none";
        }
        return Bonus::ParsingMaterial(material_type, fuzz, color[Bonus::R], color[Bonus::G], color[Bonus::B], enable_texture, path, color1[Bonus::R], color1[Bonus::G], color1[Bonus::B], color2[Bonus::R], color2[Bonus::G], color2[Bonus::B], scale);
    } else if (material_type == "glass") {
        std::cout << "Enter the albedo of the material (first the X and enter, then the Y and enter, then the Z and enter, each between 0 and 1):";
        checkCin<float, ALL_INDEXES>(albedo, "Invalid albedo, please enter a valid albedo for the albedo ", []([[maybe_unused]]float ex) { return ex >= 0 && ex <= 1; }, Bonus::A);
        std::cout << "Enter the refraction index of the material (float, between 0 and 1): ";
        checkCin<float>(ref_idx, "Invalid refraction index, please enter a valid refraction index: ", []([[maybe_unused]]float ex) { return ex >= 0 && ex <= 1; });


        std::cout << "Enable texture? (1 for yes, 0 for no): ";
        checkCin<bool>(enable_texture, "Invalid input, please enter a valid input (1 for yes, 0 for no): ", []([[maybe_unused]]bool ex) { return ex == 0 || ex == 1; });
        std::cout << "Enter the scale of the texture (float): ";
        checkCin<double>(scale, "Invalid scale, please enter a valid scale: ", []([[maybe_unused]]double ex) { return ex >= 0; });
        if (enable_texture) {
            std::cout << "Enter the path to the texture of the shape or chessboard: ";
            checkCin<std::string>(path, "Invalid path, please enter a valid path: ", []([[maybe_unused]]std::string ex) { return ex == "chessboard" || std::filesystem::exists(ex); });
            if (path == "chessboard") {
                std::cout << "Enter the color of the first square (first the R and enter, then the G and enter, then the B and enter): ";
                checkCin<int, ALL_INDEXES>(color1, "Invalid color, please enter a valid color for the color ", []([[maybe_unused]]int ex) { return ex >= 0 && ex <= 255; }, Bonus::C);
                std::cout << "Enter the color of the second square (first the R and enter, then the G and enter, then the B and enter): ";
                checkCin<int, ALL_INDEXES>(color2, "Invalid color, please enter a valid color for the color ", []([[maybe_unused]]int ex) { return ex >= 0 && ex <= 255; }, Bonus::C);
            }
        } else {
            path = "none";
        }
        return Bonus::ParsingMaterial(material_type, albedo[Bonus::R], albedo[Bonus::G], albedo[Bonus::B], ref_idx, enable_texture, path, color1[Bonus::R], color1[Bonus::G], color1[Bonus::B], color2[Bonus::R], color2[Bonus::G], color2[Bonus::B], scale);
    } else {
        std::cout << "Enter the color of the light (first the R and enter, then the G and enter, then the B and enter):";
        checkCin<int, ALL_INDEXES>(color, "Invalid color, please enter a valid color for the color ", []([[maybe_unused]]int ex) { return ex >= 0 && ex <= 255; }, Bonus::C);
        std::cout << "Enter the intensity of the light (double): ";
        checkCin<double>(intensity, "Invalid intensity, please enter a valid intensity: ", []([[maybe_unused]]double ex) { return ex >= 0; });


        std::cout << "Enable texture? (1 for yes, 0 for no): ";
        checkCin<bool>(enable_texture, "Invalid input, please enter a valid input (1 for yes, 0 for no): ", []([[maybe_unused]]bool ex) { return ex == 0 || ex == 1; });
        std::cout << "Enter the scale of the texture (float): ";
        checkCin<double>(scale, "Invalid scale, please enter a valid scale: ", []([[maybe_unused]]double ex) { return ex >= 0; });
        if (enable_texture) {
            std::cout << "Enter the path to the texture of the shape or chessboard: ";
            checkCin<std::string>(path, "Invalid path, please enter a valid path: ", []([[maybe_unused]]std::string ex) { return ex == "chessboard" || std::filesystem::exists(ex); });
            if (path == "chessboard") {
                std::cout << "Enter the color of the first square (first the R and enter, then the G and enter, then the B and enter): ";
                checkCin<int, ALL_INDEXES>(color1, "Invalid color, please enter a valid color for the color ", []([[maybe_unused]]int ex) { return ex >= 0 && ex <= 255; }, Bonus::C);
                std::cout << "Enter the color of the second square (first the R and enter, then the G and enter, then the B and enter): ";
                checkCin<int, ALL_INDEXES>(color2, "Invalid color, please enter a valid color for the color ", []([[maybe_unused]]int ex) { return ex >= 0 && ex <= 255; }, Bonus::C);
            }
        } else {
            path = "none";
        }
        return Bonus::ParsingMaterial(material_type, intensity, color[Bonus::R], color[Bonus::G], color[Bonus::B], enable_texture, path, color1[Bonus::R], color1[Bonus::G], color1[Bonus::B], color2[Bonus::R], color2[Bonus::G], color2[Bonus::B], scale);
    }
}

void Bonus::CFGGenerator::askShape()
{
    std::string type;
    bool enable_transformation = false;
    int nb_transformations;
    float position[ALL_INDEXES];
    float size[ALL_INDEXES];
    float radius;
    float normal[ALL_INDEXES];
    float height;
    float angle;
    float max_radius;
    float min_radius;

    std::vector<ParsingTransformation> transformations;
    std::cout << "Enter the type of the shape (sphere, tangle_cube, cylinder, cone, plane, limited_cylinder, limited_cone, parallelepiped, torus): ";
    checkCin<std::string>(type, "Invalid type, please enter a valid type: ", []([[maybe_unused]]std::string ex) { return ex == "sphere" || ex == "tangle_cube" || ex == "cylinder" || ex == "cone" || ex == "plane" || ex == "limited_cylinder" || ex == "limited_cone" || ex == "parallelepiped" || ex == "torus"; });
    std::cout << "Enter the position of the shape (first the X and enter, then the Y and enter, then the Z and enter):";
    checkCin<float, ALL_INDEXES>(position, "Invalid position, please enter a valid position for the position ", []([[maybe_unused]]float ex) { return true; }, A);
    if (type == "sphere") {
        std::cout << "Enter the radius of the sphere (float): ";
        checkCin<float>(radius, "Invalid radius, please enter a valid radius: ", []([[maybe_unused]]float ex) { return ex >= 0; });
    } else if (type == "plane") {
        std::cout << "Enter the normal of the plane (first the X and enter, then the Y and enter, then the Z and enter (float)): ";
        checkCin<float, ALL_INDEXES>(normal, "Invalid normal, please enter a valid normal for the normal ", []([[maybe_unused]]float ex) { return true; }, A);
    } else if (type == "limited_cylinder") {
        std::cout << "Enter the radius of the limited_cylinder (float): ";
        checkCin<float>(radius, "Invalid radius, please enter a valid radius: ", []([[maybe_unused]]float ex) { return ex >= 0; });
        std::cout << "Enter the height of the limited_cylinder (float): ";
        checkCin<float>(height, "Invalid height, please enter a valid height: ", []([[maybe_unused]]float ex) { return ex >= 0; });
    } else if (type == "cylinder") {
        std::cout << "Enter the radius of the cylinder (float): ";
        checkCin<float>(radius, "Invalid radius, please enter a valid radius: ", []([[maybe_unused]]float ex) { return ex >= 0; });
    } else if (type == "cone") {
        std::cout << "Enter the angle of the cone (float): ";
        checkCin<float>(angle, "Invalid angle, please enter a valid angle: ", []([[maybe_unused]]float ex) { return ex >= 0; });
    } else if (type == "limited_cone") {
        std::cout << "Enter the angle of the limited_cone (float): ";
        checkCin<float>(angle, "Invalid angle, please enter a valid angle: ", []([[maybe_unused]]float ex) { return ex >= 0; });
        std::cout << "Enter the height of the limited_cone (float): ";
        checkCin<float>(height, "Invalid height, please enter a valid height: ", []([[maybe_unused]]float ex) { return ex >= 0; });
    } else if (type == "parallelepiped") {
        std::cout << "Enter the size of the parallelepiped (first the X and enter, then the Y and enter, then the Z and enter): ";
        checkCin<float, ALL_INDEXES>(size, "Invalid size, please enter a valid size for the size ", []([[maybe_unused]]float ex) { return ex >= 0; }, A);
    } else if (type == "torus") {
        std::cout << "Enter the max radius of the torus (float): ";
        checkCin<float>(max_radius, "Invalid max radius, please enter a valid max radius: ", []([[maybe_unused]]float ex) { return ex >= 0; });
        std::cout << "Enter the min radius of the torus (float): ";
        checkCin<float>(min_radius, "Invalid min radius, please enter a valid min radius: ", []([[maybe_unused]]float ex) { return ex >= 0; });
    }
    std::cout << "Enable transformations? (1 for yes, 0 for no): ";
    checkCin<bool>(enable_transformation, "Invalid input, please enter a valid input (1 for yes, 0 for no): ", []([[maybe_unused]]bool ex) { return ex == 0 || ex == 1; });
    if (enable_transformation) {
        std::cout << "Enter the number of transformations (int): ";
        checkCin<int>(nb_transformations, "Invalid number of transformations, please enter a valid number of transformations: ", []([[maybe_unused]]int ex) { return ex > 0; });
        for (int i = 0; i < nb_transformations; i++)
            transformations.push_back(askTransformation());
    }
    if (type == "sphere") {
        ParsingShape new_shape(type, position[X], position[Y], position[Z], 0, 0, 0, radius,
        0, 0, 0, 0, 0, 0, 0, 0, askMaterial(), transformations);
        _shapes.push_back(new_shape);
    } else if (type == "plane") {
        ParsingShape new_shape(type, position[X], position[Y], position[Z], 0, 0, 0, 0,
        normal[X], normal[Y], normal[Z], 0, 0, 0, 0, 0, askMaterial(), transformations);
        _shapes.push_back(new_shape);
    } else if (type == "limited_cylinder") {
        ParsingShape new_shape(type, position[X], position[Y], position[Z], 0, 0, 0, radius,
        0, 0, 0, 0, height, 0, 0, 0, askMaterial(), transformations);
        _shapes.push_back(new_shape);
    } else if (type == "cylinder") {
        ParsingShape new_shape(type, position[X], position[Y], position[Z], 0, 0, 0, radius,
        0, 0, 0, 0, 0, 0, 0, 0, askMaterial(), transformations);
        _shapes.push_back(new_shape);
    } else if (type == "cone") {
        ParsingShape new_shape(type, position[X], position[Y], position[Z], 0, 0, 0, 0,
        0, 0, 0, angle, 0, 0, 0, 0, askMaterial(), transformations);
        _shapes.push_back(new_shape);
    } else if (type == "limited_cone") {
        ParsingShape new_shape(type, position[X], position[Y], position[Z], 0, 0, 0, 0,
        0, 0, 0, angle, height, 0, 0, 0, askMaterial(), transformations);
        _shapes.push_back(new_shape);
    } else if (type == "parallelepiped") {
        ParsingShape new_shape(type, position[X], position[Y], position[Z], size[X], size[Y], size[Z], 0,
        0, 0, 0, 0, 0, 0, 0, 0, askMaterial(), transformations);
        _shapes.push_back(new_shape);
    } else if (type == "torus") {
        ParsingShape new_shape(type, position[X], position[Y], position[Z], 0, 0, 0, 0,
        0, 0, 0, 0, 0, max_radius, min_radius, 0, askMaterial(), transformations);
        _shapes.push_back(new_shape);
    }
}

void Bonus::CFGGenerator::askCamera()
{
    float view_from[ALL_INDEXES];
    float view_at[ALL_INDEXES];
    float view_up[ALL_INDEXES];
    float rotation[ALL_INDEXES];
    float fov;
    float aperture;
    float focus_dist;
    int resolution[RESO_INDEX];
    std::cout << "Enter the position of the camera (first the X and enter, then the Y and enter, then the Z and enter): ";
    checkCin<float, ALL_INDEXES>(view_from, "Invalid view_from, please enter a valid integer for the position ", []([[maybe_unused]]float ex) { return true; }, A);
    std::cout << "Enter the point the camera is looking at (first the X and enter, then the Y and enter, then the Z and enter): ";
    checkCin<float, ALL_INDEXES>(view_at, "Invalid view_at, please enter a valid integer for the position ", []([[maybe_unused]]float ex) { return true; }, A);
    std::cout << "Enter the up vector of the camera (first the X and enter, then the Y and enter, then the Z and enter): ";
    checkCin<float, ALL_INDEXES>(view_up, "Invalid view_up, please enter a valid integer for the position ", []([[maybe_unused]]float ex) { return true; }, A);
    std::cout << "Enter the rotation of the camera (first the X and enter, then the Y and enter, then the Z and enter): ";
    checkCin<float, ALL_INDEXES>(rotation, "Invalid rotation, please enter a valid integer for the rotation ", []([[maybe_unused]]float ex) { return true; }, A);
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
    checkCin<int>(samples, "Invalid number of samples, please enter a valid number of samples: ", []([[maybe_unused]]int ex) { return ex >= 0; });
    std::cout << "Enter the number of bounces (int): ";
    checkCin<int>(number_of_bounces, "Invalid number of bounces, please enter a valid number of bounces: ", []([[maybe_unused]]int ex) { return ex >= 0; });
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
    float value[ALL_INDEXES];
    std::cout << "Enter the type of the transformation (translation, rotation, scale, shear): ";
    checkCin<std::string>(type, "Invalid type of transformation, please enter a valid type: ", []([[maybe_unused]]std::string ex) { return ex == "translation" || ex == "rotation" || ex == "scale" || ex == "shear"; });
    std::cout << "Enter the values of the transformation (first the X and enter, then the Y and enter, then the Z and enter): ";
    checkCin<float, ALL_INDEXES>(value, "Invalid values, please enter a valid value for the values ", []([[maybe_unused]]float ex) { return ex >= 0; }, A);
    return ParsingTransformation(type, value[X], value[Y], value[Z]);
}
