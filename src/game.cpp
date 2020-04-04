#include "game.h"
#include "core.h"

Game* Game::GetInstance() {
    static Game Game;

    return &Game;
}

Game::Game() {
    this->AdjustInterval();
}

void Game::Update() {
    int time = SDL_GetTicks();
    
    if (time - this->later_time >= this->interval) {
        this->tick_event();
        this->later_time = time;
    }
    
    for (auto p : this->game_objects) {
        p->Update();
    }
}

void Game::Draw(SDL_Renderer* p_renderer) {
    auto size = Core::GetInstance()->GetScreenSize();

    if (GIZMOS) {
        SDL_SetRenderDrawColor(p_renderer, 255, 255, 255, 255);

        for (int i = 0; i < size.y / GRID_SIZE; i++) {
            SDL_RenderDrawLine(p_renderer, 0, i * GRID_SIZE, size.x, i * GRID_SIZE);
        }

        for (int i = 0; i < size.x / GRID_SIZE; i++) {
            SDL_RenderDrawLine(p_renderer, i * GRID_SIZE, 0, i * GRID_SIZE, size.y);
        }
    }

    for (auto p : this->game_objects) {
        p->Draw(p_renderer);
    }
}

shared_ptr<GameObject> Game::AddGameObject() {
    auto p_go = make_shared<GameObject>();
    this->game_objects.push_back(p_go);
    
    return p_go;
}

void Game::AdjustInterval() {
    this->interval = 1000;
}