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
    Restaurant *extractMax();

private:
    heapRestaurant *heapifyDown(int);
    heapRestaurant *theHeap;
    int theHeapSize;
};
