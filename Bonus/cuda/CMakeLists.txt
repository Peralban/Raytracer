cmake_minimum_required(VERSION 3.10)
project(Raytracer)

include_directories(Interfaces)
include_directories(/usr/local/cuda/include/)

set(SOURCES
    src/main.cpp
    src/Graphical/Sdl2.cpp
    src/DataRetriever/Parsing.cpp
    src/Math/Ray3D.cpp
    src/Math/Vector3D.cpp
    src/Math/Point3D.cpp
    src/Raytracer/Camera.cpp
    src/Raytracer/Background.cpp
    src/Raytracer/Light.cpp
    src/Factory/Factory.cpp
    src/Materials/Glass.cpp
    src/Materials/Metal.cpp
    src/Materials/Matte.cpp
    src/Shapes/ShapeList.cpp
    src/Shapes/Sphere.cpp
    src/Shapes/Plane.cpp
    src/Shapes/Obj.cpp
    src/Shapes/Parallelepiped.cpp
    src/Shapes/Prism.cpp
    src/Shapes/Torus.cpp
    src/Shapes/Cone.cpp
    src/Shapes/CylinderInfinite.cpp
    src/Shapes/CylinderLimited.cpp
    src/Core/Core.cpp
    src/Shapes/TransformedShape.cpp
    src/Core/ClusterManagement.cpp
    src/Transformations/Translation.cpp
    src/Transformations/Rotation.cpp
    src/Transformations/Scale.cpp
    src/Transformations/Shear.cpp
)

set(CUDA_SOURCES
    src/Core/kernel.cu
)

add_executable(raytracer ${SOURCES} ${CUDA_SOURCES})

enable_language(CUDA)

target_include_directories(raytracer PRIVATE src)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(raytracer ${SDL2_LIBRARIES})

target_link_libraries(raytracer config++ SDL2 SDL2_image SDL2_ttf)

target_compile_options(raytracer PRIVATE -Wall -Wextra -Wshadow)
