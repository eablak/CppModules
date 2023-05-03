#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for(int i = 0;i<4;i++)
        this->inventory[i] = 0;
	std::cout << "MateriaSource is created ! " << std::endl;
    
}

MateriaSource::MateriaSource(const MateriaSource &r)
{
    for(int i=0;i < 4;i++)
    {
        if (!r.inventory[i])
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
    if (!m)
    {
        for(int i = 0;i<4;i++)
        {
            if (this->inventory[i] == NULL)
            {
                this->inventory[i] = m;
                break;;
            }
        }    
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for(int i = 0;i<4;i++)
    {
        if (this->inventory[i] != NULL && this->inventory[i]->getType() == type)
            return (this->inventory[i]->clone());
    }
    return (NULL);
}