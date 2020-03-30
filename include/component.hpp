// A part of game object.

#ifndef COMPONENT_H
#define COMPONENT_H

#include "common.h"

class Component {
public:
    virtual void Update() {};
    virtual void Draw() {};
};

#endif