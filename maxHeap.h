#pragma once
#include "Restaurant.h"
// credits Muhamed Hobi Stepik 6.1.1

class maxHeap
{
public:
    maxHeap(Restaurant r[]);
    ~maxHeap();
    void heapRemove();
    int readHeap();
    void heapPrint();
    int getSize();
    int front();

private:
    void balance();
    int *theHeap;
    int theHeapSize;


};
