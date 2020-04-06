#include <cstdlib>
#include "factory.h"
#include "game.h"
#include "field.h"
#include "component/renderer.h"
#include "component/transform.h"
#include "component/head.h"
#include "component/food.h"
#include "component/body.h"

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
    auto p_field = Field::GetInstance();
    auto dimension = p_field->GetDimension();
    auto pos = Vector2 {rand() % dimension.x, rand() % dimension.y};

    if (p_field->GetGrid(pos).get() != nullptr) {
        return shared_ptr<GameObject>();
    }

    auto p_go = Game::GetInstance()->AddGameObject();
    auto p_transform = p_go->AddComponent<Transform>();
    auto p_renderer = p_go->AddComponent<Renderer>();
    p_go->AddComponent<Food>();

    p_transform->Init(p_go, pos);
    p_renderer->Init(p_transform, SDL_Color {255, 0, 0, 255}, 28);

    return p_go;
}

shared_ptr<GameObject> Factory::NewBody(shared_ptr<Transform> p_pre) {
    auto p_go = Game::GetInstance()->AddGameObject();
    auto p_transform = p_go->AddComponent<Transform>();
    auto p_renderer = p_go->AddComponent<Renderer>();
    auto p_body = p_go->AddComponent<Body>();

    p_transform->Init(p_go, p_pre->GetPosition());
    p_renderer->Init(p_transform, SDL_Color {255, 255, 255, 255}, 30);
    p_body->Init(p_transform, p_pre);
    
    return p_go;
}