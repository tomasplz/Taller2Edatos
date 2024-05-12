#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include <limits>
#include <fstream>
#include "../Classes/clientCategory.h"
#include "../Classes/clientFactory.h"
#include "../Classes/product.h"
#include "../Classes/venta.h"
#include "../Classes/Hashmap.h"
using namespace std;


class Sys {
private:
int cantCategories; int thirdAgeRange; int handicappedRange; int pregnantRange; int normalRange;
clientCategory *clientCategories;
Hashmap *productForCategory; Hashmap* productForSubCategory;
queue<venta> ventas;
clientFactory *cf;
bool loadData();
bool saveData();
void showMenu();
void showMenuManageProducts();
void showMenuManageClients();
void menuClient(client *client);
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