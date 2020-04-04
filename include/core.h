// A pipeline of update and draw.

#ifndef CORE_H
#define CORE_H

#include <vector>
#include "common.h"
#include "util/vector2.hpp"

class Core {
public:
    static Core* GetInstance();
    ~Core();
    void Init(const string& title, int width, int height);
    void Update();
    void Draw();
    Vector2 GetScreenSize();
private:
    SDL_Event event;
    SDL_Window* p_window;
    SDL_Renderer* p_renderer;
};

#endif