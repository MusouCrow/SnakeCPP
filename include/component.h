// A part of game object.

#ifndef COMPONENT_H
#define COMPONENT_H

#include "common.h"

class Component {
protected:
    string name;
public:
    virtual void Start() {};
    virtual void Update() {};
    virtual void Draw() {};
    const string& GetName();
};

#endif