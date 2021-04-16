#include "Restaurant.h"
class unordered_map {
private:
    int lsize;
    int capacity;
    Restaurant[] values;
    float loadsize=0.80;
    std::hash<int> my_hash;
public:
    unordered_map();
    
    void insert(int val);

    bool has(int val);

    void rem(int val);

    int size();
};
