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
public:
client* Client; // Added variable name "Client" asociated with the sell.
venta(client *Client); // Constructor
void setProducts(queue<product> *products); // Set products
void printProducts(); // Print products
client *getClient(); // Get client
int getTotalPrice(); // Get total price
};