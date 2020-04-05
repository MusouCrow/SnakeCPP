#include "input.h"
#include <vector>

Input* Input::GetInstance() {
    static Input input;

    return &input;
}

void Input::Update(const SDL_Event& event) {
    vector<SDL_Keycode> removes;

    for (auto iter : this->key_map) {
        if (iter.second == KeyState::pressed) {
            this->key_map[iter.first] = KeyState::hold;
        }
        else if (iter.second == KeyState::released) {
            removes.push_back(iter.first);
        }
    }

    for (auto k : removes) {
        this->key_map.erase(k);
    }
    
    if (event.type == SDL_KEYDOWN) {
        auto code = event.key.keysym.sym;
        
        if (this->key_map.find(code) == this->key_map.end()) {
            this->key_map[code] = KeyState::pressed;   
        }
    }
    else if (event.type == SDL_KEYUP) {
        this->key_map[event.key.keysym.sym] = KeyState::released;
    }
}

bool Input::IsPressed(const SDL_Keycode& code) {
    if (this->key_map.find(code) == this->key_map.end()) {
        return false;
    }

    return this->key_map[code] == KeyState::pressed;
}

bool Input::IsHold(const SDL_Keycode& code) {
    if (this->key_map.find(code) == this->key_map.end()) {
        return false;
    }

    return this->key_map[code] == KeyState::hold;
}

bool Input::IsReleased(const SDL_Keycode& code) {
    if (this->key_map.find(code) == this->key_map.end()) {
        return false;
    }

    return this->key_map[code] == KeyState::released;
}
