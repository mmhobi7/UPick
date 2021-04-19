#include "app.h"
#include "dataImporter.h"
#include <time.h>
#include <iterator> // std::advance

int main()
{
    srand(time(NULL)); // set random's seed
    app uPick;
    bool keepPicking = true;
    std::cout << "Welcome to YouPick!" << endl
              << endl;
    std::cout << "Please wait..." << endl
              << endl;

    dataImporter importer("yelp_business.csv");
    importer.read(uPick); // read in all data
    while (keepPicking)
    {
        std::cout << "Choose a Preferred Cuisine Style [if any]: \n";
        int i = 1;
        for (auto const &x : uPick.getList())
        {
            std::cout << i++ << ": " << x.first << endl;
        }
        std::cout << i++ << ": Random" << endl
                  << endl;
        int option = 0;
        std::cin >> option;
        char choice;
        std::cout << endl
                  << "Do you wish to enter a ZIP code? (Y/N)" << endl;
        cin >> choice;
        int zipcode = 0;
        restaurant *chosen;
        // if all, generate random cuisine
        int size = 0;
        if (option == 16)
            option = rand() % 16 + 1;
        if (choice == 'Y' || choice == 'y')
        {
            cout << endl
                 << "Enter ZIP code: " << endl;
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

        std::cout << "\nPicking a restaurant now...\n\n";
        std::cout << "Mmm! " << next(uPick.getList().begin(), option - 1)->first << "! We picked ";
        chosen->print();
        std::cout << endl
                  << "Would you like to see related restaurants? (Y/N)\n";
        bool moreRestaurants = true;

        // generate heap and graph from this restaurant
        graph graph = uPick.getLocalGraph((next(uPick.getList().begin(), option - 1))->first, zipcode, chosen);
        minHeap heap = uPick.getLocalHeap((next(uPick.getList().begin(), option - 1))->first, zipcode, chosen);

        queue<restaurant *> relatedGraph = graph.bfs(chosen);
        relatedGraph.pop();
        queue<restaurant *> relatedHeap = heap.bfs(chosen);
        relatedHeap.pop();

        queue<restaurant *> related = graph.bfs(chosen);
        related.pop();
        int counter = 1;
        while (moreRestaurants)
        {
            cin >> choice;
            cout << endl;
            if (choice == 'Y' || choice == 'y')
            {
                if (counter == 1)
                    cout << "Here are some more " << next(uPick.getList().begin(), option - 1)->first << " restaurants near you.\n\n";
                //print out 5 more choices while minHeap is not empty
                if (relatedGraph.size() > 5)
                {
                    size = 5;
                }
                else
                {
                    size = relatedGraph.size();
                }
                for (int i = 0; i < size; i++)
                {
                    cout << counter++ << ": ";
                    related.front()->print();
                    cout << endl;
                    related.pop();
                }
                if (relatedGraph.empty())
                {
                    std::cout << endl
                              << "No more related restaurants!" << endl
                              << endl;
                    break;
                }
                std::cout << "Would you like to see more? (Y/N)" << endl;
            }
            else
                moreRestaurants = false;
        }
        std::cout << "Would you like to pick another restaurant? (Y/N)" << endl;
        cin >> choice;
        if (choice == 'N' || choice == 'n')
            keepPicking = false;
    }
    std::cout << "Enjoy your meal! Thank you for using YouPick.\n";
    return 0;
}
