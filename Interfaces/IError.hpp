/*
** EPITECH PROJECT, 2024
** IError.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include <string>
#include <exception>

/**
 * @class IError
 * @brief An interface for error handling.
 *
 * This class is an interface for error handling. It inherits from the standard exception class.
 */
class IError : public std::exception {
    public:
        /**
         * @brief Virtual destructor.
         */
        virtual ~IError() = default;

        /**
         * @brief Pure virtual function for error message retrieval.
         *
         * This function is a pure virtual function that must be overridden in derived classes.
         * It returns a C-style string representing the error message.
         *
         * @return A C-style string representing the error message.
         */
        const char *what() const noexcept override = 0;
};

/**
 * @class AError
 * @brief A base class for error handling.
 *
 * This class is a base class for error handling. It inherits from the IError interface.
 */
class AError : public IError {
    public:
        /**
         * @brief Constructor.
         *
         * This constructor initializes the error message.
         *
         * @param message The error message.
         */
        AError(const std::string &message) : _message(message) {}

        /**
         * @brief Function for error message retrieval.
         *
         * This function overrides the pure virtual function from the IError interface.
         * It returns a C-style string representing the error message.
         *
         * @return A C-style string representing the error message.
         */
        const char *what() const noexcept override { return _message.c_str(); }

    private:
        /**
         * @brief The error message.
         */
        std::string _message;
};