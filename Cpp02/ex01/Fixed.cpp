#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
    this->fixedPoint = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixedPoint = value << mantissa;
    // this->fixedPoint = value * 256;
    // this->fixedPoint = value;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixedPoint = int(roundf(value * (1 << mantissa)));
    // float keep = value << mantissa;
    // this->fixedPoint = int(roundf(keep));
}

Fixed::Fixed(const Fixed &copyFixed)
{
    std::cout << "Copy constructor called" << std::endl;
    Fixed::operator=(copyFixed);
}

Fixed &Fixed::operator=(const Fixed &copyFixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->fixedPoint = copyFixed.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    return (this->fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
    this->fixedPoint = raw;
}

float Fixed::toFloat(void) const
{
    return float(this->fixedPoint) / (1 << mantissa);
    // return float(this->fixedPoint);
}

int Fixed::toInt(void) const
{
    // std::cout << " gelen sayi " << this->fixedPoint << " ";
    return(this->fixedPoint >> mantissa);
}

std::ostream &operator<<(std::ostream &output, const Fixed &fixed)
{
    output << fixed.toFloat();
    return (output);
}