// Snake's food.

#ifndef COMPONENT_FOOD_H
#define COMPONENT_FOOD_H

#include "common.h"
#include "component.hpp"

class Food : public Component {
public:
    static int count;
    Food();
    ~Food();
};

#endif