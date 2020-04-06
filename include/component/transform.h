// A component for position.

#ifndef COMPONENT_TRANSFORM_H
#define COMPONENT_TRANSFORM_H

#include <set>
#include <functional>
#include "component.hpp"
#include "game_object.h"
#include "util/vector2.hpp"
#include "util/event.hpp"

class Transform : public Component {
public:
    Event<void, int, int> set_position_event;
    void Init(shared_ptr<GameObject> p_game_object, const Vector2& position);
    Vector2 GetPosition();
    Vector2 GetLatePosition();
    void SetPosition(int x, int y);
private:
    Vector2 position;
    Vector2 late_position;
    weak_ptr<GameObject> p_game_object;
};

#endif