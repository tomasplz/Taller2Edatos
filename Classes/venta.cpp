#include "venta.h"

venta::venta(client *Client)
{
    this->Client = Client;
    products = new queue<product>();
};

void venta::setProducts(queue<product> *products){
    this->products = products;
};

void venta::printProducts() { 
    queue<product> tempQueue = *products; // Create a temporary queue to preserve the original queue
    while (!tempQueue.empty())
    { 
        product p = tempQueue.front(); 
        cout << p.getName() << endl; 
        tempQueue.pop(); 
    }
}

client* venta::getClient() {
    return Client;
}

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