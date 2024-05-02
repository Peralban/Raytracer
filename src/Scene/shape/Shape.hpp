/*
** EPITECH PROJECT, 2024
** Shape.hpp
** File description:
** Shape
*/

#pragma once
#include <string>
#include <vector>
#include "Transformation.hpp"

class Shape {
public:
    std::string type;
    std::vector<int> size;
    std::vector<int> color;
    std::vector<Transformation> transformations;
    std::string texture_path;

    Shape();
    ~Shape();
};
