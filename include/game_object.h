// Game's base object.

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <map>
#include "common.h"
#include "component.hpp"

class GameObject final {
private:
    map<string, shared_ptr<Component>> component_map;
public:
    GameObject();
    void Update();
    void Draw(SDL_Renderer* p_renderer);
    template <class T> shared_ptr<T> AddComponent();
    template <class T> shared_ptr<T> GetComponent();
};

template <class T> shared_ptr<T> GameObject::AddComponent() {
    string type_name = typeid(T).name();

    if (this->component_map.find(type_name) == this->component_map.end()) {
        this->component_map[type_name] = make_shared<T>();
    }

    return dynamic_pointer_cast<T>(this->component_map[type_name]);
}

template <class T> shared_ptr<T> GameObject::GetComponent() {
    string type_name = typeid(T).name();

    if (this->component_map.find(type_name) == this->component_map.end()) {
        return shared_ptr<T>();
    }
    
    return dynamic_pointer_cast<T>(this->component_map[type_name]);
}

#endif