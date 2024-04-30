/*
** EPITECH PROJECT, 2024
** IError.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include <string>
#include <exception>

class IError : public std::exception {
    public:
        virtual ~IError() = default;
        virtual void DisplayError(std::string const message) = 0;
};
