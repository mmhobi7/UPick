#include "App.h"

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
    allRestaurants[obj->getCategory()][obj->getZipcode()].push_back(obj);
    //zipcodes.push_back(obj->getZipcode());
}

int App::findZip(int zip, string cat) {
    if (allRestaurants[cat].find(zip) != allRestaurants[cat].end())
        return zip;
    else {
        int minZip = INT_MAX;
        for (auto iter = allRestaurants[cat].begin(); iter != allRestaurants[cat].begin(); ++iter) {
            if (abs(zip - iter->first) < minZip)
                minZip = zip;
        }
        return zip;
    }
}

int App::getCategorySize(int category) {
    return allRestaurants[categoryList[category - 1]].size();
}

int App::getZipcodeSize(int category, int zipcode) {
    return allRestaurants[categoryList[category - 1]][zipcode].size();
}

Restaurant *App::getRestaurant(int category, int zipcode, int index) {
    return allRestaurants[categoryList[category - 1]][zipcode][index];
}

