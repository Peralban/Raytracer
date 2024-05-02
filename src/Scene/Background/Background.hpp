/*
** EPITECH PROJECT, 2024
** Background.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include <string>
#include <vector>

class Background {
public:
    std::vector<int> color;
    std::string texture_path;

    Background();
    ~Background();
};
