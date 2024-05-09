#pragma once
#include <iostream>
using namespace std;
class product{
private:
    string name;
    string category;
    string subCategory;
    int price;
    int id;
public:
    product(string name, string category, string subCategory, int price, int id);
    void setName(string name);
    string getName();
    void setCategory(string category);
    string getCategory();
    void setSubCategory(string subCategory);
    string getSubCategory();
    void setPrice(int price);
    int getPrice();
    void setId(int id);
    int getId();
};