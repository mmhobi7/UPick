#include "App.hpp"

App::App() {
    SetCategoryList();
}

void App::SetCategoryList() {
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

void App::SetCategorySet() {
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

vector<string> App::GetCategoryList() {
    return categoryList;
}

void App::AddRestaurant(Restaurant* obj) {
    allRestaurants[obj->GetCategory()].push_back(obj);
}
