#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource default constructor called" << std::endl;
    for(int i = 0;i < 4;i++)
        this->inventory[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &r)
{
    std::cout << "MateriaSource copy constructor called" << std::endl;
    for(int i = 0;i < 4;i++)
    {
        if(r.inventory[i] != NULL)
            this->inventory[i] = r.inventory[i]->clone();
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &r)
{
    std::cout << "MateriaSource copy assignment constructor called" << std::endl;
    for(int i = 0;i < 4;i++)
    {
        if (this->inventory[i] != NULL)
            delete this->inventory[i];
        if (r.inventory[i] != NULL)
        this->inventory[i] = r.inventory[i]->clone();
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor called" << std::endl;
    for(int i = 0;i < 4;i++)
    {
        if(this->inventory[i] != NULL)
            delete this->inventory[i];
    }
}

void MateriaSource::learnMateria(AMateria *m) {
	int i = 0;
	while(this->inventory[i] != NULL && i < 4)
		i++;
	if (i >= 4)
	{
		std::cout << "Can't learn more than 4 Materia";
		return ;
	}
	if(this->inventory[i] == NULL)
		this->inventory[i] = m;
	std::cout << "Materia "<< m->getType() <<" is Learned ! "<< std::endl;
}

AMateria *MateriaSource::createMateria(const std::string &type) {
	int i = 0;
	while(i < 4 && this->inventory[i] != NULL &&  this->inventory[i]->getType() != type)
		i++;
	if (i >= 4 || !(this->inventory)[i])
	{
		std::cout << type << "materia does not exit\n";
		return (NULL);
	}
	return this->inventory[i]->clone();
}