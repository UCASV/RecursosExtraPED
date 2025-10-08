#include <iostream>
#include <queue>

// Función para solicitar al usuario los valores para encolar
void IngresarValores(std::queue<int>& cola) {
    int valor;
    std::cout << "Ingrese los valores para encolar (0 para terminar): " << std::endl;
    
    while (true) {
        std::cout << "Valor: ";
        std::cin >> valor;
        if (valor == 0) break;
        cola.push(valor);  // Encolar el valor
        std::cout << "Encolando: " << valor << std::endl;
    }
}

// Función para mostrar todos los elementos de la cola sin modificarla
void MostrarCola(std::queue<int> cola) {
    if (cola.empty()) {
        std::cout << "La cola está vacía." << std::endl;
        return;
    }

    std::cout << "Elementos en la cola: ";
    while (!cola.empty()) {
        std::cout << cola.front() << " ";  // Mostrar el elemento al frente
        cola.pop();                        // Eliminar el elemento del frente (solo de la copia)
    }
    std::cout << std::endl;
}

// Función para eliminar el elemento del frente de la cola
void EliminarElemento(std::queue<int>& cola) {
    if (!cola.empty()) {
        std::cout << "Valor al frente de la cola: " << cola.front() << std::endl;
        cola.pop();  // Desencolar el frente
        std::cout << "Se ha desencolado el elemento del frente." << std::endl;
    } else {
        std::cout << "La cola está vacía, no hay nada que desencolar." << std::endl;
    }
}

int main() {
    std::queue<int> cola;

    // Llamar a la función para ingresar los valores
    IngresarValores(cola);

    // Llamar a la función para mostrar los valores de la cola
    std::cout << "Mostrando la cola:" << std::endl;
    MostrarCola(cola);

    // Llamar a la función para eliminar el elemento en el frente de la cola
    std::cout << "Eliminando el elemento del frente de la cola:" << std::endl;
    EliminarElemento(cola);

    // Mostrar la cola después de eliminar un elemento
    std::cout << "Mostrando la cola despues de eliminar el frente:" << std::endl;
    MostrarCola(cola);

    return 0;
}
