#pragma once
#include <iostream>
#include "productNode.h"
#include "product.h"

using namespace std;

class Hashmap {
private:
productNode** tabla; //array of productNode pointers
int tamano; //size of the array
int hash(string clave); //hash function

public:
Hashmap(int tamano); //constructor
void insertar(product valor, string clave); //insert product into hashmap
void remove(int id, string clave); //remove product from hashmap
product buscar(int id); //search for product by id
void imprimir(string clave); //print all products with the same key
int getTamano(); //get size of the array
productNode **getTabla(); //get array of productNode pointers
void printAll(); //print all products in the hashmap
~Hashmap(); //destructor
};