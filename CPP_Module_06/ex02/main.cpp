#include "Base.hpp"

int main()
{
    std::srand(std::time(NULL));

    for (int i = 1; i <= 10; i++)
        {
            std::cout << "\n===== Test " << i << " =====" << std::endl;

            Base* obj = generate();

            std::cout << "Por puntero:    ";
            identify(obj);

            std::cout << "Por referencia: ";
            identify(*obj);

            delete obj;
        }

    return 0;
}