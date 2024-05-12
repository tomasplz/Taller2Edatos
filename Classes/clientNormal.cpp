#include "clientNormal.h"

/**
 * @brief Constructs a new clientNormal object.
 * 
 * @param name The name of the client.
 * @param age The age of the client.
 * @param number The client's number.
 */
clientNormal::clientNormal(string name, int age, int number) : client(name, age, number){}

/**
 * @brief Destructor for the clientNormal class.
 * 
 * This destructor is responsible for cleaning up any resources
 * allocated by the clientNormal class.
 */
clientNormal::~clientNormal(){}