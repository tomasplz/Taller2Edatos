#include "clientCategory.h"

clientCategory::clientCategory(string name)
{
    this->name = name;
    clients = new queue<client>;
    next = NULL;
}

void clientCategory::addClient(client* c)
{clients->push(*c);}

void clientCategory::removeLastClient()
{clients->pop();}

string clientCategory::getName()
{return name;}

void clientCategory::showClients()
{
    queue<client> temp = *clients;
    while (!temp.empty())
    {
        cout << " -Name: " + temp.front().getName() + " Age: " << to_string(temp.front().getAge()) + " Atention Number: " << to_string(temp.front().getNumber())  << endl;
        temp.pop();
    }
}

clientCategory* clientCategory::getNext()
{return next;}

void clientCategory::setNext(clientCategory* next)
{this->next = next;}

bool clientCategory::isEmpty(){
    if (clients->empty())
    return true;
    else
    return false;
}

client* clientCategory::getLastClient(){
    return &clients->back();
}

clientCategory::~clientCategory()
{
    delete clients;
}