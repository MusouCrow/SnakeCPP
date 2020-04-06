#include <ctime>
#include <cstdlib>
#include "core.h"
#include "game.h"
#include "factory.h"
#include "component/transform.h"
#include "component/renderer.h"

int main() {
    srand(time(nullptr));
    
    auto p_core = Core::GetInstance();
    p_core->Init("SnakeCPP", 1280, 704);
    
    Factory::NewHead();
    Game::GetInstance()->ProduceFood();

    while (true) {
        p_core->Update();
        p_core->Draw();
        SDL_Delay(16);
    }
    
    return 0;
}
