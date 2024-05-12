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
client* Client;
venta(client *Client);
void setProducts(queue<product> *products);
void printProducts();
client *getClient();
int getTotalPrice();
};