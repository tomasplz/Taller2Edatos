#pragma once
#include <iostream>
#include "productNode.h"
#include "product.h"

using namespace std;

class Hashmap {
private:
productNode** tabla; // Table
int tamano; // Size
int hash(string clave); // Hash function

public:
void remove(int id, string clave); // Remove product
Hashmap(int tamano); // Constructor with size
void insertar(string clave, product valor); // Insert product
product buscar(int id); // Search product
void imprimir(string clave); // Print products
int getTamano(); // Get size
productNode **getTabla(); // Get table
void printAll(); // Print all products
~Hashmap(); // Destructor
};