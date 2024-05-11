/**
 * @file DLLoader.hpp
 * @brief This file defines the DLLoader class.
 *
 * This class is used to load dynamic libraries and get instances of classes from them.
 */

/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** No file there, just an epitech header example.
*/

#pragma once

#include <utility>
#include <dlfcn.h>
#include <functional>
#include <memory>
#include <iostream>
#include "Interfaces/IError.hpp"
#include "Interfaces/IShape.hpp"
#include "Interfaces/IMaterial.hpp"
#include "Interfaces/ITransformation.hpp"

namespace Core {

    /**
     * @class DLLoader
     * @brief DLLoader class
     *
     * This class is used to load dynamic libraries and get instances of classes from them.
     */
    class DLLoader {
    public :
        /**
         * @defgroup DLLoader Exceptions
         * @brief Exceptions for DLLoader
         * @{
         */

        /**
         * @class dlException
         * @brief Exception class for dynamic library errors
         *
         * This class is used to throw exceptions when a dynamic library error occurs.
         */
        class dlException : public AError {
        public :
            /**
             * @brief Constructor for dlException
             *
             * The message for the exception is obtained from the dynamic library error.
             */
            dlException() : AError(dlerror()) {};
        };

        /**
         * @class TypeException
         * @brief Exception class for invalid type errors
         *
         * This class is used to throw exceptions when an invalid type is encountered.
         */
        class TypeException : public AError {
        public :
            /**
             * @brief Constructor for TypeException
             *
             * The message for the exception is "Invalid type".
             */
            TypeException() : AError("Invalid type") {}
        };

        /**
         * @}
         */

        /**
         * @brief Constructor for DLLoader
         *
         * Initializes the library pointer to nullptr.
         */
        DLLoader() : lib(nullptr) {}

        /**
         * @brief Destructor for DLLoader
         *
         * Closes the dynamic library if it is open.
         */
        ~DLLoader()
        {
            if (lib != nullptr && dlclose(lib) != 0)
                std::cerr << dlerror() << std::endl;
        }

        /**
         * @brief Load a dynamic library
         *
         * @param path The path to the dynamic library.
         *
         * If a library is already open, it is closed. Then, the new library is opened.
         * If an error occurs while opening the library, a dlException is thrown.
         */
        void loadLib(const std::string path) {
            if (lib != nullptr && dlclose(lib) != 0)
                std::cerr << dlerror() << std::endl;
            lib = dlopen(path.c_str(), RTLD_LAZY);
            if (!lib)
                throw dlException();
        }

        /**
         * @brief Get an instance of a class from the dynamic library
         *
         * @tparam T The type of the class.
         * @param type The name of the function to call to get the instance.
         *
         * If the type is not "loadGameInstance" or "loadGraphicInstance", a TypeException is thrown.
         * If the function cannot be found in the library, nullptr is returned.
         * Otherwise, the function is called and the result is returned.
         */
        template <typename T>
        T *getInstance() {
            T *(*sym)() = reinterpret_cast<T *(*)()>(dlsym(lib, "entry_point"));
            if (!sym)
                return nullptr;
            return sym();
        }
    private:
        void *lib;
    };
}