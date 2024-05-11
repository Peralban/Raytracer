/*
** EPITECH PROJECT, 2024
** Core.cpp
** File description:
** Create the scene and camera, and render the scene.
*/

/**
 * @file Core.cpp
 * @brief Core class implementation.
 * @see Core.hpp
 */

#include "Core.hpp"

namespace Core {

    Engine::Engine(int argc, char **argv) : _parser(), _factory(), _clusterManagement(2160, 1080) {
        try {
            _parser.checkArguments(argc, argv);
            initialize();
        } catch (const std::exception &e) {
            if (std::string(e.what()) == "Too many arguments")
                throw App::Parsing::ErrorTooManyArguments();
            if (std::string(e.what()) == "Too few arguments")
                throw App::Parsing::ErrorTooFewArguments();
            if (std::string(e.what()) == "Error in treatment of the configuration file")
                throw App::Parsing::ErrorCFGFile();
            if (std::string(e.what()) == "Invalid type of file")
                throw App::Parsing::ErrorInvalidType();
            if (std::string(e.what()) == "CFG file not found")
                throw App::Parsing::ErrorNoCFGFile();
        }
    }

    void Engine::run() {
        render();
        finalize();
    }

    void Engine::initialize() {
        parseConfigFile();
        createScene();
        createCamera();
    }

    void Engine::parseConfigFile() {
        _parser.parseConfigFile();
        std::cout << _parser << std::endl;
        _clusterManagement.setSample(_parser.getPrecision().getSamples());
        unsigned int width = _parser.getCamera().getResolution().first;
        unsigned int height = _parser.getCamera().getResolution().second;
        _clusterManagement.setWindowSize(width, height);
        _clusterManagement.setColor(_parser.getBackground().getColor());
    }

    void Engine::createScene() {
        _scene = std::make_shared<RayTracer::ShapeList>();
        for (const auto& shapeData : _parser.getShapes()) {
            try {
                auto shape = _factory.createPrimitive(shapeData);
                _scene->shapes.push_back(shape);
            } catch (const std::exception &e) {
                std::cerr << e.what() << std::endl;
                exit(84);
            }
        }
    }

    void Engine::createCamera() {
        auto cameraData = _parser.getCamera();
        _camera = _factory.createCamera(cameraData);
    }

    void Engine::render() {
        _clusterManagement.executeRendering(_scene, _camera);
        _clusterManagement.sortConfig();
        _clusterManagement.createPPMFile();
        _clusterManagement.initSDL();
        _clusterManagement.printSDL();
    }

    void Engine::finalize() {}
}
