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
#include "Transformations/Translation.hpp"
#include "Transformations/Rotation.hpp"
#include "Transformations/Scale.hpp"

int main()
{
    int width = 1920;
    int height = 1080;
    std::shared_ptr<RayTracer::ShapeList> scene = std::make_shared<RayTracer::ShapeList>();
    scene->shapes.push_back(std::make_shared<RayTracer::Sphere>(Math::Vector3D{0, 0, 0}, 2., new RayTracer::Metal(Math::Vector3D(0.8, 0.3, 0.3), 0.3)));
    scene->shapes.push_back(std::make_shared<RayTracer::Sphere>(Math::Vector3D{0, 0, 10}, 2., new RayTracer::Matte(Math::Vector3D(0.8, 0.8, 0.0))));
    scene->shapes.push_back(std::make_shared<RayTracer::Sphere>(Math::Vector3D{10, 0, 0}, 4., new RayTracer::Metal(Math::Vector3D(0.8, 0.6, 0.2), 0.1)));
    scene->shapes.push_back(std::make_shared<RayTracer::Sphere>(Math::Vector3D{10, 0, 10}, 2., new RayTracer::Metal(Math::Vector3D(0.6, 0.3, 0.5), 1.0)));

    scene->shapes.push_back(
        std::make_shared<RayTracer::TransformedShape>(
            std::make_unique<RayTracer::Sphere>(
                Math::Vector3D(0, 0, 20),
                2.,
                new RayTracer::Matte(Math::Vector3D(0.8, 0.8, 0.0))
            ),
            std::make_unique<RayTracer::Rotation>(
                Math::Vector3D(0., 1.57, 0.)
            )
        )
    );
    scene->shapes.push_back(
        std::make_shared<RayTracer::TransformedShape>(
            std::make_unique<RayTracer::Sphere>(
                Math::Vector3D(10, 0, 10),
                2.,
                new RayTracer::Metal(Math::Vector3D(0.1, 1., 0.2), 0.1)
            ),
            std::make_unique<RayTracer::Scale>(
                Math::Vector3D(2, 2, 2)
            )
        )
    );
    std::shared_ptr<RayTracer::Camera> camera = std::make_shared<RayTracer::Camera>(Math::Vector3D(5, 20, -10), Math::Vector3D(5, 0, 5), Math::Vector3D(0, 1, 0), 90, double(width) / double(height), 0, 10.0);
    App::ClusterManagement clusterManagement(width, height);
    clusterManagement.executeRendering(scene, camera);
    clusterManagement.sortConfig();
    clusterManagement.createPPMFile();
    clusterManagement.initSDL();
    clusterManagement.printSDL();
    return 0;
}
