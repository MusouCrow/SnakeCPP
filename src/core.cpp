#include "core.h"
#include "game_object.h"
#include "component/renderer.h"

Core& Core::GetInstance() {
    static Core core;

    return core;
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

    {
        auto p_go = this->AddGameObject();
        auto p_renderer = p_go->AddComponent<Renderer>();
        p_renderer->Init(Vector2 {5, 5}, SDL_Color {255, 255, 255, 255});
    }
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

    for (auto p : this->game_objects) {
        p->Update();
    }
}

void Core::Draw() {
    SDL_SetRenderDrawColor(this->p_renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->p_renderer);
    
    for (auto p : this->game_objects) {
        p->Draw(this->p_renderer);
    }

    SDL_RenderPresent(this->p_renderer);   
}

shared_ptr<GameObject> Core::AddGameObject() {
    auto p_go = make_shared<GameObject>();
    this->game_objects.push_back(p_go);
    
    return p_go;
}

SDL_Renderer* Core::GetRenderer() {
    return this->p_renderer;
}
