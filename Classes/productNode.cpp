#include "productNode.h"

/**
 * @brief Constructs a new productNode object.
 * 
 * @param clave The key of the productNode.
 * @param currentProduct The product associated with the productNode.
 * @param next Pointer to the next productNode in the linked list.
 */
productNode::productNode(string clave, product currentProduct, productNode* next): clave(clave), currentProduct(currentProduct), next(next){}

/**
 * @brief Gets the product associated with the productNode.
 * 
 * @return product The product associated with the productNode.
 */
product productNode::getCurrentProduct(){return currentProduct;}

/**
 * @brief Gets the key of the productNode.
 * 
 * @return string The key of the productNode.
 */
string productNode::getClave(){return clave;}

/**
 * @brief Gets the next productNode in the linked list.
 * 
 * @return productNode* The next productNode in the linked list.
 */
productNode* productNode::getNext(){return next;}

/**
 * @brief Sets the next productNode in the linked list.
 * 
 * @param next The next productNode in the linked list.
 */
void productNode::setNext(productNode* next){this->next = next;}

/**
 * @brief Destroys the productNode object.
 * 
 */
productNode::~productNode(){}