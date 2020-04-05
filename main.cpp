#include "core.h"
#include "game.h"
#include "factory.h"
#include "component/transform.h"
#include "component/renderer.h"

int main() {
    auto p_core = Core::GetInstance();
    p_core->Init("SnakeCPP", 1280, 704);
    
    auto p_head = Factory::NewHead();
    
    while (true) {
        p_core->Update();
        p_core->Draw();
        SDL_Delay(16);
    }

    return 0;
}
