#pragma once
#include <iostream>
#include <queue>
#include "client.h"

using namespace std;

class clientCategory{
private:
    string name; // Name of the category.
    queue<client> *clients; // Clients from the category.
    clientCategory* next; // Next category.
public:
    clientCategory(string name); // Constructor.
    string getName(); // Get the name of the category.
    void addClient(client *client); // Add a client to the category.
    void removeLastClient(); // Remove the last client from the category.
    client* getLastClient(); // Get the last client from the category.
    void showClients(); // Show the clients from the category.
    void setNext(clientCategory* next); // Set the next category.
    clientCategory* getNext(); // Get the next category.
    bool isEmpty(); // Check if the category is empty.
    ~clientCategory(); // Destructor.
};