#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

struct App {
    unordered_map<string,Restaurant> allRestaurants; // make this the unordered_set<std::pair<string,Restaurant>>
    vector<Category> categoryList;
};
class Category {
    unordered_map<string, Restaurant> restaurantList; // make this an unordered_set
    vector<string> listNames;
    priority_queue<Restaurant> maxHeap; // based on rating. comparator uses restaurant.rating
};
class Restaurant {
    string ID;
    string name;
    double rating;
    string address;
    string category;
public:
};

int main()
{
    App uPick;
    std::cout << "Welcome to YouPick!\n\n";
    std::cout << "Choose a Preferred Cuisine Style [if any]:\n";
    for (int i = 1; i <= uPick.categoryList.size(); ++i) {
        std::cout << i << ": " <<  endl;
    }
    std::cout << "1. Italian\n2. Chinese\n3. Indian\n4. American\n5. Mexican\n6. All\n\n";
    std::cout << "Great Choice! Picking a restaurant now...\n\n";
    std::cout << "We picked \"Aman's Place\"! Would you like to see related restaurants? (Y/N)\n\n";
    std::cout << "Okay! Enjoy your meal!\n";
}
