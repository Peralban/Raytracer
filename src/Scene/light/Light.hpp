/*
** EPITECH PROJECT, 2024
** Light.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include <string>
#include <vector>

class Light {
public:
    int intensity;
    std::vector<int> color;
    std::vector<int> rotation;

    Light();
    ~Light();
};
