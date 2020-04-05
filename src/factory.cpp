#include <cstdlib>
#include "factory.h"
#include "game.h"
#include "field.h"
#include "component/renderer.h"
#include "component/transform.h"
#include "component/head.h"
#include "component/food.h"

shared_ptr<GameObject> Factory::NewHead() {
    auto p_go = Game::GetInstance()->AddGameObject();
    auto p_transform = p_go->AddComponent<Transform>();
    auto p_renderer = p_go->AddComponent<Renderer>();
    auto p_head = p_go->AddComponent<Head>();
    
    auto dimension = Field::GetInstance()->GetDimension();
    
    p_transform->Init(p_go, Vector2 {dimension.x / 2, dimension.y / 2});
    p_renderer->Init(p_transform, SDL_Color {0, 0, 0, 255}, 32);
    p_head->Init(p_transform);
    
    return p_go;
}

shared_ptr<GameObject> Factory::NewFood() {
    auto p_go = Game::GetInstance()->AddGameObject();
    auto p_transform = p_go->AddComponent<Transform>();
    auto p_renderer = p_go->AddComponent<Renderer>();
    p_go->AddComponent<Food>();
    
    auto dimension = Field::GetInstance()->GetDimension();

    p_transform->Init(p_go, Vector2 {rand() % dimension.x, rand() % dimension.y});
    p_renderer->Init(p_transform, SDL_Color {255, 0, 0, 255}, 28);

    auto pos = p_transform->GetPosition();
    
    return p_go;
}
