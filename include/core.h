// A pipeline of update and draw.

#ifndef CORE_H
#define CORE_H

#include <vector>
#include "common.h"
#include "game_object.h"

class Core {
public:
    static Core& GetInstance();
    ~Core();
    void Init(const string& title, int width, int height);
    void Update();
    void Draw();
    shared_ptr<GameObject> AddGameObject();
    SDL_Renderer* GetRenderer();
private:
    SDL_Event event;
    SDL_Window* p_window;
    SDL_Renderer* p_renderer;
    vector<shared_ptr<GameObject>> game_objects;
};

#endif