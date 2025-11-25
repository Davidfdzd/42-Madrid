/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:46:35 by dfernan3          #+#    #+#             */
/*   Updated: 2025/09/02 16:52:28 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
        materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& copy) {
    for (int i = 0; i < 4; i++) {
        if (copy.materias[i] != NULL)
            materias[i] = copy.materias[i]->clone();
        else
            materias[i] = NULL;
    }
}


MateriaSource& MateriaSource::operator=(const MateriaSource& copy) {
    if (this != &copy) {
        for (int i = 0; i < 4; i++) {
            if (materias[i]) {
                delete materias[i];
                materias[i] = NULL;
            }
            if (copy.materias[i])
                materias[i] = copy.materias[i]->clone();
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++)
        if (materias[i])
            delete materias[i];
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; i++) {
        if (!materias[i]) {
            materias[i] = m->clone();
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (materias[i] && materias[i]->getType() == type)
            return materias[i]->clone();
    }
    return NULL;
}