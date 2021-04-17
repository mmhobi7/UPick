#include "maxHeap.hpp"
#include "App.hpp"

int main()
{
    App uPick;
    std::cout << "Welcome to YouPick!\n\n";
    std::cout << "Choose a Preferred Cuisine Style [if any]:\n";
    for (int i = 1; i <= uPick.categoryList.size(); ++i)
    {
        std::cout << i << ": " << endl;
    }
    std::cout << "1. Italian\n2. Chinese\n3. Indian\n4. American\n5. Mexican\n6. All\n\n";
    std::cout << "Great Choice! Picking a restaurant now...\n\n";
    std::cout << "We picked \"Aman's Place\"! Would you like to see related restaurants? (Y/N)\n\n";
    std::cout << "Okay! Enjoy your meal!\n";
    return 0;
}