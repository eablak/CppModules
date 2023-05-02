#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
{
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &r)
{
    std::cout << "AMateria copy constructor called" << std::endl;
    *this = r;
}

AMateria &AMateria::operator=(const AMateria &r)
{
    std::cout << "AMateria copy assignment constructor called" << std::endl;
    this->type = r.type;
    return (*this);
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called" << std::endl; 
}

AMateria::AMateria(std::string const &type)
{
    std::cout << "AMateria constructor called" << std::endl;
    this->type = type;
}

std::string const &AMateria::getType() const
{
    return (this->type);
}

void AMateria::use(ICharacter &target)
{
}