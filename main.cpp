


#include "Sdl2.hpp"
#include "Vector3D.hpp"
#include "Ray3D.hpp"


double hitSphere(const Math::Vector3D &center, double radius, const Math::Ray3D &ray)
{
    Math::Vector3D oc = ray.getOrigin() - center;
    double a = ray.getDirection().dot(ray.getDirection());
    double b = 2.0 * oc.dot(ray.getDirection());
    double c = oc.dot(oc) - radius * radius;
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
        return -1.0;
    else
        return (-b - sqrt(discriminant)) / (2.0 * a);
}

Math::Vector3D color (const Math::Ray3D &ray)
{
    double t = hitSphere(Math::Vector3D(0, 0, -1), 0.5, ray);
    if (t > 0.0)
    {
        Math::Vector3D N = ray.pointOnRay(t) - Math::Vector3D(0, 0, -1);
        N.getUnitVector();
        return Math::Vector3D(N.x + 1, N.y + 0.2, N.z +0 ) * 0.5;
    }
    Math::Vector3D unitDirection = ray.getDirection();
    unitDirection.getUnitVector();
    t = 0.5 * (unitDirection.y + 1.0);
    return Math::Vector3D(1.0, 1.0, 1.0) * (1.0 - t) + Math::Vector3D(0.5, 0.7, 1.0) * t;
}

int main()
{
    Sdl sdl;
    sdl.initWindow();
    int width = 1440;
    int height = 720;
    std::cout << "P3" << std::endl;
    std::cout  << width << "  " << height << std::endl;
    std::cout << "255" << std::endl;
    Math::Vector3D lowerLeft(-2.0, -1.0, -1.0);
    Math::Vector3D horizontal(4.0, 0.0, 0.0);
    Math::Vector3D vertical(0.0, 2.0, 0.0);
    Math::Vector3D origin(0.0, 0.0, 0.0);
    for (int y=height - 1; y>=0; y--)
    {
        for (int x=0; x<width; x++)
        {
            float u = float(x) / float(width);
            float v = float(y) / float(height);
            Math::Ray3D ray(origin, lowerLeft + horizontal * u + vertical * v);
            Math::Vector3D col = color(ray);
            unsigned char r = static_cast<unsigned char>(255.99 * col.x);
            unsigned char g = static_cast<unsigned char>(255.99 * col.y);
            unsigned char b = static_cast<unsigned char>(255.99 * col.z);
           sdl.drawPoint(x, height-y, r, g, b);
          //std::cout  << (int)r << " " << (int) g << " " << (int)b << std::endl;
        }
    }
    while (sdl.isRunning()){
        sdl.startRendering();
        sdl.stopRendering();
    }
    sdl.closeWindow();
    return 0;
}