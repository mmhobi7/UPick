#include "App.h"

App::App()
{
    setCategoryList();
}

void App::setCategoryList()
{
    categoryList.push_back("American");
    categoryList.push_back("Asian");
    categoryList.push_back("Bars");
    categoryList.push_back("Breakfast");
    categoryList.push_back("Fast");
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
    else if (s == "Chinese" || s == "Japanese" || s == "Korean")
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
}
