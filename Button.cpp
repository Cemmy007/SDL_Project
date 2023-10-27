#include "Button.h"

Button::Button(){

}

Button::Button(SDL_Renderer *p_renderer)
{
    static SDL_Texture *s_texture = IMG_LoadTexture(p_renderer, "images/arrows.png"); // static variables are only initialised once.
    b_texture = s_texture;

    b_srectangle.h = 100;
    b_srectangle.w = 100;
    b_srectangle.x = 0;

    b_drectangle.h = 100;
    b_drectangle.w = 100;
}

Button::~Button()
{
}

void Button::update(Mouse &mouse){
    if(SDL_HasIntersection(&b_drectangle, &mouse.m_point)){
        isSelected = true;
        b_srectangle.x = 100;
    } else {
        isSelected = false;
        b_srectangle.x = 0;
    }
}

void Button::draw(SDL_Renderer *p_renderer){
    SDL_RenderCopy(p_renderer, b_texture, &b_srectangle, &b_drectangle);    
}

