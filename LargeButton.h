#ifndef LARGEBUTTON_H
#define LARGEBUTTON_H

#include "Button.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#pragma once

class LargeButton : public Button
{
public:
    LargeButton(SDL_Renderer *p_renderer, std::string imageLocation);
    void update(Mouse&);

};

#endif