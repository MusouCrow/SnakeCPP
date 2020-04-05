#include "component/head.h"
#include "game.h"

void Head::Init(shared_ptr<Transform> p_transform) {
    this->on_set_position = [this](int x, int y) {
    };

    this->on_tick = [this]() {
        Vector2 move;
        
        if (this->direction == Direction::up) {
            move.x = 0;
            move.y = -1;
        }
        else if (this->direction == Direction::down) {
            move.x = 0;
            move.y = 1;
        }
        else if (this->direction == Direction::left) {
            move.x = -1;
            move.y = 0;
        }
        else if (this->direction == Direction::right) {
            move.x = 1;
            move.y = 0;
        }

        auto pos = this->p_transform->GetPosition();
        this->p_transform->SetPosition(pos.x + move.x, pos.y + move.y);
    };
    
    this->p_transform = p_transform;
    this->p_transform->set_position_event += &this->on_set_position;

    Game::GetInstance()->tick_event += &this->on_tick;

    auto pos = this->p_transform->GetPosition();
    this->on_set_position(pos.x, pos.y);
}

Head::~Head() {
    this->p_transform->set_position_event -= &this->on_set_position;
    Game::GetInstance()->tick_event -= &this->on_tick;
}

void Head::Update() {

}

void Head::SetDirection(const Direction& next) {
    if (this->direction == next) {
        return;
    }

    bool ban1 = next == Direction::down && this->direction == Direction::up;
    bool ban2 = next == Direction::up && this->direction == Direction::down;
    bool ban3 = next == Direction::left && this->direction == Direction::right;
    bool ban4 = next == Direction::right && this->direction == Direction::left;

    if (!(ban1 || ban2 || ban3 || ban4)) {
        this->direction = next;
    }
}