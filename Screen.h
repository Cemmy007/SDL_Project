#ifndef SCREEN_H
#define SCREEN_H

#pragma once

#include <SDL2/SDL.h>

namespace sdlMiniProject
{
    class Screen
    {
    public:
        const static int SCREEN_WIDTH = 1000, SCREEN_HEIGHT = 800;

    private:
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        SDL_Texture *m_texture;
        Uint32 *m_buffer;

    public:
        Screen();
        bool init();
        bool processEvents();
        void close();
        void update();
        //void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
        //void clear();
        //void boxBlur();
    };
}

#endif