#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for(int i = 0;i<4;i++)
        this->materia[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &r)
{
    for(int i=0;i < 4;i++)
    {
        if (!r.materia[i])
            this->materia[i] = r.materia[i]->clone();
        else
            this->materia[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &r)
{
    for(int i = 0;i<4;i++)
    {
        if (this->materia[i] != NULL)
            delete this->materia[i];
        if (r.materia[i] != NULL)
            this->materia[i] = r.materia[i]->clone();
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for(int i = 0;i<4;i++)
        delete this->materia[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (!m)
    {
        for(int i = 0;i<4;i++)
        {
            if (this->materia[i] == NULL)
            {
                this->materia[i] = m;
                break;;
            }
        }    
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for(int i = 0;i<4;i++)
    {
        if (this->materia[i] != NULL && this->materia[i]->getType() == type)
            return (this->materia[i]->clone());
    }
    return (NULL);
}