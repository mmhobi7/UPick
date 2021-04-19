#pragma once
#include "heapRestaurant.h"
// credits Muhamed Hobi Stepik 6.1.1

class minHeap
{
public:
    minHeap(int);
    ~minHeap();
    void heapPrint();
    int getSize();
    void insert(heapRestaurant);
    restaurant *extractMin();
    double distance(restaurant *, restaurant *);
    queue<restaurant *> bfs(restaurant *src);

private:
    minHeap();
    heapRestaurant *heapifyUp(int);
    heapRestaurant *theHeap;
    int theHeapSize;
    int max;
};
