// Snake's head.

#ifndef COMPONENT_HEAD_H
#define COMPONENT_HEAD_H

#include <functional>
#include "common.h"
#include "component.hpp"
#include "transform.h"

class Head : public Component {
public:
    ~Head();
    void Init(shared_ptr<Transform> p_transform);
    virtual void Update();
    void SetDirection(const Direction& direction);
private:
    Direction direction;
    shared_ptr<Transform> p_transform;
    function<void(int, int)> on_set_position;
    function<void()> on_tick;
};

#endif