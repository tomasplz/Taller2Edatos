#include "client.h"

// Constructor
/**
 * @brief Construct a new client::client object
 * 
 * @param name
 * @param age
 * @param number
 * @return client
*/
client::client(string name, int age, int number) { this->name = name; this->age = age; this->number = number; 
ventas = new queue<venta>;
}

// Constructor
/**
 * @brief Construct a new client::client object
 * 
 * @return client
*/
client::client(){
};

// Setters
/**
 * @brief Set the Name object
 * 
 * @param name
*/
void client::setName(string name) {this->name = name;}
/**
 * @brief Set the Age object
 * 
 * @param age
*/
void client::setAge(int age) {this->age = age;}
/**
 * @brief Set the Number object
 * 
 * @param number
*/
void client::setNumber(int number) {this->number = number;}
// Getters
/**
 * @brief Get the Name object
 * 
 * @return string
*/
string client::getName() {return name;}
/**
 * @brief Get the Age object
 * 
 * @return int
*/
int client::getAge() {return age;}
/**
 * @brief Get the Number object
 * 
 * @return int
*/
int client::getNumber() {return number;}
/**
 * @brief Add a sell to the queue
 * 
 * @param saleMade
*/
void client::addVenta(venta saleMade){
    ventas->push(saleMade);
}
/**
 * @brief Show sells
*/
void client::showVentas(){
    queue<venta> tempQueue = *ventas;
    int i = 1;
    while (!tempQueue.empty())
    {
        venta v = tempQueue.front();
        v.printProducts();
        tempQueue.pop();
        i++;
    }
}
// Destructor
/**
 * @brief Destroy the client::client object
 * 
*/
client::~client(){}