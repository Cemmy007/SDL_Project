#include "Mouse.h"

Mouse::Mouse(SDL_Renderer *p_renderer)
{
    m_texture = IMG_LoadTexture(p_renderer, "images/cursor.png");
    m_rectangle.w = 25;
    m_rectangle.h = 25;
    m_point.w = 1;
    m_point.h = 1;
    SDL_ShowCursor(false);//hides system mouse
}

void Mouse::update()
{
    SDL_GetMouseState(&m_rectangle.x, &m_rectangle.y); // updates postion of rectangle.
    m_point.x = m_rectangle.x;
    m_point.y = m_rectangle.y;
}

void Mouse::draw(SDL_Renderer *p_renderer){
    SDL_RenderCopy(p_renderer, m_texture, NULL, &m_rectangle);
}

Mouse::~Mouse()
{
}