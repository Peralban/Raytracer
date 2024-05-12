/*
** EPITECH PROJECT, 2024
** kernel.cpp
** File description:
** Create the scene and camera, and render the scene.
*/
#include "../Math/Ray3D.hpp"
#include "IShape.hpp"
#include "IMaterial.hpp"
#include <memory>
#include <curand_kernel.h>
#include "kernel.cuh"


struct Coord {
    unsigned int x, y;
};

struct RGB {
    unsigned char r, g, b;
};

static Math::Vector3D color(const Math::Ray3D &ray, RayTracer::IShape *scene, int depth)
{
    RayTracer::hits  hit;
    if (scene->hit(ray, 0.001, 10000.0, hit)) {
        Math::Ray3D scattered;
        Math::Vector3D attenuation;
        if (depth < 50 && hit.material->scatter(ray, hit, attenuation, scattered)) {
            return attenuation * color(scattered, scene, depth + 1);
        } else {
            return {0, 0, 0};
        }
    } else {
        Math::Vector3D unitDirection = ray.getDirection().getUnitVector();
        double t = 0.5 * (unitDirection.y + 1.0);
        return Math::Vector3D(1.0, 1.0, 1.0) * (1.0 - t) + Math::Vector3D(0.5, 0.7, 1.0) * t;
    }
}

__global__ void render(unsigned int _axesY_first, unsigned int _axesY_second, int width, int height, int samples, RayTracer::ShapeList* scene, RayTracer::Camera* camera, int x, Coord* config_coord, RGB* config_rgb, int* threadId, curandState* state){
    int y = blockIdx.x * blockDim.x + threadIdx.x;
    if (y >= _axesY_first && y < _axesY_second) {
        Math::Vector3D col(0, 0, 0);
        for (int s = 0; s < samples; s++) {
            int idx = threadIdx.x + blockIdx.x * blockDim.x;
            float u = float(x + curand_uniform(&state[idx])) / float(width);
            float v = float(y + curand_uniform(&state[idx])) / float(height);
            Math::Ray3D ray = camera->getRay(u, v);
            Math::Vector3D p = ray.pointOnRay(2.0);
            col += color(ray, scene, 0);
        }
        col /= float(samples);
        col = Math::Vector3D(sqrt(col.x), sqrt(col.y), sqrt(col.z));
        unsigned char r = (unsigned char) (255.99 * col.x);
        unsigned char g = (unsigned char) (255.99 * col.y);
        unsigned char b = (unsigned char) (255.99 * col.z);
        config_coord[y].x = x;
        config_coord[y].y = y;
        config_rgb[y].r = r;
        config_rgb[y].g = g;
        config_rgb[y].b = b;
    }
    if (threadIdx.x == 0 && blockIdx.x == 0) {
        (*threadId)++;
    }
}