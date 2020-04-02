#include "component/transform.h"

void Transform::Init(const Vector2& position) {
    this->SetPosition(position.x, position.y);
}

Vector2 Transform::GetPosition() {
    return this->position;
}

void Transform::SetPosition(int x, int y) {
    this->position.x = x;
    this->position.y = y;
    
    for (auto f : this->set_position_event) {
        (*f)(x, y);
    }
}

bool Transform::BindSetPosition(function<void(int, int)>* func) {
    if (this->set_position_event.find(func) != this->set_position_event.end()) {
        return false;
    }
    
    this->set_position_event.insert(func);
    
    return true;
}

bool Transform::UnbindSetPosition(function<void(int, int)>* func) {
    if (this->set_position_event.find(func) == this->set_position_event.end()) {
        return false;
    }
    
    this->set_position_event.erase(func);
    
    return true;
}

