#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::Serializer(const Serializer& other){ (void)other; }

Serializer& Serializer::operator=(const Serializer& other){
    (void)other;
    return *this;
}

Serializer::~Serializer(){}

uintptr_t Serializer::serialize(Data* ptr){ //convertir puntero a entero
    return reinterpret_cast<uintptr_t>(ptr); //toma los bits de un puntero y los ve como un entero
}

Data* Serializer::deserialize(uintptr_t raw){ //convertir entero a puntero
    return reinterpret_cast<Data*>(raw); //castea a nivel de bits al reves. Reinterpresa como Data *. 
}