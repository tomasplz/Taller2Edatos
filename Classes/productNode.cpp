#include "productNode.h"

productNode::productNode(string clave, product currentProduct, productNode* next): clave(clave), currentProduct(currentProduct), next(next){}

product productNode::getCurrentProduct(){
    return currentProduct;
};

string productNode::getClave(){
    return clave;
};
productNode* productNode::getNext(){
    return next;
};
void productNode::setNext(productNode* next){
    this->next = next;
};

productNode::~productNode(){
}