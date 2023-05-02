#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat default constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &r)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = r;
}

WrongCat &WrongCat::operator=(const WrongCat &r)
{
    std::cout << "WrongCat copy assignment called" << std::endl;
    if (this == &r)
        return (*this);
    *this = r;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound()
{
    std::cout << "WrongCat sound!" << std::endl;
}