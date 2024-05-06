#pragma once
#include <iostream>
using namespace std;

class client{
private:
string name;
int age;
public:
client(string name, int age);
void setName(string name);
string getName();
void setAge(int age);
int getAge();
};