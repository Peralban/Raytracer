/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sdl.hpp
*/

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <vector>
#include <atomic>

/**
 * @class Sdl
 * @brief Represents the SDL window and rendering context.
 *
 * The Sdl class is responsible for managing the SDL window and rendering context.
 * It provides methods for initializing and closing the window, starting and stopping rendering,
 * checking if the window is running, drawing rectangles and points, and creating colors.
 */
class Sdl  {
    public:
        /**
         * @brief Default constructor for the Sdl class.
         *
         * Initializes a new instance of the Sdl class.
         */
        Sdl();

        /**
         * @brief Default destructor for the Sdl class.
         */
        ~Sdl();

        /**
         * @brief Initializes the SDL window.
         */
        void initWindow();

        /**
         * @brief Starts the rendering process.
         */
        void startRendering();

        /**
         * @brief Closes the SDL window.
         */
        void closeWindow();

        /**
         * @brief Stops the rendering process.
         */
        void stopRendering();

        /**
         * @brief Checks if the SDL window is running.
         *
         * @return A boolean indicating whether the SDL window is running.
         */
        bool isRunning();

        /**
         * @brief Draws a rectangle with a specified color.
         *
         * @param rect The rectangle to draw.
         * @param color The color of the rectangle.
         */
        void drawRect(SDL_Rect rect, SDL_Color color);

        /**
         * @brief Draws a point at a specified position.
         *
         * @param p The position of the point.
         */
        void drawPoint(SDL_Point p);

        /**
         * @brief Draws a point at a specified position.
         *
         * @param x The x-coordinate of the point.
         * @param y The y-coordinate of the point.
         */
        void drawPoint(int x, int y);

        /**
         * @brief Draws a point at a specified position with a specified color.
         *
         * @param x The x-coordinate of the point.
         * @param y The y-coordinate of the point.
         * @param color The color of the point.
         */
        void drawPoint(int x, int y, SDL_Color color);

        /**
         * @brief Draws a point at a specified position with a specified color.
         *
         * @param x The x-coordinate of the point.
         * @param y The y-coordinate of the point.
         * @param r The red component of the color.
         * @param g The green component of the color.
         * @param b The blue component of the color.
         */
        void drawPoint(int x, int y, uint8_t r, uint8_t  g, uint8_t  b);

        /**
         * @brief Creates a color with specified red, green, blue, and alpha components.
         *
         * @param r The red component of the color.
         * @param g The green component of the color.
         * @param b The blue component of the color.
         * @param a The alpha component of the color.
         * @return The created color.
         */
        SDL_Color createColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

    private:
        SDL_Window *_window; ///< The SDL window.
        SDL_Renderer *_renderer; ///< The SDL rendering context.
        SDL_Texture *_screenTexture; ///< The texture for the screen.
        SDL_Rect _screenSize; ///< The size of the screen.
};
