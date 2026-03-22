#include "Span.hpp"

int main(void)
{
    /*----------------------------------------------------------*/
    /*                  TEST BÁSICO CON 4 NÚMEROS               */
    /*----------------------------------------------------------*/
    try
    {
        std::cout << ">>> TEST CON 4 NÚMEROS (Añadir, Calcular el rango) <<<" << std::endl;
        Span sp(4);  // Creamos un Span con capacidad para 4 números
        sp.addNumber(7);  // Añadimos el número 7
        sp.addNumber(2);  // Añadimos el número 2
        sp.addNumber(15); // Añadimos el número 15
        sp.addNumber(10); // Añadimos el número 10

        // Calculamos el "span" más corto y el más largo
        std::cout << "El span más corto es: " << sp.shortestSpan() << std::endl;
        std::cout << "El span más largo es: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error capturado: " << e.what() << std::endl;
    }

    /*----------------------------------------------------------*/
    /*           PROBAR EXCEDE LA CAPACIDAD DEL SPAN            */
    /*----------------------------------------------------------*/
    try
    {
        std::cout << "\n>>> PROBAR: AÑADIR MÁS DE LO PERMITIDO <<<" << std::endl;
        Span sp(2);  // Creamos un Span con capacidad para 2 números
        sp.addNumber(12);  // Añadimos el número 12
        sp.addNumber(5);   // Añadimos el número 5
        sp.addNumber(8);   // Intentamos añadir más, debería fallar
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error esperado: " << e.what() << std::endl;
    }

    /*----------------------------------------------------------*/
    /*               PROBAR VALORES DUPLICADOS                  */
    /*----------------------------------------------------------*/
    try
    {
        std::cout << "\n>>> PROBAR: AÑADIR UN VALOR DUPLICADO <<<" << std::endl;
        Span sp(3);  // Creamos un Span con capacidad para 3 números
        sp.addNumber(3);   // Añadimos el número 3
        sp.addNumber(8);   // Añadimos el número 8
        sp.addNumber(3);   // Intentamos añadir el número 3 otra vez (duplicado)
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error esperado: " << e.what() << std::endl;
    }

    /*----------------------------------------------------------*/
    /*               COMPROBAR SI HAY POCOS ELEMENTOS           */
    /*----------------------------------------------------------*/
    try
    {
        std::cout << "\n>>> PROBAR: NO HAY SUFICIENTES ELEMENTOS PARA EL RANGO MÁS CORTO <<<" << std::endl;
        Span sp(2);  // Creamos un Span con capacidad para 2 números
        sp.addNumber(50);  // Añadimos el número 50
        std::cout << "El span más corto es: " << sp.shortestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error esperado: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n>>> PROBAR: NO HAY SUFICIENTES ELEMENTOS PARA EL RANGO MÁS LARGO <<<" << std::endl;
        Span sp(2);  // Creamos un Span con capacidad para 2 números
        sp.addNumber(75);  // Añadimos el número 75
        std::cout << "El span más largo es: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error esperado: " << e.what() << std::endl;
    }

    /*----------------------------------------------------------*/
    /*               PROBAR CON UN RANGO GRANDE DE DATOS        */
    /*----------------------------------------------------------*/
    try
    {
        std::cout << "\n>>> PROBAR: CON UN RANGO GRANDE DE DATOS (10000 NÚMEROS) <<<" << std::endl;
        Span sp(10000);  // Creamos un Span con capacidad para 10,000 números
        std::vector<int> vec;
        
        // Llenamos el vector con números de 0 a 9999
        for (int i = 0; i < 10000; ++i)
            vec.push_back(i);
        
        // Añadimos el rango de números al Span
        sp.addNumber(vec.begin(), vec.end());

        // Calculamos los rangos más corto y más largo
        std::cout << "El span más corto es: " << sp.shortestSpan() << std::endl;
        std::cout << "El span más largo es: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error inesperado: " << e.what() << std::endl;
    }

    return 0;
}