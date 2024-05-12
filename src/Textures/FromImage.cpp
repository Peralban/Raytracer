/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IShape
*/


#include "FromImage.hpp"

RayTracer::FromImage::FromImage(const std::string &imagePath)
{
    reader = new Images::ImageReader(imagePath);
}

Math::Vector3D RayTracer::FromImage::get(double u, double v, const Math::Vector3D &p) const
{
    (void) p;
    int width = reader->width();
    int height = reader->height();
    unsigned char *Data = reader->getImageData();

    int i = (1 - u) * width; // Reverse the x-axis
    int j = (1 - v) * height; // Reverse the y-axis
    if (i < 0) i = 0;
    if (j < 0) j = 0;
    if (i > width - 1) i = width - 1;
    if (j > height - 1) j = height - 1;

    double b = static_cast<double>(Data[3*i + 3*width*j]) / 255.0;
    double g = static_cast<double>(Data[3*i + 3*width*j + 1]) / 255.0;
    double r = static_cast<double>(Data[3*i + 3*width*j + 2]) / 255.0;

    return Math::Vector3D(r, g, b);
}
