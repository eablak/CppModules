#include "Character.hpp"
#include <iostream>

Character::Character()
{
    std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string name)
{
    std::cout << "Character " << name << " is created" << std::endl;
    for(int i = 0;i < 4;i++)
        this->inventory[i] = NULL;
}

Character::Character(const Character &r)
{
    std::cout << "Character copy constructor called" << std::endl;
    for(int i = 0;i < 4;i++)
        this->inventory[i] = r.inventory[i];
    this->name = r.getName();
    *this = r;
}

Character &Character::operator=(const Character &r)
{
    std::cout << "Character copy assignment constructor called" << std::endl;
    for(int i = 0;i < 4;i++)
    {
        if (this->inventory[i])
            delete this->inventory[i];
        this->inventory[i] = r.inventory[i]->clone();
    }
    return (*this);
}

Character::~Character()
{
    std::cout << "Character destructor called" << std::endl; 
    for(int i = 0;i < 4;i++)
        delete this->inventory[i];
}

const std::string& Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria *m)
{
    int i = 0;
    if (m == NULL)
    {
        std::cout << "Null Ametaria" << std::endl;
        return ;
    }
    while(i < 4 && this->inventory[i] != NULL)
        i++;
    if (i < 4 && this->inventory[i] == NULL)
        this->inventory[i] = m;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
    {
        std::cout << "Invalid input" << std::endl;
        return ;
    }
    if (this->inventory[idx] == NULL)
    {
        std::cout << "Character is already null" << std::endl;
        return ;
    }
    this->inventory[idx] = 0;
    std::cout << "Character unequipped" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4)
    {
        std::cout << "Invalid input" << std::endl;
        return ;
    }
    if (this->inventory[idx] == NULL)
    {
        std::cout << "Character is null" << std::endl;
        return ;
    }
    this->inventory[idx]->use(target);
}