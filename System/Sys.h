#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include "../Classes/clientFactory.h"
#include "../Classes/product.h"
using namespace std;

class Sys {
private:
// category categ = new category(); // Categorias unidas por nodos (forma 1)
// client currentClient; // Current client (forma 2)

public:
void loadData();
void saveData();
void giveNumber();
void callNextClient();
void createClient();
void addProduct();
void generateTicket();
};