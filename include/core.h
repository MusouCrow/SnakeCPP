// A pipeline of update and draw.

#ifndef CORE_H
#define CORE_H

#include "common.h"

class Core {
public:
    Core(const string& title, int width, int height);
    ~Core();
    void Update();
    void Draw();
private:
    SDL_Event event;
    SDL_Window* p_window;
};

#endif