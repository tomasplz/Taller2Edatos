#include "productNode.h"

// Constructor
/** 
 * @brief Construct a new product Node::product Node object
 * 
 * @param clave
 * @param currentProduct
 * @param next
 * @return productNode
*/
productNode::productNode(string clave, product currentProduct, productNode* next): clave(clave), currentProduct(currentProduct), next(next){}

// Getters
/**
 * @brief Get the Current Product object
 * 
 * @return product
 */
product productNode::getCurrentProduct(){
    return currentProduct;
};

/**
 * @brief Get the Clave object
 * 
 * @return string
 */
string productNode::getClave(){
    return clave;
};

/**
 * @brief Get the Next object
 * 
 * @return productNode*
 */
productNode* productNode::getNext(){
    return next;
};

// Setters
/**
 * @brief Set the Next object
 * 
 * @param next
 * @return void
 */
void productNode::setNext(productNode* next){
    this->next = next;
};

// Destructor
productNode::~productNode(){
}