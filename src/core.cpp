#include "core.h"
#include "game_object.h"
#include "component/renderer.h"

vector<shared_ptr<GameObject>> Core::game_objects;
SDL_Renderer* p_renderer = nullptr;

shared_ptr<GameObject> Core::AddGameObject() {
    auto p_go = make_shared<GameObject>();
    Core::game_objects.push_back(p_go);
    
    return p_go;
}

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
    
    /*
    auto p_go = Core::AddGameObject();
    auto p_renderer = p_go->AddComponent<Renderer>();
    p_renderer->Init(Vector2 {5, 5}, SDL_Color {255, 255, 255, 255});
    */
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

    for (auto p : Core::game_objects) {
        p->Update();
    }
}

void Core::Draw() {
    for (auto p : Core::game_objects) {
        p->Draw();
    }
}