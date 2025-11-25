#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    try {
        // === CREACIÓN DE BUREAUCRATS ===
        Bureaucrat alice("Alice", 50);
        Bureaucrat bob("Bob", 1);
        Bureaucrat charlie("Charlie", 150);

        std::cout << alice << std::endl;
        std::cout << bob << std::endl;
        std::cout << charlie << std::endl;

        // === CREACIÓN DE UN INTERN ===
        Intern someIntern;

        // === INTERN CREA FORMULARIOS ===
        AForm* shrubForm  = someIntern.makeForm("shrubbery creation", "home");
        AForm* robotForm  = someIntern.makeForm("robotomy request", "Marvin");
        AForm* pardonForm = someIntern.makeForm("presidential pardon", "Trillian");
        AForm* unknownForm = someIntern.makeForm("unknown form", "Nobody"); // probar error

        std::cout << std::endl;

        // === FIRMAR FORMULARIOS ===
        if (shrubForm)  alice.signForm(*shrubForm);       // debería funcionar
        if (robotForm)  charlie.signForm(*robotForm);     // debería fallar
        if (robotForm)  bob.signForm(*robotForm);         // debería funcionar
        if (pardonForm) bob.signForm(*pardonForm);        // debería funcionar

        std::cout << std::endl;

        // === EJECUTAR FORMULARIOS ===
        if (shrubForm)  alice.executeForm(*shrubForm);    // creación de archivo
        if (robotForm)  bob.executeForm(*robotForm);      // robotomy aleatoria
        if (pardonForm) bob.executeForm(*pardonForm);     // mensaje de perdón

        std::cout << std::endl;

        // === PRUEBAS DE EXCEPCIONES ===
        try {
            if (pardonForm) 
                charlie.executeForm(*pardonForm);      // fallo: grade bajo
        } catch (const std::exception &e) {
            std::cerr << "Excepción capturada: " << e.what() << std::endl;
        }

        try {
            ShrubberyCreationForm invalidForm("garden");
            invalidForm.execute(bob); // fallo: no firmado
        } catch (const std::exception &e) {
            std::cerr << "Excepción capturada: " << e.what() << std::endl;
        }

        // === LIMPIEZA DE MEMORIA ===
        delete shrubForm;
        delete robotForm;
        delete pardonForm;
        delete unknownForm;

        std::cout << "\n=== FIN DEL PROGRAMA ===" << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Excepción general: " << e.what() << std::endl;
    }

    return 0;
}
