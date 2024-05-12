#include "client.h"

/**
 * @brief Constructs a new client object with the given name, age, and number.
 * 
 * @param name The name of the client.
 * @param age The age of the client.
 * @param number The client's number.
 */
client::client(string name, int age, int number) { this->name = name; this->age = age; this->number = number; 
ventas = new queue<venta>;
}

/**
 * @brief Default constructor for the client class.
 * 
 * This constructor initializes a new instance of the client class.
 */
client::client(){}

/**
 * @brief Sets the name of the client.
 * 
 * @param name The name of the client.
 */
void client::setName(string name) {this->name = name;}

/**
 * @brief Sets the age of the client.
 * 
 * @param age The age of the client.
 */
void client::setAge(int age) {this->age = age;}

/**
 * @brief Sets the number of the client.
 * 
 * @param number The number of the client.
 */
void client::setNumber(int number) {this->number = number;}

/**
 * @brief Gets the name of the client.
 * 
 * @return string The name of the client.
 */
string client::getName() {return name;}

/**
 * @brief Gets the age of the client.
 * 
 * @return int The age of the client.
 */
int client::getAge() {return age;}

/**
 * @brief Gets the number of the client.
 * 
 * @return int The number of the client.
 */
int client::getNumber() {return number;}

/**
 * @brief Adds a venta to the client.
 * 
 * @param saleMade The venta to be added.
 */
void client::addVenta(venta saleMade){ventas->push(saleMade);}

/**
 * @brief Shows the ventas of the client.
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

/**
 * @brief Destructor for the client class.
 * 
 * This destructor is responsible for cleaning up any resources
 * allocated by the client class.
 */
client::~client(){}