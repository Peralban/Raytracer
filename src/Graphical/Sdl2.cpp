/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl.cpp
*/

#include "Sdl2.hpp"

Sdl::Sdl()
{
    _screenSize.x = 0;
    _screenSize.y = 0;
    _screenSize.w = 2160;
    _screenSize.h = 1080;
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        exit(84);
    }
    this->_window = SDL_CreateWindow("RayTracing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenSize.w, _screenSize.h, SDL_WINDOW_SHOWN);
    if (this->_window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(84);
    }
    this->_renderer = SDL_CreateRenderer(this->_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (this->_renderer == nullptr) {
        SDL_DestroyWindow(this->_window);
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(84);
    }
    _screenTexture = SDL_CreateTexture(_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, _screenSize.w, _screenSize.h);
}

Sdl::~Sdl()
{
    SDL_DestroyRenderer(this->_renderer);
    SDL_DestroyWindow(this->_window);
    SDL_Quit();
}

void Sdl::initWindow()
{
    SDL_SetRenderTarget(_renderer, _screenTexture);
    SDL_RenderClear(this->_renderer);
}

void Sdl::startRendering()
{
    SDL_SetRenderTarget(_renderer, _screenTexture);
}

void Sdl::stopRendering()
{
    SDL_SetRenderTarget(_renderer, NULL);
    SDL_RenderCopy(_renderer, _screenTexture, &_screenSize, &_screenSize);
    SDL_RenderPresent(this->_renderer);
}

void Sdl::closeWindow()
{
    SDL_DestroyRenderer(this->_renderer);
    SDL_DestroyTexture(_screenTexture);
    SDL_DestroyWindow(this->_window);
    SDL_Quit();
}

bool Sdl::isRunning()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            return 0;
    }
    return 1;
}

SDL_Color Sdl::createColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color color = {r, g, b, a};
    return color;
}

void Sdl::drawRect(SDL_Rect rect, SDL_Color color)
{
    SDL_SetRenderDrawColor(this->_renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(this->_renderer, &rect);
}

void Sdl::drawPoint(SDL_Point p)
{
    SDL_SetRenderDrawColor(this->_renderer, 255, 255, 255, 255);
    SDL_RenderDrawPoint(this->_renderer, p.x, p.y);
}

void Sdl::drawPoint(int x, int y)
{
    SDL_SetRenderDrawColor(this->_renderer, 255, 255, 255, 255);
    SDL_RenderDrawPoint(this->_renderer, x, y);
}

void Sdl::drawPoint(int x, int y, SDL_Color color)
{
    SDL_SetRenderDrawColor(this->_renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawPoint(this->_renderer, x, y);
}

void Sdl::drawPoint(int x, int y, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_SetRenderDrawColor(this->_renderer, r, g, b, 255);
    SDL_RenderDrawPoint(this->_renderer, x, y);
}
