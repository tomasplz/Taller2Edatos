#pragma once
#include <iostream>
#include "product.h"

using namespace std;

class productNode{
private:
string clave;
product currentProduct;
productNode* next;
public:
productNode(string clave, product currentProduct, productNode* next);
string getClave();
product getCurrentProduct();
productNode *getNext();
void setNext(productNode* next);
~productNode();
};