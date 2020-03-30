// A pipeline of update and draw.

#ifndef CORE_H
#define CORE_H

#include <vector>
#include "common.h"
#include "game_object.h"

class Core {
public:
    static SDL_Renderer* p_renderer;
    static shared_ptr<GameObject> AddGameObject();
    static SDL_Renderer* GetRenderer();
    Core(const string& title, int width, int height);
    ~Core();
    void Update();
    void Draw();
private:
    static vector<shared_ptr<GameObject>> game_objects;
    SDL_Event event;
    SDL_Window* p_window;
};

#endif