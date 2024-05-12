#pragma once
#include <iostream>
#include "client.h"
using namespace std;

class clientHandicapped : public client{
public:
    clientHandicapped(string name, int age, int number); // Constructor.
    virtual ~clientHandicapped(); // Destructor.
};