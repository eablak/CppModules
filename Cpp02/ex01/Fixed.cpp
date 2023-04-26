#include "Fixed.hpp"
#include <cmath>
#include <iostream>


Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedPoint = 0;
}

Fixed::Fixed(int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPoint = value << mantissa;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPoint = int(roundf(value * (1 << mantissa)));
}

Fixed::Fixed(const Fixed &copyFixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copyFixed;
}

Fixed &Fixed::operator=(const Fixed &copyFixed)
{
	std::cout << "Assignment operator called" << std::endl;
	this->fixedPoint = copyFixed.fixedPoint;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor Called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits Called" << std::endl;
	return (this->fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPoint = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->fixedPoint / (float)(1 << mantissa));
}

int Fixed::toInt(void) const
{
	return (this->fixedPoint >> mantissa);
}

std::ostream &operator<<(std::ostream &output, const Fixed &fixed)
{
	output << fixed.toFloat();
	return (output);
}