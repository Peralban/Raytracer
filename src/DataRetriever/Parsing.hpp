/*
** EPITECH PROJECT, 2024
** Parsing.hpp
** File description:
** DESCRIPTION
*/

/**
 * @file Parsing.hpp
 * @brief Defines the Parsing class and its nested exception classes.
 */

#pragma once

#include "Interfaces/IError.hpp"
#include <libconfig.h++>

namespace App {
    /**
     * @class Parsing
     * @brief A class for parsing command line arguments.
     *
     * This class provides functionality for checking the validity of command line arguments.
     * It also defines several nested exception classes for handling specific types of parsing errors.
     */
    class Parsing {
    public:
        /**
         * @class TooManyArguments
         * @brief Exception class for handling too many arguments error.
         *
         * This class is used to throw and handle exceptions when too many command line arguments are provided.
         */
        class ErrorTooManyArguments : public AError {
        public:
            /**
             * @brief Display an error message.
             * @param message The error message to display. Defaults to "Too many arguments".
             */
            ErrorTooManyArguments() : AError("Too many arguments") {}
        };

        /**
         * @class TooFewArguments
         * @brief Exception class for handling too few arguments error.
         *
         * This class is used to throw and handle exceptions when too few command line arguments are provided.
         */
        class ErrorTooFewArguments : public AError {
        public:
            /**
             * @brief Display an error message.
             * @param message The error message to display. Defaults to "Too few arguments".
             */
            ErrorTooFewArguments() : AError("Too few arguments") {}
        };

        /**
         * @class InvalidArgument
         * @brief Exception class for handling invalid argument error.
         *
         * This class is used to throw and handle exceptions when an invalid command line argument is provided.
         */
        class ErrorCFGFile : public AError {
        public:
            /**
             * @brief Display an error message.
             * @param message The error message to display. Defaults to "Error in treatment of the configuration file".
             */
            ErrorCFGFile() : AError("Error in treatment of the configuration file") {}
        };

        class ErrorInvalidType : public AError {
        public:
            /**
             * @brief Display an error message.
             * @param message The error message to display. Defaults to "Invalid type of file".
             */
            ErrorInvalidType() : AError("Invalid type of file") {}
        };

        class ErrorNoCFGFile : public AError {
        public:
            /**
             * @brief Display an error message.
             * @param message The error message to display. Defaults to "Invalid type of file".
             */
            ErrorNoCFGFile() : AError("CFG file not found") {}
        };

        /**
         * @brief Default constructor for the Parsing class.
         */
        Parsing() = default;

        /**
         * @brief Default destructor for the Parsing class.
         */
        ~Parsing() = default;

        /**
         * @brief Check the validity of command line arguments. Throws an exception if the arguments are invalid.
         * or complete _configFile with the path to the configuration file.
         * @param ac The number of command line arguments.
         * @param av The array of command line arguments.
         * @throws TooManyArguments if too many arguments are provided. @see TooManyArguments
         * @throws TooFewArguments if too few arguments are provided. @see TooFewArguments
         * @throws InvalidArgument if an invalid argument is provided. @see InvalidArgument
         */
        void checkArguments(int ac, char **av);

        /**
         * @brief Get the path to the configuration file.
         * @return The path to the configuration file.
         */
        std::string getConfigFile() { return _configFile; }
    private:
        /**
         * @brief The path to the configuration file.
         */
        std::string _configFile;
    };
}