#include "Hashmap.h"

Hashmap::Hashmap(int tamano)
{ 
    this->tamano = tamano;
    tabla = new productNode*[tamano];
    for (int i = 0; i < tamano; i++) {
        tabla[i] = nullptr;
    }
}

int Hashmap::hash(string clave) {
    int suma = 0;
    for (char c : clave) {
        suma += c;
    }
    return suma % tamano;
}


void Hashmap::insertar(string clave, product valor) {
    int indice = hash(clave);
    productNode* nuevo = new productNode(clave, valor, tabla[indice]);
    tabla[indice] = nuevo;
}

product Hashmap::buscar(int id) {
    product currentProduct = product("No encontrado", "No encontrado", "No encontrado", 0, -1);
    for (int i = 0; i < tamano; i++) {
        productNode* nodo = tabla[i];
        while (nodo != nullptr) {
            product aux = nodo->getCurrentProduct();
            if (nodo->getCurrentProduct().getId() == id) {
                return (nodo->getCurrentProduct());
            }
            nodo = nodo->getNext();
        }
    }
    return currentProduct;
}

void Hashmap::imprimir(string clave) {
    int indice = hash(clave);
    productNode* nodo = tabla[indice];
    cout << "Instancias con la clave '" << clave << "':";
    while (nodo != nullptr) {
        if (nodo->getClave() == clave) {
            cout << "\n" << nodo->getCurrentProduct().getName();
        }
        nodo = nodo->getNext();
    }
    cout << endl; // Imprime un salto de línea después de la lista de productos
}

void Hashmap::printAll() {
    for (int i = 0; i < tamano; i++) {
        productNode* nodo = tabla[i];
        while (nodo != nullptr) {
            cout << "ID: " << nodo->getCurrentProduct().getId() << ", Clave: " << nodo->getClave() << ", Nombre: " << nodo->getCurrentProduct().getName() << " PRECIO: " << nodo->getCurrentProduct().getPrice() << endl ;
            nodo = nodo->getNext();
        }
    }
}

int Hashmap::getTamano() {
    return tamano;
}

productNode** Hashmap::getTabla() {
    return tabla;
}

void Hashmap::remove(int id, string clave) {
    int indice = hash(clave);
    productNode* nodo = tabla[indice];
    productNode* previo = nullptr;

    while (nodo != nullptr && nodo->getCurrentProduct().getId() != id) {
        previo = nodo;
        nodo = nodo->getNext();
    }
    if (nodo == nullptr) {
        return;
    }

    if (previo == nullptr) {
        // El nodo a eliminar es el primer nodo en la lista enlazada
        tabla[indice] = nodo->getNext();
        delete nodo;
    } else {
        previo->setNext(nodo->getNext());
        delete nodo;
    }
}

Hashmap::~Hashmap() {
    for (int i = 0; i < tamano; i++) {
        productNode* nodo = tabla[i];
        while (nodo != nullptr) {
            productNode* temp = nodo;
            nodo = nodo->getNext();
            delete temp;
        }
    }
    delete[] tabla;
}