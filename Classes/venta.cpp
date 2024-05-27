#include "venta.h"

// Constructor
/**
 * @brief Construct a new venta::venta object
 * 
 * @param Client
 */
venta::venta(client *Client)
{
    this->Client = Client;
    products = new queue<product>();
};

// Setters
/**
 * @brief Set the Products object
 * 
 * @param products
 * @return void
 */
void venta::setProducts(queue<product> *products){
    this->products = products;
};

// Getters
/**
 * @brief Print the products in the queue
 * 
 * @return void
 */
void venta::printProducts() { 
    queue<product> tempQueue = *products; // Create a temporary queue to preserve the original queue
    while (!tempQueue.empty())
    { 
        product p = tempQueue.front(); 
        cout << p.getName() << endl; 
        tempQueue.pop(); 
    }
}

/**
 * @brief Get the Client object
 * 
 * @return client*
 */
client* venta::getClient() {
    return Client;
}

/**
 * @brief Get the Total Price object
 * 
 * @return int
 */
int venta::getTotalPrice() {
    queue<product> tempQueue = *products;
    int totalPrice = 0;
    while (!tempQueue.empty())
    {
        product p = tempQueue.front();
        totalPrice += p.getPrice();
        tempQueue.pop();
    }
    return totalPrice;
}