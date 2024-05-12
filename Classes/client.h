#pragma once
#include <iostream>
#include <queue>
#include "venta.h"
using namespace std;

class venta;

class client{
private:
    string name; // Name of the client.
    int age; // Age of the client.
    int number; // Number of the client.
    queue<venta> *ventas; // Queue of ventas.
public:
    client(); // Constructor.
    client(string name, int age, int number); // Constructor.
    void showVentas();  // Show ventas method.
    void setName(string name); // Set name method.
    string getName(); // Get name method.
    void setAge(int age); // Set age method.
    int getAge();   // Get age method.
    void setNumber(int number); // Set number method.
    int getNumber(); // Get number method.
    void addVenta(venta saleMade); // Add venta method.
    virtual ~client(); // Destructor.
};