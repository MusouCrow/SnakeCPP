// Input manager.

#ifndef INPUT_H
#define INPUT_H

#include <map>
#include "common.h"

class Input {
public:
    static Input* GetInstance();
    void Update(const SDL_Event& event);
    bool IsPressed(const SDL_Keycode& code);
    bool IsHold(const SDL_Keycode& code);
    bool IsReleased(const SDL_Keycode& code);
private:
    map<SDL_Keycode, KeyState> key_map;
};

#endif