#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for(int i = 0;i<4;i++)
        this->inventory[i] = 0;
	std::cout << "MateriaSource is created ! " << std::endl;
    
}

MateriaSource::MateriaSource( MateriaSource &r)
{
    for(int i=0;i < 4;i++)
    {
        if (r.inventory[i] != NULL)
            this->inventory[i] = r.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &r)
{
    for(int i = 0;i<4;i++)
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
    for(int i = 0;i<4;i++)
        delete this->inventory[i];
	std::cout << "MateriaSource is destructed !" << std::endl;
}

void MateriaSource::learnMateria(AMateria *m)
{
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

AMateria *MateriaSource::createMateria(std::string const &type)
{
   	int i = 0;
	while(i < 4 && this->inventory[i] != NULL &&  this->inventory[i]->getType() != type)
		i++;
	if (i >= 4 || !(this->inventory)[i])
	{
		std::cout << type << " materia does not exit\n";
		return (NULL);
	}
	return this->inventory[i]->clone();
}