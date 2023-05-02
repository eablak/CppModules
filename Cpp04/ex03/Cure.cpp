#include "Cure.hpp"
#include <iostream>

Cure::Cure()
{
    std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &r)
{
    std::cout << "Cure copy constructor called" << std::endl;
    *this = r;
}

Cure &Cure::operator=(const Cure &r)
{
    std::cout << "Cure copy assignment constructor called" << std::endl;
    this->type = r.type;
    return (*this);
}

Cure::~Cure()
{
    std::cout << "Cure destructor called" << std::endl; 
}

AMateria* Cure::clone()const
{
    return (new Cure());
}

void Cure::use(ICharacter &target)
{
    std::cout <<  "heals" << target.getName() <<  "wounds" << std::endl;
}