#include "core.h"
#include "component/renderer.h"

void Renderer::Init(shared_ptr<Transform> p_transform, const SDL_Color& color, int size) {
    this->color = color;
    
    int sub = GRID_SIZE - size;
    this->rect.w = GRID_SIZE - (sub * 2) - 1;
    this->rect.h = GRID_SIZE - (sub * 2) - 1;

    this->on_set_position = [this, sub](int x, int y) {
        this->rect.x = x * GRID_SIZE + sub + 1;
        this->rect.y = y * GRID_SIZE + sub + 1;
    };
    
    this->p_transform = p_transform;
    this->p_transform->set_position_event += &this->on_set_position;

    auto pos = this->p_transform->GetPosition();
    this->on_set_position(pos.x, pos.y);
}

Renderer::~Renderer() {
    this->p_transform->set_position_event -= &this->on_set_position;
}

void Renderer::Draw(SDL_Renderer* p_renderer) {
    SDL_SetRenderDrawColor(p_renderer, this->color.r, this->color.g, this->color.b, this->color.a);
    SDL_RenderFillRect(p_renderer, &this->rect);
}
