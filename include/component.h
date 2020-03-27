// A part of game object.

#ifndef COMPONENT_H
#define COMPONENT_H

#include "common.h"

class Component {
public:
    void Init() {};
    virtual void Update() {};
    virtual void Draw() {};
};

#endif