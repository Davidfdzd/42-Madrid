#include "easyfind.hpp"
#include <list>

int main() {
    try {
        std::list<int> lst;

        // Agregar elementos uno por uno utilizando push_back
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        lst.push_back(40);
        lst.push_back(50);

        // Declarar el iterador y buscar el valor 30
        std::list<int>::iterator it = easyfind(lst, 30);  // 'it' es el iterador que devuelve easyfind
        std::cout << "Valor encontrado: " << *it << std::endl;  // Desreferenciar 'it' para imprimir el valor

        // Intento de buscar un valor que no existe (valor 60)
        it = easyfind(lst, 60);  // Buscar valor 60 (que no está en la lista)
        std::cout << "Valor encontrado: " << *it << std::endl;

    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}