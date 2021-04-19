#include "minHeap.h"
#include "restaurant.h"

// credits Shane Malone Stepik 6.1.1

#include <iostream>
#include <queue>
#include <math.h>

minHeap::minHeap(int size)
{
    theHeapSize = 0;
    max = size;
    theHeap = new heapRestaurant[size];
}

minHeap::~minHeap()
{
    delete theHeap;
    theHeapSize = 0;
}

void minHeap::heapPrint()
{
    for (int i = 0; i < theHeapSize; ++i)
        std::cout << theHeap[i].item->getName() << " ";
}

int minHeap::getSize()
{
    return theHeapSize;
}

void minHeap::insert(heapRestaurant item)
{
    theHeap[theHeapSize] = item;
    theHeapSize++;
    theHeap = heapifyUp(0);
}

restaurant *minHeap::extractMin()
{
    heapRestaurant rootVal = theHeap[0];
    theHeap[0] = theHeap[--theHeapSize];
    theHeap = heapifyUp(0);
    return rootVal.item;
}

heapRestaurant *minHeap::heapifyUp(int index)
{
    int childLeft = 2 * index + 1;
    int childRight = 2 * index + 2;
    if (childLeft > theHeapSize - 1)
        return theHeap;
    int childMin = 0;
    if (theHeap[childLeft].distance < theHeap[childRight].distance)
        childMin = childLeft;
    else
        childMin = childRight;
    if (theHeap[childMin].distance < theHeap[index].distance)
    {
        heapRestaurant tempVal = theHeap[index];
        int nextIndex = childMin;
        theHeap[index] = theHeap[childMin];
        theHeap[childMin] = tempVal;
        return heapifyUp(childMin);
    }
    else
        return theHeap;
}

double minHeap::distance(restaurant *a, restaurant *b)
{
    pair<double, double> aCoord = a->getCoords();
    pair<double, double> bCoord = b->getCoords();

    return sqrt(abs(pow(bCoord.first - aCoord.first, 2)) + abs(pow(bCoord.second - aCoord.second, 2)));
}

queue<restaurant *> minHeap::bfs(restaurant *src)
{
    // return top 5 restaurants from heap
    std::queue<restaurant *> relatedRestaurants;
    while (theHeapSize > 0)
    {
        relatedRestaurants.push(extractMin());
    }

    return relatedRestaurants;
}