#include "category.h"

category::category(string name)
{
    this->name = name;
    clients = new queue<client>;
    next = NULL;
}

void category::addClient(client* c)
{clients->push(*c);}

void category::removeLastClient()
{clients->pop();}

string category::getName()
{return name;}

void category::showClients()
{
    queue<client> temp = *clients;
    while (!temp.empty())
    {
        cout << " -Name: " + temp.front().getName() + " Age: " << to_string(temp.front().getAge()) + " Atention Number: " << to_string(temp.front().getNumber())  << endl;
        temp.pop();
    }
}

category* category::getNext()
{return next;}

void category::setNext(category* next)
{this->next = next;}

bool category::isEmpty(){
    if (clients->empty())
    return true;
    else
    return false;
}

client* category::getLastClient(){
    return &clients->back();
}