#pragma once
#include <iostream>
#include <queue>
#include "client.h"

using namespace std;

class clientCategory{
private:
    string name;
    queue<client> *clients;
    clientCategory* next;
public:
    clientCategory(string name);
    string getName();
    void addClient(client *client);
    void removeLastClient();
    client* getLastClient();
    void showClients();
    void setNext(clientCategory* next);
    clientCategory* getNext();
    ~clientCategory();
    bool isEmpty();
};