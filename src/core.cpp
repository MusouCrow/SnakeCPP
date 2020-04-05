#include "core.h"
#include "game.h"
#include "input.h"

Core* Core::GetInstance() {
    static Core core;

    return &core;
}

void Core::Init(const string& title, int width, int height) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        cout << "Unable to initialize SDL: " << SDL_GetError() << endl;
        exit(1);
    }
    
    auto p_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_INPUT_FOCUS);
    
    if (p_window == nullptr) {
        cout << "Could not create window: " << SDL_GetError() << endl;
        exit(1);
    }
    
    this->p_window = p_window;
    this->p_renderer = SDL_CreateRenderer(p_window, -1, SDL_RENDERER_ACCELERATED);
}

Core::~Core() {
    SDL_DestroyWindow(this->p_window);
    SDL_Quit();
}

void Core::Update() {
    if (SDL_PollEvent(&this->event)) {
        if (this->event.type == SDL_QUIT) {
            exit(1);
        }
    }
    
    Input::GetInstance()->Update(this->event);
    Game::GetInstance()->Update();
}

void Core::Draw() {
    SDL_SetRenderDrawColor(this->p_renderer, 49, 77, 121, 255);
    SDL_RenderClear(this->p_renderer);

    Game::GetInstance()->Draw(this->p_renderer);

    SDL_RenderPresent(this->p_renderer);   
}

Vector2 Core::GetScreenSize() {
    int w, h;
    SDL_GetWindowSize(this->p_window, &w, &h);

    return Vector2 {w, h};
}
