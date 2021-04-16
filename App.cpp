#include "App.h"

App::App() {
    SetCategoryList();
}

void App::SetCategoryList() {
    categoryList.push_back("American");
    categoryList.push_back("Asian Fusion");
    categoryList.push_back("Breakfast");
    categoryList.push_back("Fast Food");
    categoryList.push_back("Halal");
    categoryList.push_back("Indian");
    categoryList.push_back("Latin American");
    categoryList.push_back("Mediterranean");
    categoryList.push_back("Vegan");
}

vector<string> App::GetCategoryList() {
    return categoryList;
}
