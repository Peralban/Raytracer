/*
** EPITECH PROJECT, 2024
** Camera.cpp
** File description:
** DESCRIPTION
*/

#include "Camera.hpp"

Camera::Camera()
{
    this->rotation = {0, 0, 0};
    this->aspect_ratio = {1920, 1080};
    this->fov = 90;
}

Camera::~Camera()
{
}
