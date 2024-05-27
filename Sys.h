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
int cantCategories; int thirdAgeRange; int handicappedRange; int pregnantRange; int normalRange; // Ranges for the different types of clients
clientCategory *clientCategories; // Array of client categories
Hashmap *productForCategory; Hashmap* productForSubCategory; // Hashmaps for products
queue<venta> ventas; // Queue for sales
clientFactory *cf; // Client factory
bool loadData(); // Load data from files
bool saveData(); // Save data to files
void showMenu(); // Show main menu
void showMenuManageProducts();  // Show menu for managing products
void showMenuManageClients(); // Show menu for managing clients
void menuClient(client *client); // Show menu for clients
void addCategory(string name); // Add a category
void ShowQueues(); // Show queues
void createTestFile(); // Create a test file
public:
Sys(); // Constructor
void run(); // Run the system
//Manage clients
client* callNextClient(); //option 1, call next client
void addClientToQueue(); //option 2, add client to queue
//Manage Products
void addProduct(); //option 1, add product
void generateSellTickets(); //option 2, generate sell tickets
};