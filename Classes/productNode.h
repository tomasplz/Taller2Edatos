#pragma once
#include <iostream>
#include "product.h"

using namespace std;

class productNode{
private:
string clave; // Key
product currentProduct; // Product
productNode* next; // Next node
public:
productNode(string clave, product currentProduct, productNode* next); // Constructor
string getClave(); // Get key
product getCurrentProduct(); // Get product
productNode *getNext(); // Get next node
void setNext(productNode* next); // Set next node
~productNode(); // Destructor
};