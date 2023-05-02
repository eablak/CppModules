#include "Ice.hpp"
#include <iostream>

Ice::Ice()
{
    std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &r)
{
    std::cout << "Ice copy constructor called" << std::endl;
    *this = r;
}

Ice &Ice::operator=(const Ice &r)
{
    std::cout << "Ice copy assignment constructor called" << std::endl;
    this->type = r.type;
    return (*this);
}

Ice::~Ice()
{
    std::cout << "Ice destructor called" << std::endl; 
}

AMateria* Ice::clone()const
{
    return (new Ice());
}

void Ice::use(ICharacter &target)
{
    std::cout <<  "shoots an ice bolt at " << target.getName() << std::endl;
}