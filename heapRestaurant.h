#pragma once
#include "restaurant.h"

using namespace std;

class heapRestaurant
{
public:
    heapRestaurant(restaurant *, double);
    heapRestaurant();
    restaurant *item;
    double distance;
};
