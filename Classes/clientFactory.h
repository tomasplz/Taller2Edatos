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
    clientFactory(int numOldClient, int numHandicappedClient, int numPregnantClient, int numNormalClient); // Constructor
    client* createClient(string name, int age, int type); // Create a client
    ~clientFactory(); // Destructor
private:
    int numOldClient; // Number of old clients
    int numHandicappedClient; // Number of handicapped clients
    int numPregnantClient; // Number of pregnant clients
    int numNormalClient; // Number of normal clients
};