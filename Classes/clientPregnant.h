#pragma once
#include <iostream>
#include "client.h"
using namespace std;

class clientPregnant : public client{
public:
    clientPregnant(string name, int age, int number); // Constructor
    ~clientPregnant(); // Destructor
};