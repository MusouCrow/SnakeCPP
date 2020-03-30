#include "core.h"
#include "component/renderer.h"

void Renderer::Init(const Vector2& position, const SDL_Color& color) {
    this->position = position;
    this->color = color;
    this->size = GRID_SIZE;
}

void Renderer::Draw(SDL_Renderer* p_renderer) {
    auto rect = SDL_Rect {640 - 50, 360 - 50, 100, 100};
    
    SDL_SetRenderDrawColor(p_renderer, this->color.r, this->color.g, this->color.b, this->color.a);
    SDL_RenderFillRect(p_renderer, &rect);
}