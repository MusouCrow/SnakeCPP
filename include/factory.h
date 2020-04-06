// Game object's factory.

#ifndef FACTORY_H
#define FACTORY_H

#include "common.h"
#include "game_object.h"
#include "component/transform.h"

class Factory {
public:
    static shared_ptr<GameObject> NewHead();
    static shared_ptr<GameObject> NewFood();
    static shared_ptr<GameObject> NewBody(shared_ptr<Transform> pre);
};

#endif