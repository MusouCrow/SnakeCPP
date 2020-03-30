#include "component/renderer.h"

void Renderer::Init(const Vector2& position, const SDL_Color& color) {
    this->position = position;
    this->color = color;
    this->size = GRID_SIZE;
}

void Renderer::Draw() {
    cout << "Draw" << endl;
}