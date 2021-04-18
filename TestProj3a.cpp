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
    // dataImporter importer("/Users/wylyyant/CLionProjects/YouPickProject/yelp_business.csv");
    // Graph tmp4;
    // importer.read(uPick, tmp4);
    dataImporter importer("yelp_business.csv");
    Graph tmp;
    importer.read(uPick, tmp);
    // if all, generate random cuisine
    std::cout << "Do you wish to enter a zipcode? (Y/N)" << endl;
    cin >> choice;
    int zipcode = 0;
    int size = 0;
    int thesize = 0;
    auto tmp3 = uPick.getList().begin();

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
        auto tmp = uPick.getList()[uPick.getCategoryList()[option - 1]].begin();
        advance(tmp, zipcode);
        zipcode = tmp->first;
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
    std::cout << "Okay! Enjoy your meal!\n";
    return 0;
}
