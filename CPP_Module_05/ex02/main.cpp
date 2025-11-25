#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(NULL)); // Inicializa semilla para la robotomy aleatoria

    try {
        std::cout << " === CREACIÓN DE BUREAUCRATS === " << std::endl;
        Bureaucrat alice("Alice", 50);
        Bureaucrat bob("Bob", 1);
        Bureaucrat charlie("Charlie", 150);

        std::cout << alice << std::endl;
        std::cout << bob << std::endl;
        std::cout << charlie << std::endl;

        std::cout << " === CREACIÓN DE FORMULARIOS === " << std::endl;
        ShrubberyCreationForm shrubForm("home");
        RobotomyRequestForm robotForm("Marvin");
        PresidentialPardonForm pardonForm("Trillian");

        std::cout << shrubForm << std::endl;
        std::cout << robotForm << std::endl;
        std::cout << pardonForm << std::endl;

        std::cout << " === FIRMA DE FORMULARIOS === " << std::endl;
        alice.signForm(shrubForm);      // debería funcionar
        charlie.signForm(robotForm);    // debería fallar
        bob.signForm(robotForm);        // debería funcionar
        bob.signForm(pardonForm);       // debería funcionar

        std::cout << " === EJECUCIÓN DE FORMULARIOS === " << std::endl;
        alice.executeForm(shrubForm);   // crea archivo de arbustos
        bob.executeForm(robotForm);     // robotomy aleatoria
        bob.executeForm(pardonForm);    // mensaje de perdón

        std::cout << " === PRUEBAS DE EXCEPCIONES === " << std::endl;
        try {
            charlie.executeForm(pardonForm); // fallo: grado bajo
        } catch (const std::exception &e) {
            std::cerr << "Excepción capturada: " << e.what() << std::endl;
        }

        try {
            ShrubberyCreationForm invalidForm("garden");
            invalidForm.execute(bob); // fallo: no firmado
        } catch (const std::exception &e) {
            std::cerr << "Excepción capturada: " << e.what() << std::endl;
        }

        std::cout << "\n=== FIN DEL PROGRAMA ===" << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Excepción general: " << e.what() << std::endl;
    }

    return 0;
}