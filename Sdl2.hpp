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

class Sdl  {
    public:
        Sdl();
        ~Sdl();
        void initWindow();
        void startRendering();
        void closeWindow();
        void stopRendering();

        /* Getters */
        bool isRunning();

        /*Draw functions*/
        void drawRect(SDL_Rect rect, SDL_Color color);
        void drawPoint(SDL_Point p);
        void drawPoint(int x, int y);
        void drawPoint(int x, int y, SDL_Color color);
        void drawPoint(int x, int y, uint8_t r, uint8_t  g, uint8_t  b);

        /*Color functions*/
        SDL_Color createColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    private:
        SDL_Window *_window;
        SDL_Renderer *_renderer;
        SDL_Texture *_screenTexture;
        SDL_Rect _screenSize;
};