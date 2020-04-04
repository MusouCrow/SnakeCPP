#include "field.h"
#include "core.h"

Field* Field::GetInstance() {
    static Field field;

    return &field;
}

bool Field::AddGrid(const Vector2& position, shared_ptr<GameObject> gameObject) {
    if (this->grid_map.find(position) != this->grid_map.end()) {
        return false;
    }

    this->grid_map[position] = gameObject;

    return true;
}

bool Field::DelGrid(const Vector2& position) {
    if (this->grid_map.find(position) == this->grid_map.end()) {
        return false;
    }

    this->grid_map.erase(position);

    return true;
}

shared_ptr<GameObject> Field::GetGrid(const Vector2& position) {
    if (this->grid_map.find(position) == this->grid_map.end()) {
        return shared_ptr<GameObject>();
    }

    return this->grid_map[position];
}

Vector2 Field::GetDimension() {
    if (this->dimension.IsZero()) {
        auto p_core = Core::GetInstance();
        auto size = p_core->GetScreenSize();
        this->dimension.x = size.x / GRID_SIZE;
        this->dimension.y = size.y / GRID_SIZE;
    }

    return this->dimension;
}

Vector2 Field::TranslatePosition(int x, int y) {
    auto dimension = this->GetDimension();
    
    return Vector2 {x % this->dimension.x, y % this->dimension.y};
}
