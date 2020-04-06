// Snake's body.

#ifndef COMPONENT_BODY_H
#define COMPONENT_BODY_H

#include "common.h"
#include "component.hpp"
#include "component/transform.h"

class Body : public Component {
public:
    static int count;
    void Init(shared_ptr<Transform> p_transform, shared_ptr<Transform> p_pre);
    ~Body();
private:
    shared_ptr<Transform> p_transform;
    shared_ptr<Transform> p_pre;
    function<void()> on_tick;
};

#endif