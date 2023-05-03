#include "Ice.hpp"

Ice::Ice():AMateria("ice")
{
    std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice &r):AMateria(r)
{
    std::cout << "Ice copy called" << std::endl;
    *this = r;
}

Ice &Ice::operator=(const Ice &r)
{
    std::cout << "Ice operator called" << std::endl;
    this->AMateria::operator=(r);
    return (*this);
}

Ice::~Ice()
{
    std::cout << "Destructor called" << std::endl;
}

Ice *Ice::clone()const
{
    return (new Ice());
}

void Ice::use(ICharacter &target) {
	std::cout << "Shoots an ice bolt at "<< target.getName() << std::endl;
}