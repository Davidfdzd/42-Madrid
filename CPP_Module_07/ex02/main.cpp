#include <iostream>
#include "Array.hpp"

int main(void)
{
    try
    {
        // Crear un Array de 5 enteros
        Array<int> intArray(5);

        std::cout << "TESTING ARRAY CREATION + VALUE MODIFICATION..." << std::endl;
        for (size_t i = 0; i < intArray.size(); ++i)
            intArray[i] = static_cast<int>(i * 10);

        for (size_t i = 0; i < intArray.size(); ++i)
            std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;

        // Probar mi funcion size()
        std::cout << "intArray size: " << intArray.size() << std::endl;

        // Probar copia y modificar [0]
        std::cout << "TESTING COPY ARRAY + VALUE [0] MODIFICATION..." << std::endl;
        Array<int> copy = intArray;
        copy[0] = 999;
        std::cout << "copy[0] = " << copy[0] << " | intArray[0] = " << intArray[0] << std::endl;

        // Probar excepción por índice fuera de rango
        std::cout << "TESTING INDEX OUT OF BOUNDS EXCEPTION..." << std::endl;
        std::cout << intArray[100] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    return 0;
}