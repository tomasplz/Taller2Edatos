#include "clientOld.h"

/**
 * @brief Constructs a new clientOld object.
 * 
 * This constructor initializes a new clientOld object with the specified name, age, and number.
 * 
 * @param name The name of the client.
 * @param age The age of the client.
 * @param number The client's number.
 */
clientOld::clientOld(string name, int age, int number) : client(name, age, number){}

/**
 * @brief Destructor for the clientOld class.
 * 
 * This destructor is responsible for cleaning up any resources
 * allocated by the clientOld class.
 */
clientOld::~clientOld(){}