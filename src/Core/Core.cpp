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
            std::cerr << e.what() << std::endl;
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
        _clusterManagement.setSample(_parser.getPrecision().getSamples());
        _clusterManagement.setNbBounces(_parser.getPrecision().getNumberOfBounces());
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
