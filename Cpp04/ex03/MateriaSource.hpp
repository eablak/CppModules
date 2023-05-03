#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"

class MateriaSource:public IMateriaSource
{
    private:
    AMateria *materia[4];

    public:
    MateriaSource();
	MateriaSource(const MateriaSource& copy);
	MateriaSource& operator=(const MateriaSource& copy);
	~MateriaSource(void);

    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);    
};

#endif