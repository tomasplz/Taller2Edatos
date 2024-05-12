#include "clientHandicapped.h"

/**
 * @brief Constructs a new clientHandicapped object.
 * 
 * @param name The name of the handicapped client.
 * @param age The age of the handicapped client.
 * @param number The client number of the handicapped client.
 */
clientHandicapped::clientHandicapped(string name, int age, int number) : client(name, age, number){}

/**
 * @brief Destructor for the clientHandicapped class.
 * 
 * This destructor is responsible for cleaning up any resources
 * allocated by the clientHandicapped class.
 */
clientHandicapped::~clientHandicapped(){}
