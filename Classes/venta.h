#pragma once
#include <iostream>
#include <queue>
#include "client.h"
#include "product.h"

using namespace std;

class client;

class venta{
private:
queue<product> *products; // Added variable name "products" after the data type.
client* Client; // Client pointer variable.
public:
venta(client *Client); // Constructor with a client pointer as a parameter.
void setProducts(queue<product> *products); // Set products method with a queue of products pointer as a parameter.
void printProducts(); // Print products method.
client *getClient(); // Get client method.
int getTotalPrice(); // Get total price method.
~venta(); // Destructor.
};