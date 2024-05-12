#include "venta.h"

/**
 * @brief Constructs a new venta object with the given client.
 * 
 * @param Client A pointer to the client associated with the venta.
 */
venta::venta(client *Client) : Client(Client)
{
    products = new queue<product>();
}

/**
 * @brief Sets the products of the venta.
 * 
 * @param products A pointer to a queue of products.
 */
void venta::setProducts(queue<product> *products){this->products = products;}

/**
 * @brief Prints the products of the venta.
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
 * @brief Gets the client associated with the venta.
 * 
 * @return client* A pointer to the client associated with the venta.
 */
client* venta::getClient() {return Client;}

/**
 * @brief Gets the total price of the products in the venta.
 * 
 * @return int The total price of the products in the venta.
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

/**
 * @brief Destroys the venta object.
 */
venta::~venta()
{
    delete products;
}