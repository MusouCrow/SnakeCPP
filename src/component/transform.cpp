#include "component/transform.h"
#include "field.h"

void Transform::Init(shared_ptr<GameObject> p_game_object, const Vector2& position) {
    this->p_game_object = p_game_object;
    this->SetPosition(position.x, position.y);
}

Vector2 Transform::GetPosition() {
    return this->position;
}

void Transform::SetPosition(int x, int y) {
    auto p_field = Field::GetInstance();
    auto pos = p_field->TranslatePosition(x, y);

    p_field->DelGrid(this->position);
    this->position.x = pos.x;
    this->position.y = pos.y;

    this->set_position_event(pos.x, pos.y);
    p_field->AddGrid(pos, shared_ptr<GameObject>(this->p_game_object));
}
