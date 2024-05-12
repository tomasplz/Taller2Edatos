#pragma once
#include <iostream>
#include "client.h"
using namespace std;

class clientNormal : public client{
public:
    clientNormal(string name, int age, int number); // Constructor.
    virtual ~clientNormal(); // Destructor.
};