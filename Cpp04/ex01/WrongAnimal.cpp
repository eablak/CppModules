#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &r)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = r;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &r)
{
    std::cout << "WrongAnimal copy assignment called" << std::endl;
    this->type = r.type;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "This is wronganimal sound" << std::endl;
}