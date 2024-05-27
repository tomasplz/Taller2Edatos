#pragma once
#include <iostream>
#include <queue>
#include "venta.h"
using namespace std;

class venta;

class client{
private:
    string name; // Added variable name "name" of the client.
    int age; // Added variable name "age" of the client.
    int number;     // Added variable name "number" of the client.
    queue<venta> *ventas; // Added variable name "ventas" of the client.
public:
    client(); // Constructor
    client(string name, int age, int number); // Constructor
    void showVentas(); // Show sells
    void setName(string name); // Set name
    string getName(); // Get name
    void setAge(int age); // Set age
    int getAge(); // Get age
    void setNumber(int number); // Set number
    int getNumber(); // Get number
    void addVenta(venta saleMade); // Add sell
    virtual ~client(); // Destructor
};