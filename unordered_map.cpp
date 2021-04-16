#include "unordered_map.h"
#include <functional>

    unordered_map::unordered_map() {
        lsize=0;
        capacity=100;
        values = new Restaurant[capacity];
    }

    void unordered_map::insert(Restaurant val) {
        if(!has(val)){
            if(loadsize*capacity>size()){
                values[my_hash(val)]=val;
                lsize++;
            } else {
                int *values2 = new int[capacity*2];
                for(int i=0; i<capacity; i++){
                    values2[my_hash(values[i])]=
                }
                capacity=capacity*2;
            }
        }
    }

    bool unordered_map::has(int val) {
        return (values[my_hash(val)]==val);
    }

    void unordered_map::rem(int val) {
        if(has(val)){
            values[my_hash(val)]=0;
            lsize--;
        }
    }

    int unordered_map::size() {
        return lsize;
    }
};
