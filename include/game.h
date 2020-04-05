// Game manager

#ifndef GAME_H
#define GAME_H

#include <set>
#include "common.h"
#include "game_object.h"
#include "util/event.hpp"

class Game {
public:
    static Game* GetInstance();
    Event<void> tick_event;
    Game();
    void Update();
    void Draw(SDL_Renderer* p_renderer);
    shared_ptr<GameObject> AddGameObject();
    bool DelGameObject(shared_ptr<GameObject> p_go);
    void AdjustInterval();
    void ProduceFood();
private:
    set<shared_ptr<GameObject>> game_object_set;
    int later_time;
    int interval;
};

#endif