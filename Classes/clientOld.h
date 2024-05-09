#pragma once
#include <iostream>
#include "client.h"
using namespace std;

class clientOld : public client{
public:
    clientOld(string name, int age, int number);
};