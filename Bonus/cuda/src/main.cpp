/*
** EPITECH PROJECT, 2024
** main.cpp
** File description:
** DESCRIPTION
*/

#include "Core/Core.hpp"

int main(int argc, char **argv)
{
    try {
        Core::Engine engine(argc, argv);
        engine.run();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
