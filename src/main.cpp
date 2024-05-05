/*
** EPITECH PROJECT, 2024
** main.cpp
** File description:
** DESCRIPTION
*/

#include "Core/ClusterManagement.hpp"
#include "Math/Vector3D.hpp"
#include "Raytracer/Camera.hpp"
#include "Shapes/ShapeList.hpp"
#include "Shapes/Sphere.hpp"
#include "Shapes/Material.hpp"

int main()
{
    int width = 1000;
    int height = 500;
    std::shared_ptr<RayTracer::ShapeList> scene = std::make_shared<RayTracer::ShapeList>();
    scene->_shapes.push_back(std::make_shared<RayTracer::Sphere>(Math::Vector3D(0, 0, -1), 0.5, new RayTracer::Matte(Math::Vector3D(0.1, 0.2, 0.5))));
    scene->_shapes.push_back(std::make_shared<RayTracer::Sphere>(Math::Vector3D(0, -100.5, -1), 100, new RayTracer::Metal(Math::Vector3D(0.8, 0.8, 0.0), 0.0)));
    scene->_shapes.push_back(std::make_shared<RayTracer::Sphere>(Math::Vector3D(0.7, -0.3, -0.7), 0.2, new RayTracer::Metal(Math::Vector3D(0.8, 0.6, 0.2), 0.1)));
    scene->_shapes.push_back(std::make_shared<RayTracer::Sphere>(Math::Vector3D(-1, 0, -1), 0.4, new RayTracer::Metal(Math::Vector3D(0.6, 0.3, 0.5), 1.0)));
    std::shared_ptr<RayTracer::Camera> camera = std::make_shared<RayTracer::Camera>();

    App::ClusterManagement clusterManagement(width, height);
    clusterManagement.executeRendering(scene, camera);
    clusterManagement.sortConfig();
    clusterManagement.createPPMFile();
    clusterManagement.initSDL();
    clusterManagement.printSDL();
    return 0;
}
