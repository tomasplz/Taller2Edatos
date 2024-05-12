#pragma once
#include <iostream>
#include "client.h"
#include "clientHandicapped.h"
#include "clientPregnant.h"
#include "clientNormal.h"
#include "clientOld.h"
using namespace std;

class clientFactory
{
public:
    clientFactory(int numOldClient, int numHandicappedClient, int numPregnantClient, int numNormalClient);
    client* createClient(string name, int age, int type);
    ~clientFactory();
private:
    int numOldClient;
    int numHandicappedClient;
    int numPregnantClient;
    int numNormalClient;
};