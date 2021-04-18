#include "App.h"
#include "dataImporter.h"

int main()
{
    srand(time(NULL)); // set random's seed
    App uPick;
    // read in all data
    std::cout << "Welcome to YouPick! \n\n";
    std::cout << "Choose a Preferred Cuisine Style [if any]: \n";
    int i;
    for (i = 1; i <= uPick.getCategoryList().size(); ++i)
    {
        std::cout << i << ": " << uPick.getCategoryList()[i - 1] << endl;
    }
    std::cout << i++ << ": "
              << "All" << endl;
    std::cout << endl;
    int option = 0;
    cin >> option;
    char choice;
    Restaurant *chosen;
    dataImporter importer("/Users/wylyyant/CLionProjects/YouPickProject/yelp_business.csv");
    Graph tmp4;
    importer.read(uPick, tmp4);
    // if all, generate random cuisine
    std::cout << "Do you wish to enter a zipcode? (Y/N)" << endl;
    cin >> choice;
    int zipcode = 0;
    int size = 0;
    int thesize = 0;
    auto tmp3 = uPick.getList().begin();
    /*cout << "here: " << tmp3->first << endl;
    advance(tmp3,2);
    cout << "here: " << tmp3->first << endl; */

    /*for (auto tmp2 = uPick.getList().begin(); tmp2 != uPick.getList().end(); tmp2++)
    {
        cout << "here: " << tmp2->first << endl;
        // for (auto j = (uPick.getList()[i->second]).begin(); j != (uPick.getList()[i->second]).end(); j++)
        // {
        //     cout << j->first << " | " << j->second.size() << " | " << thesize++ << endl;
        // }
    } */

    if (option == 15)
    {
        option = rand() % 15;
    }
    if (choice == 'Y' || choice == 'y')
    {
        cin >> zipcode;
        zipcode = uPick.findZip(zipcode, uPick.getCategoryList()[option - 1]);
    }
    else
    {
        size = uPick.getCategorySize(option);
        zipcode = rand() % size;
        cout << "random number we generated: " << zipcode << " " << size << endl;
        //auto tmp = uPick.getList()[uPick.getCategoryList()[option - 1]].begin();
        auto tmp = uPick.getList();
        auto categoryList = uPick.getCategoryList();
        auto curr = tmp[categoryList[option - 1]].begin();
        advance(curr, zipcode);
        zipcode = curr->first;
        cout << "Random zipcode is " << zipcode << endl; //TODO: pad with 0's
    }
    size = uPick.getZipcodeSize(option, zipcode);
    int randRest = rand() % size;
    chosen = uPick.getRestaurant(option, zipcode, randRest);

    // generate heap and graph from this restaurant

    std::cout << "\nGreat Choice! Picking a restaurant now...\n\n";
    std::cout << "We picked " << chosen->getName() << endl
              << "Would you like to see related restaurants? (Y/N)\n\n";
    bool moreRestaurants = true;

    queue<Restaurant*> related = tmp4.bfs(chosen);

    while (moreRestaurants)
    {
        cin >> choice;
        if (choice == 'Y' || choice == 'y')
        {
            //print out 5 more choices while maxHeap is not empty
            if(related.size() > 5) {
                    size = 5;
                } else {
                    size = related.size();
                }
                for(int i = 0; i < size; i++) {
                    related.front()->print();
                    related.pop();
                }
            std::cout << "Would you like to see more?" << endl;
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
