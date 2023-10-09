#include <iostream>
#include <SDL2/SDL.h>
#include "Screen.h"

using namespace std;
using namespace sdlMiniProject;

int main(int argc, char *argv[])
{
    Screen screen;

    if (screen.init() == false)
    {
        cout << "Error initialising SDL!" << endl;
    }

    while (true)
    {
        screen.update();

        // check for messages/events
        if (screen.processEvents() == false)
        {
            break;
        }
    }

    screen.close();

    return 0;
}