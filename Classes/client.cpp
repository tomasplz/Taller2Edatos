#include "client.h"

client::client(string name, int age, int number) { this->name = name; this->age = age; this->number = number; }

client::~client(){}
void client::setName(string name) {this->name = name;}
void client::setAge(int age) {this->age = age;}
void client::setNumber(int number) {this->number = number;}
string client::getName() {return name;}
int client::getAge() {return age;}
int client::getNumber() {return number;}