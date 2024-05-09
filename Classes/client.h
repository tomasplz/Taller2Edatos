#pragma once
#include <iostream>
using namespace std;

class client{
private:
    string name;
    int age;
    int number;
public:
    client(string name, int age, int number);
    void setName(string name);
    string getName();
    void setAge(int age);
    int getAge();
    void setNumber(int number);
    int getNumber();
    virtual ~client();
};