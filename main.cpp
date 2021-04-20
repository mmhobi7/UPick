#include "app.h"
#include "dataImporter.h"
#include <time.h>
#include <iterator> // std::advance
#include <chrono>
#include <string.h>

#define NAME "YouPick"
#define VERSION "0.1.2"

void helpmenu()
{
    fprintf(stderr, "%s v%s \n\n", NAME, VERSION);
    fprintf(stderr, "Options:\n \
    --debug : Enable debug messages\n \
    --help  : Display this messages\n\n");
}

int main(int argc, char **argv)
{
    srand(time(NULL)); // set random's seed
    bool userContinue = true;
    bool debug = false;
    if (argc > 1)
    {
        if (strcmp(argv[1], "--Debug") == 0 || strcmp(argv[1], "--debug") == 0)
        {
            debug = true;
        }
        else
        {
            helpmenu();
            exit(0);
        }
    }
    app uPick;
    std::cout << "Welcome to YouPick!" << endl
              << endl;
    std::cout << "Please wait..." << endl
              << endl;

    dataImporter importer("yelp_business.csv");
    importer.read(uPick); // read in all data
    while (userContinue)
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
            option = (rand() % 15) + 1;
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
        // generate heap and graph from this restaurant
        std::cout << "\nDo you want to use a Graph or a Min Heap?\n1. Graph\n2. Min Heap\n";
        int selector;
        std::cin >> selector;
        queue<restaurant *> relatedGraph;

        auto passZero = chrono::high_resolution_clock::now();
        auto passOne = chrono::high_resolution_clock::now();
        auto passTwo = chrono::high_resolution_clock::now();
        float timeGraph, timeHeap, timeGraph2, timeHeap2;

        passZero = chrono::high_resolution_clock::now();
        graph graph = uPick.getLocalGraph((next(uPick.getList().begin(), option - 1))->first, zipcode, chosen);
        passOne = chrono::high_resolution_clock::now();
        minHeap heap = uPick.getLocalHeap((next(uPick.getList().begin(), option - 1))->first, zipcode, chosen);
        passTwo = chrono::high_resolution_clock::now();

        timeGraph = (chrono::duration_cast<chrono::nanoseconds>(passOne - passZero).count());
        timeHeap = (chrono::duration_cast<chrono::nanoseconds>(passTwo - passOne).count());
        if (debug)
        {
            cout << endl
                 << "Time Graph: " << timeGraph << " nanoseconds. Time Heap: " << timeHeap << " nanoseconds." << endl;
        }
        passZero = chrono::high_resolution_clock::now();
        queue<restaurant *> graphQueue = graph.bfs(chosen);
        passOne = chrono::high_resolution_clock::now();
        queue<restaurant *> heapQueue = heap.bfs(chosen);
        passTwo = chrono::high_resolution_clock::now();
        if (debug)
        {
            timeGraph2 = (chrono::duration_cast<chrono::nanoseconds>(passOne - passZero).count());
            timeHeap2 = (chrono::duration_cast<chrono::nanoseconds>(passTwo - passOne).count());

            cout << "Time Graph bfs: " << timeGraph2 << " nanoseconds. Time Heap extract min: " << timeHeap2 << " nanoseconds." << endl;
            cout << "Time Graph total: " << timeGraph + timeGraph2 << " nanoseconds. Time Heap total: " << timeHeap + timeHeap2 << " nanoseconds." << endl;
            cout << "The Heap ran " << (timeGraph + timeGraph2) - (timeHeap + timeHeap2) << " nanoseconds faster," << endl;
            cout << "Or " << (((timeGraph + timeGraph2) - (timeHeap + timeHeap2)) / (timeGraph + timeGraph2)) * 100.0 << "% faster than the Graph." << endl;
        }
        if (selector == 1)
        {
            relatedGraph = graphQueue;
        }
        else
        {
            relatedGraph = heapQueue;
        }

        relatedGraph.pop();
        std::cout << endl
                  << "Would you like to see related restaurants? (Y/N)\n";
        bool moreRestaurants = true;

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
                    relatedGraph.front()->print();
                    cout << endl;
                    relatedGraph.pop();
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
            userContinue = false;
    }
    std::cout << "Enjoy your meal! Thank you for using YouPick.\n\n";
    return 0;
}