#include <iostream>
#include <set>
#include <string>

// Estructura Persona
struct Persona {
    int id;
    std::string nombre;
    int edad;
};

// Sobrecarga del operador < para comparar dos objetos Persona por ID
bool operator<(const Persona& persona1, const Persona& persona2) {
    return persona1.id < persona2.id; // Comparar por ID
}

// Función para insertar personas en el set
void insertarPersonas(std::set<Persona>& personas) {
    personas.insert({1, "Carlos", 25});
    personas.insert({2, "Ana", 30});
    personas.insert({3, "Luis", 25});
    personas.insert({4, "Carlos", 25}); 
}

// Función para mostrar las personas en el set
void mostrarPersonas(const std::set<Persona>& personas) {
    std::cout << "Personas en el set:" << std::endl;
    for (const Persona& persona : personas) {
        std::cout << "ID: " << persona.id << ", Nombre: " << persona.nombre << ", Edad: " << persona.edad << std::endl;
    }
}

// Función para buscar una persona en el set por ID
void buscarPersonaPorID(const std::set<Persona>& personas, int idBuscado) {
    // Creamos una persona "ficticia" con solo el ID para usar el comparador
    Persona personaBuscada{idBuscado, "", 0};

    auto it = personas.find(personaBuscada);
    if (it != personas.end()) {
        std::cout << "La persona con ID " << idBuscado << " es " << it->nombre << ", de " << it->edad << " años." << std::endl;
    } else {
        std::cout << "La persona con ID " << idBuscado << " no está en el set." << std::endl;
    }
}

// Función para borrar una persona del set por ID
void borrarPersonaPorID(std::set<Persona>& personas, int idABorrar) {
    // Creamos una persona "ficticia" con solo el ID para usar el comparador
    Persona personaABorrar{idABorrar, "", 0};

    auto it = personas.find(personaABorrar);
    if (it != personas.end()) {
        personas.erase(it);
        std::cout << "Persona con ID " << idABorrar << " eliminada." << std::endl;
    } else {
        std::cout << "La persona con ID " << idABorrar << " no fue encontrada." << std::endl;
    }
}

// Función para mostrar el tamaño del set
void mostrarTamanio(const std::set<Persona>& personas) {
    std::cout << "El set tiene " << personas.size() << " personas." << std::endl;
}

int main() {

    std::set<Persona> personas;

    // Insertar personas en el set
    insertarPersonas(personas);

    // Mostrar el contenido del set
    mostrarPersonas(personas);

    // Buscar una persona por ID
    buscarPersonaPorID(personas, 1); 

    // Borrar una persona por ID
    borrarPersonaPorID(personas, 1); 

    // Mostrar el tamaño del set
    mostrarTamanio(personas);

    return 0;
}
