


#include "Graphical/Sdl2.hpp"
#include "Math/Vector3D.hpp"
#include "Math/Ray3D.hpp"
#include "Raytracer/Camera.hpp"
#include "Shapes/ShapeList.hpp"
#include "Shapes/Sphere.hpp"
#include "Materials/Metal.hpp"
#include "Materials/Matte.hpp"
#include "Materials/Glass.hpp"
#include <thread>
#include <vector>

Math::Vector3D color (const Math::Ray3D &ray, RayTracer::IShape *scene, int depth)
{
    RayTracer::hits  hit;
    if (scene->hit(ray, 0.001, 10000.0, hit))
    {
        Math::Ray3D scattered;
        Math::Vector3D attenuation;
        if (depth < 50 && hit.material->scatter(ray, hit, attenuation, scattered))
        {
            return attenuation * color(scattered, scene, depth + 1);
        } else {
            return Math::Vector3D(0, 0, 0);
        }
    } else {
        Math::Vector3D unitDirection = ray.getDirection().getUnitVector();
        float t = 0.5 * (unitDirection.y + 1.0);
        return Math::Vector3D(1.0, 1.0, 1.0) * (1.0 - t) + Math::Vector3D(0.5, 0.7, 1.0) * t;
    }
}

/**
int main()
{
    Sdl sdl;
    sdl.initWindow();
    int width = 400;
    int height = 200;
    int samples = 30;
    std::cout << "P3" << std::endl;
    std::cout  << width << "  " << height << std::endl;
    std::cout << "255" << std::endl;
    RayTracer::ShapeList scene;
    scene._shapes.push_back(std::make_shared<RayTracer::Sphere>(Math::Vector3D(0, 0, -1), 0.5, new RayTracer::Metal(Math::Vector3D(0.8, 0.3, 0.3), 0.0)));
    scene._shapes.push_back(std::make_shared<RayTracer::Sphere>(Math::Vector3D(0, -100.5, -1), 100, new RayTracer::Metal(Math::Vector3D(0.8, 0.8, 0.0), 0.0)));
    scene._shapes.push_back(std::make_shared<RayTracer::Sphere>(Math::Vector3D(0.7, -0.3, -0.7), 0.2, new RayTracer::Metal(Math::Vector3D(0.8, 0.6, 0.2), 0.1)));
    scene._shapes.push_back(std::make_shared<RayTracer::Sphere>(Math::Vector3D(-1, 0, -1), 0.4, new RayTracer::Metal(Math::Vector3D(0.6, 0.3, 0.5), 1.0)));
    RayTracer::Camera camera;
    for (int y = height - 1; y >= 0; y--) {
        for (int x = 0; x < width; x++) {
            Math::Vector3D col(0, 0, 0);
            for (int s = 0; s < samples; s++) {
                float u = float(x + drand48()) / float(width);
                float v = float(y + drand48()) / float(height);
                Math::Ray3D ray = camera.getRay(u, v);
                Math::Vector3D p = ray.pointOnRay(2.0);
                col += color(ray, &scene, 0);
            }
            col /= float(samples);
            col = Math::Vector3D(sqrt(col.x), sqrt(col.y), sqrt(col.z));
            unsigned char r = (unsigned char) (255.99 * col.x);
            unsigned char g = (unsigned char) (255.99 * col.y);
            unsigned char b = (unsigned char) (255.99 * col.z);
            //sdl.drawPoint(x, height-y, r, g, b);
           std::cout << (int)r << " " << (int)g << " " << (int)b << std::endl;
        }
    }

    return 0;
    while (sdl.isRunning())
    {
        sdl.startRendering();
        sdl.stopRendering();
    }

    sdl.closeWindow();
    return 0;
}
*/

/**

#include <thread>
#include <vector>
#include <mutex>

std::mutex mtx;
void drawPoints(int startY, int endY, Sdl &sdl) {
    for (int y = startY; y < endY; ++y) {
        mtx.lock();
        for (int x = 0; x < 6400; ++x) {
            unsigned char r = (unsigned char) (255.99 * (float)x / 400);
            unsigned char g = (unsigned char) (255.99 * (float)y / 200);
            unsigned char b = (unsigned char) (255.99 * 0.2);
            sdl.drawPoint(x, y, sdl.createColor(r, g, b, 255));
        }
        mtx.unlock();
    }
}

int main () {
    Sdl sdl;
    sdl.initWindow();
    int width = 6400;
    int height = 3200;

    int numThreads = 1; // Limit the number of threads to the number of cores
    std::vector<std::thread> threads(numThreads);
    int range = height / numThreads;

    for (int i = 0; i < numThreads; ++i) {
        int startY = i * range;
        int endY = (i == numThreads - 1) ? height : startY + range;
        threads[i] = std::thread(drawPoints, startY, endY, std::ref(sdl));
    }

    for (int i = 0; i < numThreads; ++i)
        threads[i].join();

    return 0;
    while (sdl.isRunning())
    {
        sdl.startRendering();
        sdl.stopRendering();
    }
    sdl.closeWindow();
}
*/


#include <thread>
#include <vector>
#include <mutex>
#include <future>
std::mutex mtx;

thread_local int threadId = 0;

void render(int startY, int endY, int width, int samples, RayTracer::ShapeList& scene, RayTracer::Camera& camera, Sdl& sdl, int x) {
    for (int y = startY; y <=  endY; y++) {
        Math::Vector3D col(0, 0, 0);
        for (int s = 0; s < samples; s++) {
            float u = float(x + drand48()) / float(width);
            float v = float(y + drand48()) / float(1080);
            Math::Ray3D ray = camera.getRay(u, v);
            Math::Vector3D p = ray.pointOnRay(2.0);
            col += color(ray, &scene, 0);
        }
        col /= float(samples);
        col = Math::Vector3D(sqrt(col.x), sqrt(col.y), sqrt(col.z));
        unsigned char r = (unsigned char) (255.99 * col.x);
        unsigned char g = (unsigned char) (255.99 * col.y);
        unsigned char b = (unsigned char) (255.99 * col.z);
        mtx.lock();
        sdl.drawPoint(x, 1080-y, r, g, b);
        mtx.unlock();
    }
    threadId++;
}

int main()
{
    Sdl sdl;
    sdl.initWindow();
    int width = 2160;
    int height = 1080;
    int samples = 15;
    std::cout << "P3" << std::endl;
    std::cout  << width << "  " << height << std::endl;
    std::cout << "255" << std::endl;
    RayTracer::ShapeList scene;
    scene._shapes.push_back(std::make_shared<RayTracer::Sphere>(Math::Vector3D(0, 0, -1), 0.5, new RayTracer::Glass(1.630, Math::Vector3D(1, 1, 1))));
    scene._shapes.push_back(std::make_shared<RayTracer::Sphere>(Math::Vector3D(0, -100.5, -1), 100, new RayTracer::Matte(Math::Vector3D(0.8, 0.8, 0.0))));
    scene._shapes.push_back(std::make_shared<RayTracer::Sphere>(Math::Vector3D(00, 0.2, -2.5), 0.5, new RayTracer::Matte(Math::Vector3D(0.8, 0.6, 0.2))));
    RayTracer::Camera camera;

    int numThreads = std::thread::hardware_concurrency();
    std::vector<std::future<void>> futures(numThreads);
    int range = height / numThreads;

    for (int i = 0; i < width ; i++) {
        for (int j = 0; j < numThreads; ++j) {
            int startY = j * range;
            int endY = (j == numThreads - 1) ? height : startY + range;
            futures[j] = std::async(std::launch::async, render, startY, endY, width, samples, std::ref(scene), std::ref(camera), std::ref(sdl), i);
        }
        for (int j = 0; j < numThreads; ++j)
            futures[j].get();
    }

    while (sdl.isRunning())
    {
        sdl.startRendering();
        sdl.stopRendering();
    }
    sdl.closeWindow();
    return 0;
}
