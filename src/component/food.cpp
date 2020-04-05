#include "component/food.h"

int Food::count = 0;

Food::Food() {
    Food::count++;
}

Food::~Food() {
    Food::count--;
}
