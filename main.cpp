#include <iostream>

extern "C" {
    #include <SDL2/SDL.h>
}

using namespace std;

int main() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        cout << "Unable to initialize SDL: " << SDL_GetError() << endl;
        return 1;
    }

    auto window = SDL_CreateWindow(
        "Test", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        1280, 
        720, 
        SDL_WINDOW_INPUT_FOCUS
    );

    if (window == nullptr) {
        cout << "Could not create window: " << SDL_GetError() << endl;
        return 1;
    }

    SDL_Event event;

    while (true) {
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                break;
            }
        }
    }
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}
