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


/**
 * @class Sys
 * @brief Represents the main system class.
 * 
 * The Sys class is responsible for managing clients, products, and sales in the system.
 * It provides functionality to add clients to a queue, call the next client, add products,
 * generate sell tickets, and perform other system operations.
 */
class Sys {
private:
int cantCategories; int thirdAgeRange; int handicappedRange; int pregnantRange; int normalRange; //Ranges for clients
clientCategory *clientCategories; //Queue of clients
Hashmap *productForCategory; Hashmap* productForSubCategory; //Hashmaps for products
queue<venta> ventas; //Queue of ventas
clientFactory *cf; //Factory for clients
bool loadData(); //load data from file
bool saveData(); //save data to file
void showMenu(); //show main menu
void showMenuManageProducts(); //show menu for managing products
void showMenuManageClients(); //show menu for managing clients
void menuClient(client *client); //show menu for clients
void addCategory(string name); //insert a new category
void ShowQueues(); //show queues
void createTestFile(); //create a test file with data for the system to work
public:
Sys(); //constructor
void run(); //run the system
//Manage clients
client* callNextClient(); //option 1, call next client
void addClientToQueue(); //option 2, add new client to queue
//Manage Products
void addProduct(); //option 1, add new product to system
void generateSellTickets(); //option 2, generate sell tickets
};