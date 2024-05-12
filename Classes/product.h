#pragma once
#include <iostream>
using namespace std;
class product{
private:
    string name; // Product name.
    string category; // Product category.
    string subCategory; // Product subcategory.
    int price; // Product price.
    int id; // Product id.
public:
    product(string name, string category, string subCategory, int price, int id); // Constructor with all the attributes as parameters.
    void setName(string name); // Set name method with a string as a parameter.
    string getName(); // Get name method.
    void setCategory(string category); // Set category method with a string as a parameter.
    string getCategory(); // Get category method.
    void setSubCategory(string subCategory); // Set subcategory method with a string as a parameter.
    string getSubCategory(); // Get subcategory method.
    void setPrice(int price); // Set price method with an integer as a parameter.
    int getPrice(); // Get price method.
    void setId(int id); // Set id method with an integer as a parameter.
    int getId(); // Get id method.
    ~product(); // Destructor.
};