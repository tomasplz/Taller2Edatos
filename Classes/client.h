#pragma once
#include <iostream>
#include <queue>
#include "venta.h"
using namespace std;

class venta;

class client{
private:
    string name;
    int age;
    int number;
    queue<venta> *ventas;
public:
    client();
    client(string name, int age, int number);
    void showVentas();
    void setName(string name);
    string getName();
    void setAge(int age);
    int getAge();
    void setNumber(int number);
    int getNumber();
    void addVenta(venta saleMade);
    virtual ~client();
};