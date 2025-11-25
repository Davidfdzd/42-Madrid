#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    std::cout << "=== Test 1: Creación de objetos válidos ===\n";
    try {
        Bureaucrat alice("Alice", 3);
        Form taxForm("TaxForm", 5, 10);

        std::cout << alice << std::endl;
        std::cout << taxForm << std::endl;

        std::cout << "\nAlice intenta firmar el formulario:\n";
        alice.signForm(taxForm);
        std::cout << taxForm << std::endl;

        std::cout << "\nIncrementamos la autoridad de Alice:\n";
        alice.incrementGrade(); // pasa de 3 -> 2
        std::cout << alice << std::endl;

        alice.signForm(taxForm); // ahora debería firmarlo
        std::cout << taxForm << std::endl;

    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Creación de objetos con grades inválidos ===\n";
    try {
        Bureaucrat bob("Bob", 0);          // invalido → GradeTooHighException
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Form secretForm("SecretForm", 0, 10); // invalido → GradeTooHighException
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Form junkForm("JunkForm", 151, 100); // invalido → GradeTooLowException
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}