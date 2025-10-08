#include <iostream>
#include <stack>

// Función para solicitar al usuario los valores para apilar
void IngresarValores(std::stack<int>& pila) {
    int valor;
    std::cout << "Ingrese los valores para apilar (0 para terminar): " << std::endl;
    
    while (true) {
        std::cout << "Valor: ";
        std::cin >> valor;
        if (valor == 0) break;
        pila.push(valor);  // Apilando el valor
    }
}

// Función para mostrar todos los elementos de la pila sin modificarla
void MostrarPila(std::stack<int> pila) {
    if (pila.empty()) {
        std::cout << "La pila está vacía." << std::endl;
        return;
    }

    std::cout << "Elementos en la pila: ";
    while (!pila.empty()) {
        std::cout << pila.top() << " ";  // Muestra el elemento en la cima
        pila.pop();                      // Elimina el elemento de la cima
    }
    std::cout << std::endl;
}

// Función para eliminar el elemento en la cima de la pila
void EliminarElemento(std::stack<int>& pila) {
    if (!pila.empty()) {
        std::cout << "Cima de la pila: " << pila.top() << std::endl;
        pila.pop();
        std::cout << "Se ha eliminado el elemento de la cima." << std::endl;
    } else {
        std::cout << "La pila está vacía, no hay nada que eliminar." << std::endl;
    }
}

int main() {
    std::stack<int> pila;

    // Llamar a la función para ingresar los valores
    IngresarValores(pila);

    // Llamar a la función para mostrar los valores de la pila
    std::cout << "Mostrando la pila:" << std::endl;
    MostrarPila(pila);

    // Llamar a la función para eliminar el elemento en la cima de la pila
    std::cout << "Eliminando el elemento de la cima:" << std::endl;
    EliminarElemento(pila);

    // Mostrar pila después de eliminar
    std::cout << "Mostrando la pila después de eliminar el elemento de la cima:" << std::endl;
    MostrarPila(pila);

    return 0;
}
