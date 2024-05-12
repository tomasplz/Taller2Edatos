#include "clientCategory.h"

/**
 * @brief Constructs a new clientCategory object with the given name.
 * 
 * @param name The name of the client category.
 */
clientCategory::clientCategory(string name)
{
    this->name = name;
    clients = new queue<client>;
    next = NULL;
}

/**
 * @brief Adds a client to the client category.
 * 
 * @param c The client to be added.
 */
void clientCategory::addClient(client* c){clients->push(*c);}

/**
 * @brief Removes the last client from the client category.
 */
void clientCategory::removeLastClient(){clients->pop();}

/**
 * @brief Gets the name of the client category.
 * 
 * @return string The name of the client category.
 */
string clientCategory::getName(){return name;}

/**
 * @brief Shows the clients from the client category.
 */
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
 * @brief Get the next client category object.
 * 
 * @return clientCategory* Pointer to the next client category object.
 */
clientCategory* clientCategory::getNext(){return next;}

/**
 * @brief Set the next client category object.
 * 
 * @param next Pointer to the next client category object.
 */
void clientCategory::setNext(clientCategory* next){this->next = next;}


/**
 * @brief Check if the client category is empty.
 * 
 * @return true If the client category is empty.
 * @return false If the client category is not empty.
 */
bool clientCategory::isEmpty(){
    return clients->empty();
}

/**
 * @brief Get the last client from the client category.
 * 
 * @return client* Pointer to the last client from the client category.
 */
client* clientCategory::getLastClient(){return &clients->back();}

/**
 * @brief Destroys the clientCategory object.
 * 
 */
clientCategory::~clientCategory(){delete clients;}