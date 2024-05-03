


#include "Sdl2.hpp"
#include "Vector3D.hpp"
#include "Sphere.hpp"
#include "ShapeList.hpp"
#include "Camera.hpp"
#include "Material.hpp"
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

void renderSection(int startX, int endX, int startY, int endY, int samples, Sdl& sdl, RayTracer::ShapeList& scene, RayTracer::Camera& camera, std::mutex& mutex)
{
    int width = 400;
    int height = 200;
    (void) sdl;
    (void) mutex;
    for (int y = startY; y < endY; y++) {
        for (int x = startX; x < endX; x++) {
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
            sdl.drawPoint(x, y, r, g, b);
        }
    }
}

#include <mutex>

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
    scene._shapes.push_back(std::make_shared<RayTracer::Sphere>(Math::Vector3D(0.7, -0.3, -0.7), 0.2, new RayTracer::Metal(Math::Vector3D(0.8, 0.6, 0.2), 0.3)));
    scene._shapes.push_back(std::make_shared<RayTracer::Sphere>(Math::Vector3D(-1, 0, -1), 0.4, new RayTracer::Metal(Math::Vector3D(0.6, 0.3, 0.5), 1.0)));
    RayTracer::Camera camera;

    int numThreads = std::thread::hardware_concurrency();
    int sectionHeight = height / numThreads;
    int sectionWidth = width / numThreads;
    // mutex initialisation
    std::vector<std::thread> threads(numThreads);

    std::mutex mutex;

    std::cout << "Num threads: " << numThreads << std::endl;

    for (int i = 0; i < numThreads; i++) {
        std::cerr << "Thread finished" << std::endl;
        threads[i] = std::thread(renderSection, i * sectionWidth, (i + 1) * sectionWidth, i * sectionHeight, (i + 1) * sectionHeight, samples, std::ref(sdl), std::ref(scene), std::ref(camera), std::ref(mutex));
    }

    for (int i = 0; i < numThreads; i++) {
        threads[i].join();
    }

    while (sdl.isRunning())
    {
    sdl.startRendering();
    sdl.stopRendering();
    }

    sdl.closeWindow();
    return 0;
}
