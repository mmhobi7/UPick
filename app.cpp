#include "app.h"
#include <climits>
#include <map>
#include <iterator>

app::app()
{
    setCategorySet();
}

void app::setCategorySet()
{
    categorySet.insert("American");
    categorySet.insert("Asian");
    categorySet.insert("Bars");
    categorySet.insert("Breakfast");
    categorySet.insert("Coffee");
    categorySet.insert("Fast");
    categorySet.insert("Halal");
    categorySet.insert("Indian");
    categorySet.insert("Latin");
    categorySet.insert("Mediterranean");
    categorySet.insert("Mexican");
    categorySet.insert("Pizza");
    categorySet.insert("Seafood");
    categorySet.insert("Vegan");
    categorySet.insert("All");
}

set<string> app::getCategorySet()
{
    return categorySet;
}

string app::findCategory(string s)
{
    if (categorySet.find(s) != categorySet.end())
    {
        return s;
    }
    else if (s == "Chinese" || s == "Japanese" || s == "Korean" || s == "Thai")
    {
        return "Asian";
    }
    else if (s == "Greek")
    {
        return "Mediterranean";
    }
    else if (s == "Mexican" || s == "Cuban" || s == "Tex-Mex" || s == "Peruvian" || s == "Colombian")
    {
        return "Latin";
    }
    else if (s == "Vegetarian")
    {
        return "Vegan";
    }
    else
        return "";
}

void app::addRestaurant(restaurant *obj)
{
    // cout << "Eahttt tjtjt: " << obj->getCategory() << endl;
    allRestaurants[obj->getCategory()][obj->getZipcode()].push_back(obj);
    allRestaurants["All"][obj->getZipcode()].push_back(obj);
    //zipcodes.push_back(obj->getZipcode());
}

int app::findZip(int zip, string cat)
{
    if (allRestaurants[cat].find(zip) != allRestaurants[cat].end())
        return zip;
    else
    {
        int minZip = INT_MAX;
        for (auto iter = allRestaurants[cat].begin(); iter != allRestaurants[cat].end(); ++iter)
        {
            //cout << abs(iter->first - zip) << endl;
            if (abs(iter->first - zip) < minZip)
            {
                //cout << iter->first << endl;
                minZip = iter->first;
            }
        }
        return minZip;
    }
}

int app::getCategorySize(int category)
{
    return allRestaurants[(next(allRestaurants.begin(), category))->first].size();
}

int app::getListSize()
{
    return allRestaurants.size();
}

int app::getListZipcodeSize(string key)
{
    return allRestaurants[key].size();
}

int app::getZipcodeSize(int category, int zipcode)
{
    zipcode = findZip(zipcode, (next(allRestaurants.begin(), category - 1))->first);
    return allRestaurants[(next(allRestaurants.begin(), category - 1))->first][zipcode].size();
}

restaurant *app::getRestaurant(int category, int zipcode, int index)
{
    return allRestaurants[(next(allRestaurants.begin(), category - 1))->first][zipcode][index];
}

unordered_map<string, std::map<int, vector<restaurant *>>> app::getList()
{
    return allRestaurants;
}

graph app::getLocalGraph(string cat, int zipcode, restaurant *source)
{
    graph myGraph;
    int k = 0;
    int end = distance(allRestaurants[cat].find(zipcode), allRestaurants[cat].end());
    // std::map<string, int>::iterator it = myMap.find("myKey");
    while (myGraph.getSize() < 26)
    {
        vector<restaurant *> restInZip = allRestaurants[cat][next(allRestaurants[cat].begin(), distance(allRestaurants[cat].begin(), allRestaurants[cat].find(zipcode)) + k)->first];
        for (int i = 0; i < restInZip.size(); i++)
        {
            for (int j = 1; j < restInZip.size(); j++)
            {
                if (!myGraph.isEdge(restInZip[i], restInZip[j]))
                    myGraph.insertEdge(restInZip[i], restInZip[j], distance(restInZip[i], restInZip[j]));
            }
        }
        // (next(uPick.getList().begin(), option - 1))->first

        k++;
        if (k > end - 2)
        {
            cout << "BREAK"<< endl;
            break;
        }
        restaurant *newZip = allRestaurants[cat][next(allRestaurants[cat].begin(), distance(allRestaurants[cat].begin(), allRestaurants[cat].find(zipcode)) + k)->first][0];
        restaurant *oldZip = restInZip[restInZip.size() - 1];

        myGraph.insertEdge(newZip, oldZip, myGraph.distance(newZip, oldZip));
    }
    return myGraph;
}

maxHeap app::getLocalHeap(string cat, int zipcode, restaurant *source)
{
    maxHeap myHeap(26);
    int k = 0;
    int end = distance(allRestaurants[cat].find(zipcode), allRestaurants[cat].end());
    // std::map<string, int>::iterator it = myMap.find("myKey");
    while (myHeap.getSize() < 26)
    {
        vector<restaurant *> restInZip = allRestaurants[cat][next(allRestaurants[cat].begin(), distance(allRestaurants[cat].begin(), allRestaurants[cat].find(zipcode)) + k)->first];
        for (int i = 0; i < restInZip.size(); i++)
        {
            if (myHeap.getSize() < 26)
            {
                heapRestaurant tmp(restInZip[i], myHeap.distance(source, restInZip[i]));
                myHeap.insert(tmp);
            }
        }
        k++;
        if (k == end - 1)
        {
            break;
        }
    }
    return myHeap;
}
