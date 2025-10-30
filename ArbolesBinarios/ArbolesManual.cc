#include <iostream>
#include <string>

using namespace std;

struct Datos {
    int id;         
    std::string nombre; 
};

struct Nodo {
    Datos dato;         // Valor almacenado   
    Nodo* izquierda;    // Puntero al hijo izquierdo
    Nodo* derecha;      // Puntero al hijo derecho
};

// Insertar en BST
Nodo* Insertar(Nodo* raiz, Datos nuevo_dato) {
    if (raiz == nullptr) {
        Nodo* nuevo_nodo = new Nodo();
        nuevo_nodo->dato = nuevo_dato;
        nuevo_nodo->izquierda = nullptr;
        nuevo_nodo->derecha = nullptr;
        return nuevo_nodo;
    }

    if (nuevo_dato.id < raiz->dato.id) {
        raiz->izquierda = Insertar(raiz->izquierda, nuevo_dato);
    } else {
        raiz->derecha = Insertar(raiz->derecha, nuevo_dato);
    }

    return raiz;
}

// Buscar en BST
bool Buscar(Nodo* raiz, int id) {
    if (raiz == nullptr) {
        return false;
    }

    if (raiz->dato.id == id) {
        return true;
    }

    if (id < raiz->dato.id) {
        return Buscar(raiz->izquierda, id);
    } else {
        return Buscar(raiz->derecha, id);
    }
}

// Recorrido en orden (izq, raíz, der)
void InOrden(Nodo* raiz) {
    if (raiz != nullptr) {
        InOrden(raiz->izquierda);
        std::cout << "ID: " << raiz->dato.id << ", Nombre: " << raiz->dato.nombre << std::endl;
        InOrden(raiz->derecha);
    }
}

// Recorrido preorden (raíz, izq, der)
void PreOrden(Nodo* raiz) {
    if (raiz != nullptr) {
        std::cout << "ID: " << raiz->dato.id << ", Nombre: " << raiz->dato.nombre << std::endl;
        PreOrden(raiz->izquierda);
        PreOrden(raiz->derecha);
    }
}

// Recorrido postorden (izq, der, raíz)
void PostOrden(Nodo* raiz) {
    if (raiz != nullptr) {
        PostOrden(raiz->izquierda);
        PostOrden(raiz->derecha);
        std::cout << "ID: " << raiz->dato.id << ", Nombre: " << raiz->dato.nombre << std::endl;
    }
}

// Encuentra el nodo con el id mínimo en un subárbol
Nodo* EncontrarMin(Nodo* nodo) {
    while (nodo->izquierda != nullptr) {
        nodo = nodo->izquierda;
    }
    return nodo;
}

// Eliminar un nodo por id
Nodo* Eliminar(Nodo* raiz, int id) {
    if (raiz == nullptr) {
        return raiz;
    }

    if (id < raiz->dato.id) {
        raiz->izquierda = Eliminar(raiz->izquierda, id);
    } else if (id > raiz->dato.id) {
        raiz->derecha = Eliminar(raiz->derecha, id);
    } else {
        // Caso 1: sin hijos
        if (raiz->izquierda == nullptr && raiz->derecha == nullptr) {
            delete raiz;
            raiz = nullptr;
        }
        // Caso 2: solo hijo derecho
        else if (raiz->izquierda == nullptr) {
            Nodo* temp = raiz;
            raiz = raiz->derecha;
            delete temp;
        }
        // Caso 3: solo hijo izquierdo
        else if (raiz->derecha == nullptr) {
            Nodo* temp = raiz;
            raiz = raiz->izquierda;
            delete temp;
        }
        // Caso 4: dos hijos
        else {
            Nodo* temp = EncontrarMin(raiz->derecha);
            raiz->dato = temp->dato;
            raiz->derecha = Eliminar(raiz->derecha, temp->dato.id);
        }
    }
    return raiz;
}

// Destruir todo el árbol para evitar fugas de memoria
void LiberarArbol(Nodo* raiz) {
    if (raiz == nullptr) return;
    LiberarArbol(raiz->izquierda);
    LiberarArbol(raiz->derecha);
    delete raiz;
}

int main() {
    Nodo* raiz = nullptr;

    // Insertar varios nodos
    raiz = Insertar(raiz, {50, "Juan"});
    raiz = Insertar(raiz, {30, "Maria"});
    raiz = Insertar(raiz, {70, "Luis"});
    raiz = Insertar(raiz, {20, "Ana"});
    raiz = Insertar(raiz, {40, "Carlos"});
    raiz = Insertar(raiz, {60, "Pedro"});
    raiz = Insertar(raiz, {80, "Sofia"});

    cout << "=== Recorrido INORDEN (de menor a mayor) ===" << endl;
    InOrden(raiz);

    cout << "\n=== Recorrido PREORDEN ===" << endl;
    PreOrden(raiz);

    cout << "\n=== Recorrido POSTORDEN ===" << endl;
    PostOrden(raiz);

    // Buscar algunos IDs
    int buscar1 = 40;
    int buscar2 = 99;

    cout << "\nBuscando ID " << buscar1 << ": ";
    if (Buscar(raiz, buscar1)) {
        cout << "Encontrado" << endl;
    } else {
        cout << "No encontrado" << endl;
    }

    cout << "Buscando ID " << buscar2 << ": ";
    if (Buscar(raiz, buscar2)) {
        cout << "Encontrado" << endl;
    } else {
        cout << "No encontrado" << endl;
    }

    // Eliminar nodos
    cout << "\n=== Eliminando un nodo hoja (20) ===" << endl;
    raiz = Eliminar(raiz, 20);
    InOrden(raiz);

    cout << "\n=== Eliminando un nodo con un hijo (30) ===" << endl;
    raiz = Eliminar(raiz, 30);
    InOrden(raiz);

    cout << "\n=== Eliminando un nodo con dos hijos (50, la raiz actual) ===" << endl;
    raiz = Eliminar(raiz, 50);
    InOrden(raiz);

    // Limpieza final de memoria
    LiberarArbol(raiz);
    raiz = nullptr;

    return 0;
}
