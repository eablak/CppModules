#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "AMateria.hpp"

class MateriaSource: public IMateriaSource
{
    private:
    AMateria *inventory[4];

    public:
    MateriaSource();
	MateriaSource(const MateriaSource &copy);
	~MateriaSource();
	MateriaSource &operator=(const MateriaSource &c);
    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const & type);
};

#endif