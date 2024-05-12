#include "product.h"

/**
 * @brief Constructs a new product object.
 * 
 * @param name The name of the product.
 * @param category The category of the product.
 * @param subCategory The sub-category of the product.
 * @param price The price of the product.
 * @param id The ID of the product.
 */
product::product(string name, string category, string subCategory, int price, int id){
    this->name = name;
    this->category = category;
    this->subCategory = subCategory;
    this->price = price;
    this->id = id;
}

/**
 * @brief Sets the name of the product.
 * 
 * @param name The name of the product.
 */
void product::setName(string name){this->name = name;}

/**
 * @brief Gets the name of the product.
 * 
 * @return string The name of the product.
 */
string product::getName(){return name;}

/**
 * @brief Sets the category of the product.
 * 
 * @param category The category of the product.
 */
void product::setCategory(string category){this->category = category;}

/**
 * @brief Gets the category of the product.
 * 
 * @return string The category of the product.
 */
string product::getCategory(){return category;}

/**
 * @brief Sets the sub-category of the product.
 * 
 * @param subCategory The sub-category of the product.
 */
void product::setSubCategory(string subCategory){this->subCategory = subCategory;}

/**
 * @brief Gets the sub-category of the product.
 * 
 * @return string The sub-category of the product.
 */
string product::getSubCategory(){return subCategory;}

/**
 * @brief Sets the price of the product.
 * 
 * @param price The price of the product.
 */
void product::setPrice(int price){this->price = price;}

/**
 * @brief Gets the price of the product.
 * 
 * @return int The price of the product.
 */
int product::getPrice(){return price;}

/**
 * @brief Sets the ID of the product.
 * 
 * @param id The ID of the product.
 */
void product::setId(int id){this->id = id;}

/**
 * @brief Gets the ID of the product.
 * 
 * @return int The ID of the product.
 */
int product::getId(){ return id;}

/**
 * @brief Destroys the product object.
 * 
 */
product::~product(){}