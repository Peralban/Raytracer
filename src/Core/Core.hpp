#pragma once

#include "ClusterManagement.hpp"
#include "Factory/Factory.hpp"
#include "DataRetriever/Parsing.hpp"
#include <iostream>

/**
 * @brief The main namespace of the application.
 */
namespace Core {

    /**
     * @brief The main engine of the application responsible for coordinating different components.
     */
    class Engine {
    public:
        /**
         * @brief Constructs an Engine object.
         * @param argc The number of command-line arguments.
         * @param argv The array of command-line arguments.
         */
        Engine(int argc, char **argv);

        /**
         * @brief Runs the engine to execute the application.
         */
        void run();

    private:
        /**
         * @brief Initializes the engine.
         */
        void initialize();

        /**
         * @brief Parses the configuration file.
         */
        void parseConfigFile();

        /**
         * @brief Creates the scene based on the parsed configuration.
         */
        void createScene();

        /**
         * @brief Creates the camera based on the parsed configuration.
         */
        void createCamera();

        /**
         * @brief Renders the scene using the camera.
         */
        void render();

        /**
         * @brief Finalizes and cleans up the engine.
         */
        void finalize();

        App::Parsing _parser;
        Factory::SceneFactory _factory;
        std::shared_ptr<RayTracer::ShapeList> _scene;
        std::shared_ptr<RayTracer::Camera> _camera;
        App::ClusterManagement _clusterManagement;
    };
}
