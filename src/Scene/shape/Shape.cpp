/*
** EPITECH PROJECT, 2024
** Shape.cpp
** File description:
** Shape
*/

#include "Shape.hpp"

Shape::Shape()
{
    this->type = "";
    this->color = {0, 0, 0};
    this->size = {0, 0, 0};
    this->texture_path = "";
    this->transformations = {};
}

Shape::~Shape()
{
}
