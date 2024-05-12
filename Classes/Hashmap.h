#pragma once
#include <iostream>
#include "productNode.h"
#include "product.h"

using namespace std;

class Hashmap {
private:
productNode** tabla;
int tamano;
int hash(string clave);

public:
void remove(int id, string clave);
Hashmap(int tamano);
void insertar(string clave, product valor);
product buscar(int id);
void imprimir(string clave);
int getTamano();
productNode **getTabla();
void printAll();
~Hashmap();
};