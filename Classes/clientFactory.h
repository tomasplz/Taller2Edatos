#pragma once
#include <iostream>
#include "client.h"
#include "clientDisc.h"
#include "clientEmb.h"
#include "clientNormal.h"
#include "clientOld.h"

using namespace std;
class clientFactory
{
public:
    clientFactory();
    client* createClient(string name, int age, string type);
};