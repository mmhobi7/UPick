#pragma once
#include "heapRestaurant.h"
// credits Muhamed Hobi Stepik 6.1.1

class maxHeap
{
public:
    maxHeap(int);
    ~maxHeap();
    void heapPrint();
    int getSize();
    void insert(heapRestaurant);
    Restaurant *extractMax();
    long long distance(Restaurant *, Restaurant *);
    queue<Restaurant *> bfs(Restaurant* src);

private:
    maxHeap();
    heapRestaurant *heapifyDown(int);
    heapRestaurant *theHeap;
    int theHeapSize;
    int max;
};
