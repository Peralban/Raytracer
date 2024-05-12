/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IShape
*/


#include "FromImage.hpp"

RayTracer::FromImage::FromImage(const std::string &imagePath)
{
    _image = Images::ImageReader(imagePath);
}

Math::Vector3D RayTracer::FromImage::get(double u, double v, const Math::Vector3D &p) const
{
    int i = u * _image.width();
    int j = (1 - v) * _image.height() - 0.001;
    if (i < 0) {
        i = 0;
    }
    if (j < 0) {
        j = 0;
    }
    if (i > _image.width() - 1) {
        i = _image.width() - 1;
    }
    if (j > _image.height() - 1) {
        j = _image.height() - 1;
    }
    double r = static_cast<int>(_image.getPixel(i, j).r) / 255.0;
    double g = static_cast<int>(_image.getPixel(i, j).g) / 255.0;
    double b = static_cast<int>(_image.getPixel(i, j).b) / 255.0;
    return Math::Vector3D(r, g, b);
}
