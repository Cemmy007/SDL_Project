#ifndef MOUSE_H
#define MOUSE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#pragma once

class Mouse
{
public:
    SDL_Texture *m_texture;
    SDL_Rect m_rectangle;
    SDL_Rect m_point;

public:
    Mouse(SDL_Renderer *p_renderer);
    ~Mouse();
    void update();
    void draw(SDL_Renderer *p_renderer);

};

#endif