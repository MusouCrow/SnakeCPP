#include "component/body.h"
#include "game.h"

int Body::count = 0;

void Body::Init(shared_ptr<Transform> p_transform, shared_ptr<Transform> p_pre) {
    this->p_transform = p_transform;
    this->p_pre = p_pre;

    this->on_tick = [this]() {
        auto pos = this->p_pre->GetLatePosition();
        this->p_transform->SetPosition(pos.x, pos.y);
    };

    Game::GetInstance()->tick_event += &this->on_tick;
    Body::count++;
};

Body::~Body() {
    Game::GetInstance()->tick_event -= &this->on_tick;
    Body::count--;
}
