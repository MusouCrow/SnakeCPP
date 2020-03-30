#include "core.h"

int main() {
    auto core = Core::GetInstance();
    core.Init("SnakeCPP", 1280, 720);
    
    while (true) {
        core.Update();
        core.Draw();
        SDL_Delay(16);
    }
    
    return 0;
}
