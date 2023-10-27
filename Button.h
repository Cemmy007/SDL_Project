#ifndef BUTTON_H
#define BUTTON_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Mouse.h"

#pragma once

class Button
{
    public:
    SDL_Texture *b_texture;
    SDL_Rect b_srectangle, b_drectangle;
    bool isSelected = false;
public:
    Button();
    Button(SDL_Renderer *p_renderer);
    ~Button();
    void update(Mouse&);
    void draw(SDL_Renderer *p_renderer);

private:

};

#endif