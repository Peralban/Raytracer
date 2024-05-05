/*
** EPITECH PROJECT, 2024
** ClusterManagement.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include <thread>
#include <vector>
#include <memory>
#include <utility>
#include <mutex>
#include <map>

#include "Raytracer/Camera.hpp"
#include "Shapes/ShapeList.hpp"

namespace App {
    /**
     * @class Cluster
     * @brief Represents a cluster of threads for parallel processing.
     */
    class Cluster {
        public:
            /**
             * @brief Construct a new Cluster object.
             * @param startY The starting Y-coordinate for this cluster.
             * @param endY The ending Y-coordinate for this cluster.
             * @param id The unique identifier for this cluster.
             */
            Cluster(unsigned int startY, unsigned int endY, int id);
            ~Cluster() = default;

            // Getters
            /**
             * @brief Get the Y-axis range for this cluster.
             * @return A pair of unsigned integers representing the start and end Y-coordinates.
             */
            std::pair<unsigned int, unsigned int> getAxesY() const { return _axesY; }

            /**
             * @brief The thread associated with this cluster.
             */
            std::thread thread;

            /**
             * @brief Get the unique identifier for this cluster.
             * @return The unique identifier as an integer.
             */
            int getId() const { return id; }
        private:
            int id;
            std::pair<unsigned int, unsigned int> _axesY;
    };

    /**
     * @class ClusterManagement
     * @brief Manages a collection of Cluster objects for parallel processing.
     */
    class ClusterManagement {
        public:
            /**
             * @brief Construct a new ClusterManagement object.
             * @param width The width of the window. Default is 1920.
             * @param height The height of the window. Default is 1080.
             */
            ClusterManagement(int width = 1920, int height = 1080);
            ~ClusterManagement();

            /**
             * @brief Execute the rendering process across all clusters.
             * @param scene The scene to be rendered.
             * @param camera The camera used for rendering.
             */
            void executeRendering(std::shared_ptr<RayTracer::ShapeList> scene, std::shared_ptr<RayTracer::Camera> camera);

        // Getters
            /**
            * @brief Get the number of threads.
            * @return The number of threads as an unsigned integer.
            */
            unsigned int getNbThreads() const { return _nbThreads; }

            /**
             * @brief Get the window width.
             * @return The window width as an unsigned integer.
             */
            unsigned int getWindowWidth() const { return _windowWidth; }

            /**
             * @brief Get the window height.
             * @return The window height as an unsigned integer.
             */
            unsigned int getWindowHeight() const { return _windowHeight; }

            /**
             * @brief Get the window size.
             * @return A pair of unsigned integers representing the window width and height.
             */
            std::pair<unsigned int, unsigned int> getWindowsSize() const { return std::make_pair(_windowWidth, _windowHeight); }

            /**
             * @brief Get the clusters.
             * @return A vector of shared pointers to the Cluster objects.
             */
            std::vector<std::shared_ptr<Cluster>> getClusters() const { return _clusters; }

            /**
             * @brief Get the sample.
             * @return The sample as an integer.
             */
            int getSample() const { return _sample; }

            /**
             * @brief Get the configuration.
             * @return A vector of pairs, each containing a pair of unsigned integers and a string.
             */
            std::vector<std::pair<std::pair<unsigned int, unsigned int>, std::string>> getConfig() const { return _config; }

            /**
             * @brief Get the configuration as a map.
             * @return A map of pairs, each containing a pair of unsigned integers and a string.
             * @param filename The name of the file to be printed.
             */
            void createPPMFile(std::string filename = "output.ppm");

        // Sorter
            /**
             * @brief Sort the configuration based on the pair of unsigned integers in ascending order.
             */
            void sortConfig();

            /**
             * @brief Mutex for thread safety.
             */
            std::mutex mtx;
        private:
        // Rendering
            /**
             * @brief Render the scene.
             * @param _axesY The Y-axis range.
             * @param width The width of the window.
             * @param height The height of the window.
             * @param samples The number of samples.
             * @param scene The scene to be rendered.
             * @param camera The camera used for rendering.
             * @param x The X-coordinate.
             */
            void render(std::pair<unsigned int, unsigned int> _axesY, int width, int height, int samples, std::shared_ptr<RayTracer::ShapeList> scene, std::shared_ptr<RayTracer::Camera> camera, int x);
            /**
             * @brief The number of threads, window width, window height, and sample.
             * In volatile mode to prevent compiler optimization.
             */
            volatile unsigned int _nbThreads;
            volatile unsigned int _windowWidth;
            volatile unsigned int _windowHeight;
            volatile int _sample;
            std::vector<std::shared_ptr<Cluster>> _clusters;
            std::vector<std::pair<std::pair<unsigned int, unsigned int>, std::string>> _config;
    };
}
