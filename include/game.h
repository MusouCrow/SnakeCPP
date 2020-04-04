// Game manager

#ifndef GAME_H
#define GAME_H

#include <vector>
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
    void AdjustInterval();
private:
    vector<shared_ptr<GameObject>> game_objects;
    int later_time;
    int interval;
};

#endif