#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include <iostream>

class MateriaSource : public IMateriaSource {
private:
    AMateria* materias[4];

public:
    MateriaSource();
    MateriaSource(const MateriaSource& copy);
    MateriaSource& operator=(const MateriaSource& copy);
    ~MateriaSource();

    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const & type);
};

#endif