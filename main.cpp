#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

int main(int argc, char *argv[])
{

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "uh oh" << endl;
        return false;
    }
    cout << "not uh oh" << endl;
    return 0;
}