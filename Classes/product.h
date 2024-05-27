#pragma once
#include <iostream>
using namespace std;
class product{
private:
    string name; // Name
    string category; // Category
    string subCategory; // Subcategory
    int price; // Price
    int id; // Id
public:
    product(string name, string category, string subCategory, int price, int id); // Constructor
    void setName(string name); // Set name
    string getName(); // Get name
    void setCategory(string category); // Set category
    string getCategory(); // Get category
    void setSubCategory(string subCategory); // Set subcategory
    string getSubCategory(); // Get subcategory
    void setPrice(int price); // Set price
    int getPrice(); // Get price
    void setId(int id); // Set id
    int getId(); // Get id
    ~product(); // Destructor
};