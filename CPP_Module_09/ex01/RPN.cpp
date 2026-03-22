#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) : s(other.s) {}

RPN&	RPN::operator=(const RPN& other)
{
	if (this != &other)
		s = other.s;
	return (*this);
}

RPN::~RPN() {}

int RPN::evaluate(const std::string& expression) {
    std::istringstream iss(expression); //flujo que lee token por token
    std::string token; //donde guardo numero u operador

    while (iss >> token) {
        if (token.size() == 1 && std::isdigit(token[0])) {
            s.push(token[0] - '0'); //convierte char en int
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (s.size() < 2) { //verificar 2 numeros atras en la pila
                throw std::runtime_error("Error");
            }
            int b = s.top(); s.pop(); //pop para eliminarlos de la pila para operar
            int a = s.top(); s.pop();
            if (token == "+") s.push(a + b);
            else if (token == "-") s.push(a - b);
            else if (token == "*") s.push(a * b);
            else if (token == "/") {
                if (b == 0) throw std::runtime_error("Error");
                s.push(a / b);
            }
        } else {
            throw std::runtime_error("Error");
        }
    }

    if (s.size() != 1) throw std::runtime_error("Error"); //al final en la pila tiene que haber solo 1 valor
    return s.top();
}