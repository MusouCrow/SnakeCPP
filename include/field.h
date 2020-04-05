// Field about position and scope.

#ifndef FIELD_H
#define FIELD_H

#include <map>
#include "common.h"
#include "game_object.h"
#include "util/vector2.hpp"

class Field {
public:
    static Field* GetInstance();
    void AddGrid(const Vector2& position, shared_ptr<GameObject> gameObject);
    bool DelGrid(const Vector2& position);
    shared_ptr<GameObject> GetGrid(const Vector2& position);
    Vector2 GetDimension();
    Vector2 TranslatePosition(int x, int y);
private:
    map<Vector2, shared_ptr<GameObject>> grid_map;
    Vector2 dimension;
};

#endif