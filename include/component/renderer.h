// A component for rendering.

#ifndef COMPONENT_RENDERER_H
#define COMPONENT_RENDERER_H

#include <functional>
#include "component.hpp"
#include "transform.h"
#include "util/vector2.hpp"

class Renderer : public Component {
public:
    SDL_Color color;
    ~Renderer();
    void Init(shared_ptr<Transform> p_transform, const SDL_Color& color, int size);
    virtual void Draw(SDL_Renderer* p_renderer);
private:
    SDL_Rect rect;
    shared_ptr<Transform> p_transform;
    function<void(int, int)> on_set_position;
};

#endif