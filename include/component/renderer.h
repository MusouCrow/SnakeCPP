// A component for rendering.

#ifndef COMPONENT_RENDERER_H
#define COMPONENT_RENDERER_H

#include "component.hpp"
#include "util/vector2.hpp"

class Renderer : public Component {
public:
    SDL_Color color;
    void Init(const Vector2& position, const SDL_Color& color, int size);
    virtual void Draw(SDL_Renderer* p_renderer);
    Vector2 GetPosition();
    void SetPosition(int x, int y);
private:
    SDL_Rect rect;
    int sub;
};

#endif