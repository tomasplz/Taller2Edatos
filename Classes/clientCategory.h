#pragma once
#include <iostream>
#include <queue>
#include "client.h"

using namespace std;

class clientCategory{
private:
    string name; // Added variable name "name" after the data type.
    queue<client> *clients; // Added variable name "clients" after the data type.
    clientCategory* next; // Added variable name "next" after the data type.
public:
    clientCategory(string name); // Constructor
    string getName(); // Get name
    void addClient(client *client); // Add client
    void removeLastClient(); // Remove last client
    client* getLastClient(); // Get last client
    void showClients(); // Show clients
    void setNext(clientCategory* next); // Set next
    clientCategory* getNext(); // Get next
    bool isEmpty(); // Check if the category is empty
    ~clientCategory(); // Destructor
};