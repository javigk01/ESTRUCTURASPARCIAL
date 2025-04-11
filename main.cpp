#include <iostream>
#include "ArbolGeneral.h"

void menuArbolGeneral() {
    ArbolGeneral<int> arbol;

    // Insertamos nodos
    arbol.insertarNodo(-1, 1); // -1 indica que es la raíz (asumiendo esta convención)
    arbol.insertarNodo(1, 2);
    arbol.insertarNodo(1, 3);
    arbol.insertarNodo(2, 4);
    arbol.insertarNodo(2, 5);
    arbol.insertarNodo(3, 6);
    arbol.insertarNodo(3, 7);

    std::cout << "\nRecorrido Preorden: ";
    arbol.preOrden();
    std::cout << std::endl;

    std::cout << "Recorrido Posorden: ";
    arbol.posOrden();
    std::cout << std::endl;

    std::cout << "Recorrido por Niveles: ";
    arbol.nivelOrden();
    std::cout << std::endl;

    // Probamos la búsqueda
    int val = 4;
    std::cout << "\nBuscar " << val << ": " 
              << (arbol.buscar(val) ? "Encontrado" : "No encontrado") << std::endl;

    // Eliminamos un nodo
    std::cout << "\nEliminando nodo 2..." << std::endl;
    arbol.eliminarNodo(2);

    std::cout << "Recorrido por Niveles después de eliminar 2: ";
    arbol.nivelOrden();
    std::cout << std::endl;
}

int main() {
    int opcion;
    do {
        std::cout << "\nSeleccione el tipo de árbol:\n";
        std::cout << "1. Árbol General\n";
        std::cout << "2. Árbol Binario Ordenado\n";
        std::cout << "3. Salir\n";
        std::cout << "Opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                menuArbolGeneral();
                break;
            case 2:
                std::cout << "Funcionalidad aún no implementada.\n";
                break;
            case 3:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 3);

    return 0;
}
