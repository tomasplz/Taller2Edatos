#include "clientFactory.h"

/**
 * @brief Constructs a clientFactory object with the specified ranges for different client types.
 * 
 * @param thirdAgeRange The range for third age clients.
 * @param handicappedRange The range for handicapped clients.
 * @param pregnantRange The range for pregnant clients.
 * @param normalRange The range for normal clients.
 */
clientFactory::clientFactory(int thirdAgeRange, int handicappedRange, int pregnantRange, int normalRange)
{
    this->numOldClient = thirdAgeRange;
    this->numHandicappedClient = handicappedRange;
    this->numPregnantClient = pregnantRange;
    this->numNormalClient = normalRange;
}

/**
 * @brief Creates a new client object.
 * 
 * This method creates a new client object based on the specified type.
 * 
 * @param name The name of the client.
 * @param age The age of the client.
 * @param type The type of the client.
 * @return client* A pointer to the newly created client object.
 */
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
}

/**
 * @brief Destructor for the clientFactory class.
 * 
 * This destructor is responsible for cleaning up any resources
 * allocated by the clientFactory class.
 */
clientFactory::~clientFactory()
{
}