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
#include "Shapes/TransformedShape.hpp"
#include "Materials/LightDirectional.hpp"
#include "Transformations/Translation.hpp"
#include "Transformations/Rotation.hpp"
#include "Transformations/Scale.hpp"
#include "Transformations/Shear.hpp"
#include "Shapes/Torus.hpp"
#include "Shapes/Plane.hpp"
#include "Textures/SolidColor.hpp"


int main()
{
    int width = 2160;
    int height = 1080;
    std::shared_ptr<RayTracer::ShapeList> scene = std::make_shared<RayTracer::ShapeList>();
    scene->shapes.push_back(std::make_shared<RayTracer::Sphere>(Math::Vector3D(0, 0, -1), 0.5, std::make_shared<RayTracer::Metal>(std::make_shared<RayTracer::SolidColor>(Math::Vector3D(0.8, 0.0, 0.0)), 1.0)));
    scene->shapes.push_back(std::make_shared<RayTracer::Plane>(Math::Vector3D(0.0, -100.5, 100.0), Math::Vector3D(0.0, 1.0, 0.0), std::make_shared<RayTracer::Matte>(std::make_shared<RayTracer::SolidColor>(Math::Vector3D(0.8, 0.8, 0.8)))));
    scene->shapes.push_back(std::make_shared<RayTracer::Sphere>(Math::Vector3D(0.7, -0.3, -0.0), 1.0, std::make_shared<RayTracer::LightDirectional>(std::make_shared<RayTracer::SolidColor>(Math::Vector3D(9, 9, 9)))));
    scene->shapes.push_back(std::make_shared<RayTracer::Sphere>(Math::Vector3D(-1, 0, -1), 0.4, std::make_shared<RayTracer::Matte>(std::make_shared<RayTracer::SolidColor>(Math::Vector3D(0.8, 0.8, 0.0)))));

    std::shared_ptr<RayTracer::Camera> camera = std::make_shared<RayTracer::Camera>(Math::Vector3D(-2, 2, 1), Math::Vector3D(0, 0, -1), Math::Vector3D(0, 1, 0), 45, double(width) / double(height), 0, 10.0);
    App::ClusterManagement clusterManagement(width, height);
    clusterManagement.executeRendering(scene, camera);
    clusterManagement.sortConfig();
    clusterManagement.createPPMFile();
    clusterManagement.initSDL();
    clusterManagement.printSDL();
    return 0;
}
