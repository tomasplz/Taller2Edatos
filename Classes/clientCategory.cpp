#include "clientCategory.h"

// Constructor
/**
 * @brief Construct a new client Category::client Category object
 * 
 * @param name
 * @return clientCategory
*/
clientCategory::clientCategory(string name)
{
    this->name = name;
    clients = new queue<client>;
    next = NULL;
}

/**
 * @brief Add a client to the queue
 * 
 * @param c
 * @return void
*/
void clientCategory::addClient(client* c)
{clients->push(*c);}

/**
 * @brief Remove the last client from the queue
 * 
 * @return void
*/
void clientCategory::removeLastClient()
{clients->pop();}

/**
 * @brief Get the Name object
 * 
 * @return string

*/
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

/**
 * @brief Get the next category object
*/
clientCategory *clientCategory::getNext()
{return next;}

/**
 * @brief Set the next category object
 * 
 * @param next
*/
void clientCategory::setNext(clientCategory* next)
{this->next = next;}

/**
 * @brief Check if the category is empty
 * 
 * @return true
 * @return false
*/
bool clientCategory::isEmpty(){
    if (clients->empty())
    return true;
    else
    return false;
}

/**
 * @brief Get the last client object
 * 
 * @return client*
*/
client* clientCategory::getLastClient(){
    return &clients->back();
}

/**
 * @brief Destroy the client Category::client Category object
*/
clientCategory::~clientCategory()
{
    delete clients;
}