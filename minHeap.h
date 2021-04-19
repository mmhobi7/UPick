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
    restaurant *extractMax();
    long long distance(restaurant *, restaurant *);
    queue<restaurant *> bfs(restaurant *src);

private:
    minHeap();
    heapRestaurant *heapifyDown(int);
    heapRestaurant *theHeap;
    int theHeapSize;
    int max;
};
