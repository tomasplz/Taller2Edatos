#include "Hashmap.h"

/**
 * @brief Constructs a new Hashmap object with the specified size.
 * 
 * @param tamano The size of the hashmap.
 */
Hashmap::Hashmap(int tamano)
{ 
    this->tamano = tamano;
    tabla = new productNode*[tamano];
    for (int i = 0; i < tamano; i++) {
        tabla[i] = nullptr;
    }
}

/**
 * @brief Hash function to determine the index of the key in the hashmap.
 * 
 * @param clave The key to hash.
 * @return int The index of the key in the hashmap.
 */
int Hashmap::hash(string clave) {
    int suma = 0;
    for (char c : clave) {
        suma += c;
    }
    return suma % tamano;
}

/**
 * @brief Inserts a product into the hashmap.
 * 
 * @param valor The product to insert.
 * @param clave The key of the product.
 */
void Hashmap::insertar(product valor, string clave) {
    int indice = hash(clave);
    productNode* nuevo = new productNode(clave, valor, tabla[indice]);
    tabla[indice] = nuevo;
}

/**
 * @brief Searches for a product in the hashmap by ID.
 * 
 * @param id The ID of the product to search for.
 * @return product The product with the specified ID.
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
 * @brief Prints all products with the same key.
 * 
 * @param clave The key to search for.
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
 * @brief Prints all products in the hashmap.
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
 * @brief Gets the size of the hashmap.
 * 
 * @return int The size of the hashmap.
 */
int Hashmap::getTamano() {
    return tamano;
}

/**
 * @brief Gets the array of productNode pointers.
 * 
 * @return productNode** The array of productNode pointers.
 */
productNode** Hashmap::getTabla() {
    return tabla;
}

/**
 * @brief Removes a product from the hashmap by ID.
 * 
 * @param id The ID of the product to remove.
 * @param clave The key of the product to remove.
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

/**
 * @brief Destroys the Hashmap object.
 */
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