#include "product.h"

// Constructor
/**
 * @brief Construct a new product::product object
 * 
 * @param name
 * @param category
 * @param subCategory
 * @param price
 * @param id
 * @return product
*/
product::product(string name, string category, string subCategory, int price, int id){
    this->name = name;
    this->category = category;
    this->subCategory = subCategory;
    this->price = price;
    this->id = id;
}

// Setters
/**
 * @brief Set the Name object
 * 
 * @param name
 * @return void
 */
void product::setName(string name){this->name = name;}
/**
 * @brief Set the Category object
 * 
 * @param category
 * @return void
 */
void product::setCategory(string category){this->category = category;}
/**
 * @brief Set the Sub Category object
 * 
 * @param subCategory
 * @return void
 */
void product::setSubCategory(string subCategory){this->subCategory = subCategory;}
/**
 * @brief Set the Price object
 * 
 * @param price
 * @return void
 */
void product::setPrice(int price){this->price = price;}
/**
 * @brief Set the Id object
 * 
 * @param id
 * @return void
 */
void product::setId(int id){this->id = id;}

// Getters
/**
 * @brief Get the Name object
 * 
 * @return string
 */
string product::getName(){return name;}
/**
 * @brief Get the Category object
 * 
 * @return string
 */
string product::getCategory(){return category;}
/**
 * @brief Get the Sub Category object
 * 
 * @return string
 */
string product::getSubCategory(){return subCategory;}
/**
 * @brief Get the Price object
 * 
 * @return int
 */
int product::getPrice(){return price;}
/**
 * @brief Get the Id object
 * 
 * @return int
 */
int product::getId(){ return id;}

// Destructor
product::~product(){}