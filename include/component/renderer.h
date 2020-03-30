// A component for rendering.

#ifndef COMPONENT_RENDERER_H
#define COMPONENT_RENDERER_H

#include "component.hpp"
#include "util/vector2.hpp"

class Renderer : public Component {
public:
    Vector2 position;
    SDL_Color color;
    int size;
    void Init(const Vector2& position, const SDL_Color& color);
    virtual void Draw(SDL_Renderer* p_renderer);
};

#endif