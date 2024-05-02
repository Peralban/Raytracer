/*
** EPITECH PROJECT, 2024
** Camera.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include <string>
#include <vector>

class Camera {
public:
    std::vector<int> rotation;
    std::vector<int> aspect_ratio;
    int fov;

    Camera();
    ~Camera();
};
