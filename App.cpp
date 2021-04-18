#include "App.h"
#include <climits>

App::App()
{
    setCategoryList();
    setCategorySet();
}

void App::setCategoryList()
{
    categoryList.push_back("American");
    categoryList.push_back("Asian Fusion");
    categoryList.push_back("Bars");
    categoryList.push_back("Breakfast");
    categoryList.push_back("Coffee & Tea");
    categoryList.push_back("Fast Food");
    categoryList.push_back("Halal");
    categoryList.push_back("Indian");
    categoryList.push_back("Latin");
    categoryList.push_back("Mediterranean");
    categoryList.push_back("Mexican");
    categoryList.push_back("Pizza");
    categoryList.push_back("Seafood");
    categoryList.push_back("Vegan");
}

void App::setCategorySet()
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
}

vector<string> App::getCategoryList()
{
    return categoryList;
}

string App::findCategory(string s)
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

void App::addRestaurant(Restaurant *obj)
{
    // cout << "Eahttt tjtjt: " << obj->getCategory() << endl;
    allRestaurants[obj->getCategory()][obj->getZipcode()].push_back(obj);
    //zipcodes.push_back(obj->getZipcode());
}

int App::findZip(int zip, string cat)
{
    if (allRestaurants[cat].find(zip) != allRestaurants[cat].end())
        return zip;
    else
    {
        int minZip = INT_MAX;
        for (auto iter = allRestaurants[cat].begin(); iter != allRestaurants[cat].end(); ++iter)
        {
            if (abs(zip - iter->first) < minZip)
                minZip = iter->first;
        }
        return minZip;
    }
}

int App::getCategorySize(int category)
{
    return allRestaurants[categoryList[category - 1]].size();
}

int App::getListSize()
{
    return allRestaurants.size();
}

int App::getListZipcodeSize(string key)
{
    return allRestaurants[key].size();
}

int App::getZipcodeSize(int category, int zipcode) {
    zipcode = findZip(zipcode, getCategoryList()[category - 1]);
    return allRestaurants[categoryList[category - 1]][zipcode].size();
}

Restaurant *App::getRestaurant(int category, int zipcode, int index)
{
    return allRestaurants[categoryList[category - 1]][zipcode][index];
}

unordered_map<string, std::map<int, vector<Restaurant *>>> App::getList()
{
    return allRestaurants;
}

Graph& App::getLocalGraph(string cat, int zipcode, Restaurant* source) {
    Graph myGraph;
    auto it = allRestaurants[cat].begin();
    for(it = allRestaurants[cat].begin(); it != allRestaurants[cat].end(); it++) {
        if(it->first == zipcode) {
            break;
        }
    }
    
    
    vector<Restaurant*> restInZip = allRestaurants[cat][zipcode];
    for(int i = 0; i < restInZip.size(); i++) {
        for(int j = 1; j < restInZip.size(); j++) {
            if(!myGraph.isEdge(restInZip[i], restInZip[j]))
                myGraph.insertEdge(restInZip[i], restInZip[j], distance(restInZip[i], restInZip[j]));
        }
    }
}

maxHeap& App::getLocalHeap(string cat, int zipcode, Restaurant* source) {
    maxHeap myHeap;
    auto it = allRestaurants[cat].begin();
    for(it = allRestaurants[cat].begin(); it != allRestaurants[cat].end(); it++) {
        if(it->first == zipcode) {
            break;
        }
    }
    
    vector<Restaurant*> restInZip = allRestaurants[cat][zipcode];
    for(int i = 0; i < restInZip.size(); i++) {
        for(int j = 1; j < restInZip.size(); j++) {
            if(!myHeap.isEdge(restInZip[i], restInZip[j]))
                myHeap.insertEdge(restInZip[i], restInZip[j], distance(restInZip[i], restInZip[j]));
        }
    }
}
