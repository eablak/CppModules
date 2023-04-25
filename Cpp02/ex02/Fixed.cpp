#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
    this->fixedPoint = 0;
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    // std::cout << "Int constructor called" << std::endl;
    this->fixedPoint = value << mantissa;
}

Fixed::Fixed(const float value)
{
    // std::cout << "Float constructor called" << std::endl;
    this->fixedPoint = int(roundf(value * (1 << mantissa)));
}

Fixed::Fixed(const Fixed &copyFixed)
{
    // std::cout << "Copy constructor called" << std::endl;
    Fixed::operator=(copyFixed);
}

Fixed &Fixed::operator=(const Fixed &copyFixed)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    this->fixedPoint = copyFixed.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
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
}

int Fixed::toInt(void) const
{
    return(this->fixedPoint >> mantissa);
}

std::ostream &operator<<(std::ostream &output, const Fixed &fixed)
{
    output << fixed.toFloat();
    return (output);
}

bool Fixed::operator>(const Fixed &r)
{
    return (this->fixedPoint > r.fixedPoint);
}


bool Fixed::operator<(const Fixed &r)
{
    return (this->fixedPoint < r.fixedPoint);
}

bool Fixed::operator>=(const Fixed &r)
{
    return (this->fixedPoint >= r.fixedPoint);
}

bool Fixed::operator<=(const Fixed &r)
{
    return (this->fixedPoint <= r.fixedPoint);
}

bool Fixed::operator==(const Fixed &r)
{
    return (this->fixedPoint == r.fixedPoint);
}

bool Fixed::operator!=(const Fixed &r)
{
    return (this->fixedPoint != r.fixedPoint);
}

Fixed Fixed::operator*(const Fixed &r)
{
    Fixed ret;
    ret.setRawBits(this->fixedPoint * r.fixedPoint >> mantissa);
    return (ret);
}

Fixed Fixed::operator/(const Fixed &r)
{
    Fixed ret;
    ret.setRawBits(this->fixedPoint * (1 << mantissa) / r.fixedPoint);
    return (ret);
}

Fixed Fixed::operator-(const Fixed &r)
{
    Fixed ret;
    ret.setRawBits(this->fixedPoint - r.fixedPoint);
    return (ret);
}

Fixed Fixed::operator+(const Fixed &r)
{
    Fixed ret;
    ret.setRawBits(this->fixedPoint + r.fixedPoint);
    return (ret);
}

Fixed &Fixed::operator++()
{
    this->fixedPoint++;
    return (*this);
}

Fixed &Fixed::operator--()
{
    this->fixedPoint--;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed x;
    x = *this;
    ++*this;
    return (x);
}

Fixed Fixed::operator--(int)
{
    Fixed x = *this;
    --*this;
    return (x);
}

Fixed &Fixed::min(Fixed &r1, Fixed &r2)
{
    return (r1.fixedPoint < r2.fixedPoint) ? r1 : r2;
}

const Fixed &Fixed::min(const Fixed &r1, const Fixed &r2)
{
    return (r1.fixedPoint < r2.fixedPoint) ? r1 : r2;
}

Fixed &Fixed::max(Fixed &r1, Fixed &r2)
{
    return (r1.fixedPoint > r2.fixedPoint) ? r1 : r2;
}

const Fixed &Fixed::max(const Fixed &r1, const Fixed &r2)
{
    return (r1.fixedPoint > r2.fixedPoint) ? r1 : r2;
}