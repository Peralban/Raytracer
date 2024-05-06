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
#include "Materials/Matte.hpp"
#include "Materials/Metal.hpp"

int main()
{
    int width = 2160;
    int height = 1080;
    std::shared_ptr<RayTracer::ShapeList> scene = std::make_shared<RayTracer::ShapeList>();
    scene->shapes.push_back(std::make_shared<RayTracer::Sphere>(Math::Vector3D(0, 0, -1), 0.5, new RayTracer::Metal(Math::Vector3D(0.8, 0.3, 0.3), 0.3)));
    scene->shapes.push_back(std::make_shared<RayTracer::Sphere>(Math::Vector3D(0.0, -100.5, -1), 100, new RayTracer::Metal(Math::Vector3D(0.8, 0.8, 0.0), 0.0)));
    scene->shapes.push_back(std::make_shared<RayTracer::Sphere>(Math::Vector3D(0.7, -0.3, -0.7), 0.2, new RayTracer::Metal(Math::Vector3D(0.8, 0.6, 0.2), 0.1)));
    scene->shapes.push_back(std::make_shared<RayTracer::Sphere>(Math::Vector3D(-1, 0, -1), 0.4, new RayTracer::Metal(Math::Vector3D(0.6, 0.3, 0.5), 1.0)));
    std::shared_ptr<RayTracer::Camera> camera = std::make_shared<RayTracer::Camera>(Math::Vector3D(-2, 2, 1), Math::Vector3D(0, 0, -1), Math::Vector3D(0, 1, 0), 90, double(width) / double(height), 0, 10.0);

    App::ClusterManagement clusterManagement(width, height);
    clusterManagement.executeRendering(scene, camera);
    clusterManagement.sortConfig();
    clusterManagement.createPPMFile();
    clusterManagement.initSDL();
    clusterManagement.printSDL();
    return 0;
}
