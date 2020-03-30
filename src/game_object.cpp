#include "game_object.h"

GameObject::GameObject() {
    this->component_map = map<string, shared_ptr<Component>>();
}

void GameObject::Update() {
    for (auto iter : this->component_map) {
        iter.second->Update();
    }
}

void GameObject::Draw(SDL_Renderer* p_renderer) {
    for (auto iter : this->component_map) {
        iter.second->Draw(p_renderer);
    }
}
