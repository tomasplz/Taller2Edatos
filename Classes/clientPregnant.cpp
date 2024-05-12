#include "clientPregnant.h"

/**
 * @brief Constructs a new clientPregnant object.
 * 
 * @param name The name of the client.
 * @param age The age of the client.
 * @param number The client's number.
 */
clientPregnant::clientPregnant(string name, int age, int number) : client(name, age, number){}

/**
 * @brief Destructor for the clientPregnant class.
 * 
 * This destructor is responsible for cleaning up any resources allocated by the clientPregnant class.
 * It is automatically called when an object of the class is destroyed.
 */
clientPregnant::~clientPregnant(){}