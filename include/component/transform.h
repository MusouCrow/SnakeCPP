// A component for position.

#ifndef COMPONENT_TRANSFORM_H
#define COMPONENT_TRANSFORM_H

#include <set>
#include <functional>
#include "component.hpp"
#include "util/vector2.hpp"
#include "util/event.hpp"

class Transform : public Component {
public:
    Event<void, int, int> set_position_event;
    void Init(const Vector2& position);
    Vector2 GetPosition();
    void SetPosition(int x, int y);
private:
    Vector2 position;
};

#endif