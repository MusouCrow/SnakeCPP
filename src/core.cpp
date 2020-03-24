#include "core.h"

Core::Core(const string& title, int width, int height) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        cout << "Unable to initialize SDL: " << SDL_GetError() << endl;
        exit(1);
    }
    
    auto window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_INPUT_FOCUS);
    
    if (window == nullptr) {
        cout << "Could not create window: " << SDL_GetError() << endl;
        exit(1);
    }
    
    this->p_window = window;
}

Core::~Core() {
    SDL_DestroyWindow(this->p_window);
    SDL_Quit();

    delete this->p_window;
}

void Core::Update() {
    if (SDL_PollEvent(&this->event)) {
        if (this->event.type == SDL_QUIT) {
            exit(1);
        }
    }
}

void Core::Draw() {

}