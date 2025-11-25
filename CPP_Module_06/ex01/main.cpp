#include "Serializer.hpp"

int main(void)
{
    Data data;
    data.id = 42;
    data.name = "dfernan3";

    std::cout << "~Antes de serializar~" << std::endl;
    std::cout << data.name << "_" << data.id << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    Data *copy = Serializer::deserialize(raw);

    std::cout << "~Después de deserializar~" << std::endl;
    std::cout << copy->name << "_" << copy->id << std::endl;

    if (copy == &data)
        std::cout << "✅ El puntero deserializado coincide con el original" << std::endl;
    else
        std::cout << "❌ Error: los punteros no coinciden" << std::endl;

    return 0;
}