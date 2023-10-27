#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
// #include "Screen.h"
#include "LargeButton.h"
#include <vector>
#include <time.h>

using namespace std;
// using namespace sdlMiniProject;

int main(int argc, char *argv[])
{
    srand(time(NULL));
    // Screen screen;

    // if (screen.init() == false)
    // {
    //     cout << "Error initialising SDL!" << endl;
    // }

    // while (true)
    // {
    //     screen.update();

    //     // check for messages/events
    //     if (screen.processEvents() == false)
    //     {
    //         break;
    //     }
    // }

    // screen.close();

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 1;
    }

    SDL_Window *p_window = SDL_CreateWindow("To be named", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1000, 800, SDL_WINDOW_SHOWN);
    SDL_Renderer *p_renderer = SDL_CreateRenderer(p_window, -1, SDL_RENDERER_PRESENTVSYNC);

    bool running = true;
    double delta = .0001;
    double time2 = SDL_GetTicks();

    SDL_Rect p_rectangle{30, 30, 200, 100};
    float x = p_rectangle.x;
    float y = p_rectangle.y;
    SDL_Rect p_rectangle2{0, 100, 200, 100};

    SDL_Texture *p_texture = IMG_LoadTexture(p_renderer, "images/test.png");
    
    vector<string> images{"images/randomImages/A.png","images/randomImages/car.png","images/randomImages/planet.png"};

    int number;

    if (!p_texture)
    {
        cout << SDL_GetError() << endl;
    }

    Mouse mouse(p_renderer);

    Button upArrow(p_renderer), downArrow(p_renderer), leftArrow(p_renderer), rightArrow(p_renderer);
    rightArrow.b_srectangle.y = 0;
    rightArrow.b_drectangle.x = 900;
    rightArrow.b_drectangle.y = 600;

    leftArrow.b_srectangle.y = 200;
    leftArrow.b_drectangle.x = 800;
    leftArrow.b_drectangle.y = 600;

    downArrow.b_srectangle.y = 300;
    downArrow.b_drectangle.x = 850;
    downArrow.b_drectangle.y = 700;

    upArrow.b_srectangle.y = 100;
    upArrow.b_drectangle.x = 850;
    upArrow.b_drectangle.y = 500;

    LargeButton changeImage(p_renderer, "images/changeImage.png");
    changeImage.b_drectangle.x = 600;
    changeImage.b_drectangle.y = 550;

    // main loop
    while (running)
    {
        mouse.update();
        rightArrow.update(mouse);
        leftArrow.update(mouse);
        downArrow.update(mouse);
        upArrow.update(mouse);
        changeImage.update(mouse);

        delta = (SDL_GetTicks() - time2) / 1000;
        time2 = SDL_GetTicks();
        SDL_Event p_event;

        while (SDL_PollEvent(&p_event))
        {
            switch (p_event.type)
            {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_MOUSEBUTTONUP:
                if (p_event.button.button == SDL_BUTTON_LEFT)
                {
                    if (rightArrow.isSelected)
                    {
                        x += 100 * delta;
                    }
                    else if (leftArrow.isSelected)
                    {
                        x += -100 * delta;
                    }
                    else if (upArrow.isSelected)
                    {
                        y += -100 * delta;
                    }
                    else if (downArrow.isSelected)
                    {
                        y += 100 * delta;
                    }
                    else if (changeImage.isSelected)
                    {
                        number = rand() % 3;
                        string image = images[number];
                        p_texture = IMG_LoadTexture(p_renderer, image.c_str());
                    }
                }
                break;

            default:
                break;
            }
        }

        auto key = SDL_GetKeyboardState(0);

        if (key[SDL_SCANCODE_A])
        {
            x += -100 * delta;
        }

        if (key[SDL_SCANCODE_D])
        {
            x += 100 * delta;
        }
        if (key[SDL_SCANCODE_W])
        {
            y += -100 * delta;
        }

        if (key[SDL_SCANCODE_S])
        {
            y += 100 * delta;
        }

        p_rectangle.x = x;
        p_rectangle.y = y;

        SDL_SetRenderDrawColor(p_renderer, 0, 0, 0, 255);
        SDL_RenderClear(p_renderer);
        SDL_SetRenderDrawColor(p_renderer, 0, 0, 200, 255);
        SDL_RenderFillRect(p_renderer, &p_rectangle);
        SDL_SetRenderDrawColor(p_renderer, 150, 0, 0, 255);
        SDL_RenderDrawRect(p_renderer, &p_rectangle);
        SDL_RenderCopy(p_renderer, p_texture, &p_rectangle2, &p_rectangle); // first rectangle is your source, second is destination
        rightArrow.draw(p_renderer);
        leftArrow.draw(p_renderer);
        downArrow.draw(p_renderer);
        upArrow.draw(p_renderer);
        changeImage.draw(p_renderer);
        mouse.draw(p_renderer);
        SDL_RenderPresent(p_renderer);
    }

    SDL_DestroyRenderer(p_renderer);
    SDL_DestroyWindow(p_window);
    SDL_Quit();

    return 0;
}