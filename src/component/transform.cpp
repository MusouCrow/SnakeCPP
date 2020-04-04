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
    
    this->set_position_event(pos.x, pos.y);
}
