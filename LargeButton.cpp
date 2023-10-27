#include "LargeButton.h"

LargeButton::LargeButton(SDL_Renderer *p_renderer, std::string imageLocation)
{
    static SDL_Texture *s_texture = IMG_LoadTexture(p_renderer, imageLocation.c_str()); // static variables are only initialised once.
    b_texture = s_texture;

    b_srectangle.h = 100;
    b_srectangle.w = 200;
    b_srectangle.x = 0;
    b_srectangle.y = 0;

    b_drectangle.h = 100;
    b_drectangle.w = 200;
}

void LargeButton::update(Mouse &mouse){
       if(SDL_HasIntersection(&b_drectangle, &mouse.m_point)){
        isSelected = true;
    } else {
        isSelected = false;
    }
}
