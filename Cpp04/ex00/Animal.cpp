#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &r)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = r;
}

Animal &Animal::operator=(const Animal &r)
{
    std::cout << "Animal copy assignment called" << std::endl;
    this->type = r.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}