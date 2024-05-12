#pragma once
#include <iostream>
#include "product.h"

using namespace std;

class productNode{
private:
string clave; //key
product currentProduct; //product
productNode* next; //pointer to next node
public:
productNode(string clave, product currentProduct, productNode* next); //constructor
string getClave(); //get key
product getCurrentProduct(); //get product
productNode *getNext(); //get next node
void setNext(productNode* next); //set next node
~productNode(); //destructor
};