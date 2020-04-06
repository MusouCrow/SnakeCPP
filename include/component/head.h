// Snake's head.

#ifndef COMPONENT_HEAD_H
#define COMPONENT_HEAD_H

#include <functional>
#include "common.h"
#include "component.hpp"
#include "component/transform.h"

class Head : public Component {
public:
    ~Head();
    void Init(shared_ptr<Transform> p_transform);
    virtual void Update();
    void Turn(const Direction& direction);
private:
    Direction direction;
    Direction next_direction;
    shared_ptr<Transform> p_transform;
    shared_ptr<Transform> p_tail;
    function<void(int, int)> on_set_position;
    function<void()> on_tick;
    void Grow();
};

#endif