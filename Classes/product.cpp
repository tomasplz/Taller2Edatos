#include "product.h"

product::product(string name, string category, string subCategory, int price, int id){
    this->name = name;
    this->category = category;
    this->subCategory = subCategory;
    this->price = price;
    this->id = id;
}

void product::setName(string name){this->name = name;}
string product::getName(){return name;}
void product::setCategory(string category){this->category = category;}
string product::getCategory(){return category;}
void product::setSubCategory(string subCategory){this->subCategory = subCategory;}
string product::getSubCategory(){return subCategory;}
void product::setPrice(int price){this->price = price;}
int product::getPrice(){return price;}
void product::setId(int id){this->id = id;}
int product::getId(){ return id;}