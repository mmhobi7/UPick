#include "App.h"
#include "dataImporter.h"
#include <time.h>
#include <iterator> // std::advance

int main()
{
    srand(time(NULL)); // set random's seed
    App uPick;
    // read in all data
    bool keepPicking = true;
    std::cout << "Welcome to YouPick!" << endl
              << endl;
    std::cout << "Please wait..." << endl;

    dataImporter importer("yelp_business.csv");
    Graph graph;
    importer.read(uPick, graph);
    while (keepPicking)
    {
        std::cout << "Choose a Preferred Cuisine Style [if any]: \n";
        int i = 1;
        for (auto const &x : uPick.getList())
        {
            std::cout << i++ << ": " << x.first << endl;
        }
        std::cout << i++ << ": All" << endl; 
        int option = 0;
        cin >> option;
        char choice;
        std::cout << "Do you wish to enter a zipcode? (Y/N)" << endl;
        cin >> choice;
        int zipcode = 0;
        Restaurant *chosen;
        // if all, generate random cuisine
        int size = 0;
        if (option == 15)
            option = rand() % 15 + 1;
        if (choice == 'Y' || choice == 'y')
        {
            cout << "Enter Zipcode: " << endl;
            cin >> zipcode;
            zipcode = uPick.findZip(zipcode, (next(uPick.getList().begin(), option - 1))->first);
        }
        else
        {
            zipcode = rand() % 99999;
            zipcode = uPick.findZip(zipcode, (next(uPick.getList().begin(), option - 1))->first);
        }
        size = uPick.getZipcodeSize(option, zipcode);
        int randRest = rand() % size;
        chosen = uPick.getRestaurant(option, zipcode, randRest);
        // generate heap and graph from this restaurant
        std::cout << "\nPicking a restaurant now...\n\n";
        std::cout << "We picked: ";
        chosen->print();
        std::cout << "Would you like to see related restaurants? (Y/N)\n\n";
        bool moreRestaurants = true;

        
        auto categoryList = uPick.getCategoryList();
        myGraph = uPick.getLocalGraph(categoryList[option - 1], zipcode, chosen);

        queue<Restaurant*> related = myGraph.bfs(chosen);
        while (moreRestaurants)
        {
            cin >> choice;
            if (choice == 'Y')
            {
                std::cout << "Would you like to see more?" << endl;
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
            }
            else
                moreRestaurants = false;
        }
        std::cout << "Would you like to pick again? (Y/N)" << endl;
        cin >> choice;
        if (choice == 'N' || choice == 'n')
            keepPicking = false;
    }
    std::cout << "Okay! Enjoy your meal!\n";
    return 0;
}
