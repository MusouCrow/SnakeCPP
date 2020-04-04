#include "core.h"
#include "component/transform.h"
#include "component/renderer.h"

int main() {
    auto p_core = Core::GetInstance();
    p_core->Init("SnakeCPP", 1280, 720);
    
    auto p_go = p_core->AddGameObject();
    auto p_transform = p_go->AddComponent<Transform>();
    auto p_renderer = p_go->AddComponent<Renderer>();
    
    p_transform->Init(Vector2 {39, 0});
    p_renderer->Init(p_transform, SDL_Color {255, 0, 0, 255}, 30);

    while (true) {
        p_core->Update();
        p_core->Draw();
        SDL_Delay(16);
    }

    return 0;
}
