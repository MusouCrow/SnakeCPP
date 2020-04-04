#include "core.h"
#include "game.h"
#include "component/transform.h"
#include "component/renderer.h"

int main() {
    auto p_core = Core::GetInstance();
    p_core->Init("SnakeCPP", 1280, 704);
    
    for (int i = 0; i < 2; i++) {
        auto p_go = Game::GetInstance()->AddGameObject();
        auto p_transform = p_go->AddComponent<Transform>();
        auto p_renderer = p_go->AddComponent<Renderer>();
        
        p_transform->Init(Vector2 {i, 0});
        p_renderer->Init(p_transform, SDL_Color {255, 0, 0, 255}, 32);
    }

    while (true) {
        p_core->Update();
        p_core->Draw();
        SDL_Delay(16);
    }

    return 0;
}
