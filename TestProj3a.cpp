#include "App.h"
#include "dataImporter.h"

int main()
{
    App uPick;
    // read in all data
    std::cout << "Welcome to YouPick!\n\n";
    std::cout << "Choose a Preferred Cuisine Style [if any]:\n";
    for (int i = 1; i <= uPick.GetCategoryList().size(); ++i) {
        std::cout << i << ": " << uPick.GetCategoryList()[i-1] << endl;
    }
    std::cout << endl;
    int option = 0;
    cin >> option;
    Restaurant* chosen;
    if (option == 1) {

    }
    else if (option == 2) {

    }
    else if (option == 3) {

    }
    else if (option == 4) {

    }
    else if (option == 5) {

    }
    else if (option == 6) {

    }
    else if (option == 7) {

    }
    else if (option == 8) {

    }
    else if (option == 9) {

    }
    std::cout << "\nGreat Choice! Picking a restaurant now...\n\n";
    std::cout << "We picked \" << " << "\"! Would you like to see related restaurants? (Y/N)\n\n";
    bool moreRestaurants = true;
    char choice;
    while (moreRestaurants) {
        cin >> choice;
        if (choice == 'Y') {
            std::cout << "Would you like to see more?" << endl;
            //print out 5 more choices while maxHeap is not empty
        }
        else
            moreRestaurants = false;
    }
    std::cout << "Okay! Enjoy your meal!\n";
}
