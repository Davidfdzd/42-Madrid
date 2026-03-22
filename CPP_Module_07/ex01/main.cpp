#include "iter.hpp"

template <typename T>
void printElement(const T &elem) {
    std::cout << elem << std::endl;
}

void addTen(int &n) {
    n += 10;
}

void square(int &n) {
    n = n * n;
}

int main() {
    // -------------------------------
    // 1. ARRAY DE INTS
    // -------------------------------
    int numbers[] = {1, 2, 3, 4, 5};

    std::cout << "Antes:" << std::endl;
    iter(numbers, 5, printElement<int>);

    iter(numbers, 5, addTen);

    std::cout << std::endl;
    std::cout << "Despues de addTen:" << std::endl;
    iter(numbers, 5, printElement<int>);

    iter(numbers, 5, square);

    std::cout << std::endl;
    std::cout << "Despues de square:" << std::endl;
    iter(numbers, 5, printElement<int>);

    // -------------------------------
    // 2. ARRAY DE STRINGS
    // -------------------------------
    const std::string words[] = {"Hola", "Adios", "Iter", "Template"};

    std::cout << std::endl;
    std::cout << "Strings:" << std::endl;
    iter(words, 4, printElement<std::string>);

    return 0;
}