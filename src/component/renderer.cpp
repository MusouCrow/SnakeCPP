#include "core.h"
#include "component/renderer.h"

void Renderer::Init(const Vector2& position, const SDL_Color& color, int size) {
    this->color = color;
    this->sub = GRID_SIZE - size;

    this->rect.w = GRID_SIZE - this->sub;
    this->rect.h = GRID_SIZE - this->sub;
    this->SetPosition(position.x, position.y);
}

void Renderer::Draw(SDL_Renderer* p_renderer) {
    SDL_SetRenderDrawColor(p_renderer, this->color.r, this->color.g, this->color.b, this->color.a);
    SDL_RenderFillRect(p_renderer, &this->rect);
}

Vector2 Renderer::GetPosition() {
    return Vector2 {(this->rect.x - this->sub) / GRID_SIZE, (this->rect.y - this->sub) / GRID_SIZE};
}

void Renderer::SetPosition(int x, int y) {
    this->rect.x = x * GRID_SIZE + this->sub;
    this->rect.y = y * GRID_SIZE + this->sub;
}
