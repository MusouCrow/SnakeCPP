#include "game_object.h"

GameObject::GameObject() {
    this->component_map = map<string, Component*>();
}

GameObject::~GameObject() {
    for (auto iter : this->component_map) {
        delete iter.second;
    }
}

void GameObject::Update() {
    for (auto iter : this->component_map) {
        iter.second->Update();
    }
}

void GameObject::Draw() {
    for (auto iter : this->component_map) {
        iter.second->Draw();
    }
}

bool GameObject::AddComponent(Component* component) {
    // Don't allow same component.
    if (this->component_map.find(component->GetName()) != this->component_map.end()) {
        return false;
    }
    
    component->Start();
    this->component_map[component->GetName()] = component;

    return true;
}

Component* GameObject::GetComponent(const string& name) {
    if (this->component_map.find(name) == this->component_map.end()) {
        return nullptr;
    }

    return this->component_map[name];
}
