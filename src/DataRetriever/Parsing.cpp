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


void App::Parsing::checkArguments(int ac, char **av) {
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
