#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
    this->fixed_point_number = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &r)
{
    std::cout << "Copy constructor called" << std::endl;
    this->fixed_point_number = r.fixed_point_number;
}

Fixed &Fixed::operator=(const Fixed &copyFixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->fixed_point_number = copyFixed.fixed_point_number;
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixed_point_number);
}

void Fixed::setRawBits(int const raw)
{
    this->fixed_point_number = raw;
}