#pragma once
#include <iostream>
#include <queue>
#include "client.h"

using namespace std;

class category{
private:
    string name;
    queue<client> *clients;
    category* next;
public:
    category(string name);
    string getName();
    void addClient(client *client);
    void removeLastClient();
    client* getLastClient();
    void showClients();
    void setNext(category* next);
    category* getNext();
    bool isEmpty();
};