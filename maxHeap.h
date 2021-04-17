#pragma once
#include "Restaurant.h"
// credits Muhamed Hobi Stepik 6.1.1

class maxHeap
{
public:
    maxHeap(int);
    ~maxHeap();
    void heapRemove();
    int readHeap();
    void heapPrint();
    int getSize();
    Restaurant extractMax();

private:
    void balance();
    Restaurant *theHeap;
    int theHeapSize;
};
