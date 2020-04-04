#include "component/transform.h"
#include "field.h"

void Transform::Init(const Vector2& position) {
    this->SetPosition(position.x, position.y);
}

Vector2 Transform::GetPosition() {
    return this->position;
}

void Transform::SetPosition(int x, int y) {
    auto p_field = Field::GetInstance();
    auto pos = p_field->TranslatePosition(x, y);
    this->position.x = pos.x;
    this->position.y = pos.y;
    
    for (auto f : this->set_position_event) {
        (*f)(pos.x, pos.y);
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

