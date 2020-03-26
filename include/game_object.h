// Game's base object.

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <map>
#include "common.h"
#include "component.h"

class GameObject final {
private:
    map<string, Component*> component_map;
public:
    GameObject();
    ~GameObject();
    void Update();
    void Draw();
    bool AddComponent(Component* component);
    Component* GetComponent(const string& name);
};

#endif