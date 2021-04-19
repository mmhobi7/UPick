#pragma once
#include "restaurant.h"

using namespace std;

class heapRestaurant
{
public:
    heapRestaurant(restaurant *, long long);
    heapRestaurant();
    restaurant *item;
    long long distance;
};
