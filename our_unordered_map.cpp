#include "our_unordered_map.h"
#include <functional>

our_unordered_map::our_unordered_map()
{
    lsize = 0;
    capacity = 100;
    values = new Restaurant[capacity];
}

void our_unordered_map::insert(Restaurant val)
{
    if (!has(val))
    {
        if (loadsize * capacity > size())
        {
            values[my_hash(val.getAddress())] = val;
            lsize++;
        }
        else
        {
            Restaurant *values2 = new Restaurant[capacity * 2];
            for (int i = 0; i < capacity; i++)
            {
                values2[my_hash(values[i].getAddress())] = values[my_hash(val.getAddress())];
            }
            capacity = capacity * 2;
            values = values2; //TODO: delete values before reassigning
        }
    }
}

bool our_unordered_map::has(Restaurant val)
{
    return (values[my_hash(val.getAddress())].getName() == val.getName());
}

void our_unordered_map::rem(Restaurant val)
{
    if (has(val))
    {
        //values[my_hash(val.getAddress())]=0; // TODO; this if we use it
        lsize--;
    }
}

int our_unordered_map::size()
{
    return lsize;
}
