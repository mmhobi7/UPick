#include "App.h"
#include "dataImporter.h"

int main()
{
    App uPick;
    // read in all data
    std::cout << "Welcome to YouPick!\n\n";
    std::cout << "Choose a Preferred Cuisine Style [if any]:\n";
    for (int i = 1; i <= uPick.getCategoryList().size(); ++i) {
        std::cout << i << ": " << uPick.getCategoryList()[i-1] << endl;
    }
    std::cout << endl;
    int option = 0;
    cin >> option;
    Restaurant* chosen;
    dataImporter importer("/home/aaahh/p3/UPick/yelp_business.csv");
    Graph tmp;
    importer.read(uPick, tmp);
    // if all, generate random cuisine
        if(option == 14) {
            option = rand() % 13;
        }

        int size = uPick.getCategorySize(option);
        int randZipCode = rand() % size;

        size = uPick.getZipcodeSize(option, randZipCode);
        int randRest = rand() % size;
        chosen = uPick.getRestaurant(option, randZipCode, randRest);
    // generate heap and graph from this restaurant
    
    
    std::cout << "\nGreat Choice! Picking a restaurant now...\n\n";
    std::cout << "We picked \" << chosen->getName() << "\"! Would you like to see related restaurants? (Y/N)\n\n";
    bool moreRestaurants = true;
    char choice;
    queue<Restaurant*> related = myGraph.bfs(chosen);
    
    while (moreRestaurants) {
            cin >> choice;
            if (choice == 'Y') {
                std::cout << "Would you like to see more?" << endl;
                //print out 5 more choices while maxHeap is not empty
                for(int i = 0; i < 5; i++) {
                    related.front()->print();
                    related.pop();
                }
            }
            else
                moreRestaurants = false;
        }
    std::cout << "Okay! Enjoy your meal!\n";
    return 0;
}



















/*#include "maxHeap.h"
#include "Restaurant.h"
#include "dataImporter.h"
#include "App.h"
#include<iostream>
using namespace std;

enum cuisines {
    ITALIAN = 1,
    CHINESE = 2,
    INDIAN = 3,
    AMERICAN = 4,
    MEXICAN = 5,
    ALL = 6
};

int main()
{
    // UI stuffs



    // Menu Item Logic
    // returning top element of max heap of that cuisine
    // FIXME:: BUILD MAP
/*
    map<cuisines, maxHeap> cuisine_map;
    int userChoice = 1;
    char cont = 'Y';
    cin >> userChoice;


    maxHeap currHeap = cuisine_map[userChoice];
    Restaurant currRestaurant = currHeap.front();
    currHeap.heapRemove();

    while(cont == 'Y') {
        currRestaurant = currHeap.front();
        currHeap.heapRemove();

        cout << "We picked \"" << currRestaurant.getName() << "\"! Would you like to see related restaurants? (Y/N)"
             << endl;
        cin >> cont;
    }

    cout << "Okay! Enjoy your meal!" << endl;
    return 0;

    // initialize a set to pass in
    App myApp;
    Graph myGraph;
    dataImporter myReader("/Users/wylyyant/CLionProjects/YouPickProject/yelp_business.csv");
    myReader.read(myApp, myGraph);

    cout << "SIZE OF RESTAURANT LIST : " << myApp.GetRestaurantListSize() << endl;
} */
