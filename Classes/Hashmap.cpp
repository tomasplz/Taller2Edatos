#include "Hashmap.h"

// Constructor
/**
 * @brief Construct a new Hashmap::Hashmap object
 * 
 * @param tamano
 * @return Hashmap
*/
Hashmap::Hashmap(int tamano)
{ 
    this->tamano = tamano;
    tabla = new productNode*[tamano];
    for (int i = 0; i < tamano; i++) {
        tabla[i] = nullptr;
    }
}

// Getters
/**
 * @brief Get the Tamano object
 * 
 * @return int
 */
int Hashmap::hash(string clave) {
    int suma = 0;
    for (char c : clave) {
        suma += c;
    }
    return suma % tamano;
}

/**
 * @brief Get the Current Product object
 * 
 * @param id
 * @return product
 */
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
/**
 * @brief Get the Tamano object
 * 
 * @return int
 */
int Hashmap::getTamano() {
    return tamano;
}

/**
 * @brief Get the Tabla object
 * 
 * @return productNode**
 */
productNode** Hashmap::getTabla() {
    return tabla;
}

// Setters
/**
 * @brief Set the Tamano object
 * 
 * @param clave
 * @param valor
 * @return void
 */
void Hashmap::insertar(string clave, product valor) {
    int indice = hash(clave);
    productNode* nuevo = new productNode(clave, valor, tabla[indice]);
    tabla[indice] = nuevo;
}

/**
 * @brief Print the products
 * 
 * @param clave
 * @return void
 */
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

/**
 * @brief Print all products
 * 
 * @return void
 */
void Hashmap::printAll() {
    for (int i = 0; i < tamano; i++) {
        productNode* nodo = tabla[i];
        while (nodo != nullptr) {
            cout << "ID: " << nodo->getCurrentProduct().getId() << ", Clave: " << nodo->getClave() << ", Nombre: " << nodo->getCurrentProduct().getName() << " PRECIO: " << nodo->getCurrentProduct().getPrice() << endl ;
            nodo = nodo->getNext();
        }
    }
}

/**
 * @brief Remove product
 * 
 * @param id
 * @param clave
 * @return void
 */
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

// Destructor
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