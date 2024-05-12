#include "clientFactory.h"

clientFactory::clientFactory(int thirdAgeRange, int handicappedRange, int pregnantRange, int normalRange)
{
    this->numOldClient = thirdAgeRange;
    this->numHandicappedClient = handicappedRange;
    this->numPregnantClient = pregnantRange;
    this->numNormalClient = normalRange;
}
client* clientFactory::createClient(string name, int age, int type)
{
    switch (type)
    {
    case 1:
        numOldClient++;
        return new clientOld(name, age, numOldClient);
        break;
    case 2:
        numHandicappedClient ++;
        return new clientHandicapped(name, age, numHandicappedClient);
        break;
    case 3:
        numPregnantClient++;
        return new clientPregnant(name, age, numPregnantClient);
        break;
    case 4:
        numNormalClient++;
        return new clientNormal(name, age, numNormalClient);
        break;
    default:
        return NULL;
        break;
    }
};
clientFactory::~clientFactory()
{
}