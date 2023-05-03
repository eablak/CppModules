#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"

class MateriaSource:public IMateriaSource
{
    private:
    AMateria *inventory[4];

    public:
    MateriaSource();
	MateriaSource( MateriaSource& copy);
	MateriaSource& operator=(const MateriaSource& copy);
	~MateriaSource(void);

    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);    
};

#endif