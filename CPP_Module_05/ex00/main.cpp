#include "Bureaucrat.hpp"

int main(void)
{
	try {
		Bureaucrat a("Alice", 2);
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
		a.incrementGrade();
	} 
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "-----------------" << std::endl;

	try {
		Bureaucrat b("Bob", 151);
		std::cout << b << std::endl;
	} 
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}