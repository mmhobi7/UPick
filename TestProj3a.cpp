#include "App.h"
#include "dataImporter.h"
#include <time.h>

int main()
{
    srand(time(NULL)); // set random's seed
    App uPick;
    // read in all data
    bool keepPicking = true;
    std::cout << "Welcome to YouPick! \n\n";
    while (keepPicking) {
        std::cout << "Choose a Preferred Cuisine Style [if any]: \n";
        int i = 1;
        std::cout << i++ << ": American" << endl;
        std::cout << i++ << ": Asian Fusion" << endl;
        std::cout << i++ << ": Bars" << endl;
        std::cout << i++ << ": Breakfast" << endl;
        std::cout << i++ << ": Coffee & Tea" << endl;
        std::cout << i++ << ": Fast Food" << endl;
        std::cout << i++ << ": Halal" << endl;
        std::cout << i++ << ": Indian" << endl;
        std::cout << i++ << ": Latin" << endl;
        std::cout << i++ << ": Mediterranean" << endl;
        std::cout << i++ << ": Mexican" << endl;
        std::cout << i++ << ": Pizza" << endl;
        std::cout << i++ << ": Seafood" << endl;
        std::cout << i++ << ": Vegan" << endl;
        std::cout << i++ << ": All" << endl;
        int option = 0;
        cin >> option;
        char choice;
        std::cout << "Do you wish to enter a zipcode? (Y/N)" << endl;
        cin >> choice;
        int zipcode = 0;
        if (choice == 'Y' || choice == 'y') {
            cout << "Enter Zipcode: " << endl;
            cin >> zipcode;
        }
        std::cout << "\nPicking a restaurant now...\n\n";
        Restaurant* chosen;
        dataImporter importer("yelp_business.csv");
        Graph graph;
        importer.read(uPick, graph);
        // if all, generate random cuisine
        int size = 0;

        if (option == 15)
            option = rand() % 15;
        cout << option << endl;
        if (choice == 'Y' || choice == 'y')
            zipcode = uPick.findZip(zipcode, uPick.getCategoryList()[option - 1]);
        else {
            size = uPick.getCategorySize(option);
            zipcode = rand() % size;
            cout << "random number we generated: " << zipcode << " " << size << endl;
            auto tmp = uPick.getList()[uPick.getCategoryList()[option - 1]].begin();
            advance(tmp, zipcode);
            zipcode = tmp->first;
            cout << "Random zipcode is " << zipcode << endl; //TODO: pad with 0's
        }
        size = uPick.getZipcodeSize(option, zipcode);
        int randRest = rand() % size;
        chosen = uPick.getRestaurant(option, zipcode, randRest);

        // generate heap and graph from this restaurant

        std::cout << "We picked: ";
        chosen->print();
        std::cout << "Would you like to see related restaurants? (Y/N)\n\n";
        bool moreRestaurants = true;

        // queue<Restaurant*> related = tmp4.bfs(chosen);

        while (moreRestaurants)
        {
            cin >> choice;
            if (choice == 'Y')
            {
                std::cout << "Would you like to see more?" << endl;
                //print out 5 more choices while maxHeap is not empty
                /*if(related.size() > 5) {
                        size = 5;
                    } else {
                        size = related.size();
                    }
                    for(int i = 0; i < size; i++) {
                        related.front()->print();
                        related.pop();
                    }
                std::cout << "Would you like to see more?" << endl;
                    }*/
            }
            else
                moreRestaurants = false;
        }
        std::cout << "Would you like to pick again? (Y/N)" << endl;
        cin >> option;
        if (option == 'N' || option == 'n')
            keepPicking = false;
    }
    std::cout << "Okay! Enjoy your meal!\n";
    return 0;
}
