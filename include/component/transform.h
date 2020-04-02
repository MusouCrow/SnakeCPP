// A component for position.

#ifndef COMPONENT_TRANSFORM_H
#define COMPONENT_TRANSFORM_H

#include <set>
#include <functional>
#include "component.hpp"
#include "util/vector2.hpp"

class Transform : public Component {
public:
    void Init(const Vector2& position);
    Vector2 GetPosition();
    void SetPosition(int x, int y);
    bool BindSetPosition(function<void(int, int)>* func);
    bool UnbindSetPosition(function<void(int, int)>* func);
private:
    Vector2 position;
    set<function<void(int, int)>*> set_position_event;
};

#endif