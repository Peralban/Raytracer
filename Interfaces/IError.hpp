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
        const char *what() const noexcept override = 0;
};

class AError : public IError {
    public:
       AError(const std::string &message) : _message(message) {}
       const char *what() const noexcept override { return _message.c_str(); }
    private:
        std::string _message;
};
