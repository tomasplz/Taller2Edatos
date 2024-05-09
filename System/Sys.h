#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include <limits>
#include <fstream>
#include "../Classes/category.h"
#include "../Classes/clientFactory.h"
#include "../Classes/product.h"
using namespace std;

class Sys {
private:
int cantCategories;
int thirdAgeRange; int handicappedRange; int pregnantRange; int normalRange;
category *categories;
clientFactory *cf;
bool loadData();
bool saveData();
void showMenu();
void showMenuManageProducts();
void showMenuManageClients();
void addCategory(string name);

void ShowQueues();

public:
Sys();
void run();
//Manage clients
client* callNextClient(); //option 1
void addClientToQueue(); //option 2
//Manage Products
void addProduct(); //option 1
void generateSellTickets(); //option 2
};