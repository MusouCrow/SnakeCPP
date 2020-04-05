// Game object's factory.

#ifndef FACTORY_H
#define FACTORY_H

#include "common.h"
#include "game_object.h"

class Factory {
public:
    static shared_ptr<GameObject> NewHead();
};

#endif