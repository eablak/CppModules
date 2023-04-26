#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
    this->fixedPoint = 0;
}

Fixed::Fixed(int value)
{
    this->fixedPoint = value << mantissa;
}

Fixed::Fixed(const float value)
{
    this->fixedPoint = int(roundf(value * (1 << mantissa)));
}

Fixed::Fixed(const Fixed &copyFixed)
{
    *this = copyFixed;
}

Fixed &Fixed::operator=(const Fixed &copyFixed)
{
    this->fixedPoint = copyFixed.fixedPoint;
    return (*this);
}

Fixed::~Fixed()
{
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
    return ((float)this->fixedPoint / (float)(1 << mantissa));
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

bool Fixed::operator>(const Fixed &r) const
{
    return (this->fixedPoint > r.fixedPoint);
}


bool Fixed::operator<(const Fixed &r) const
{
    return (this->fixedPoint < r.fixedPoint);
}

bool Fixed::operator>=(const Fixed &r) const
{
    return (this->fixedPoint >= r.fixedPoint);
}

bool Fixed::operator<=(const Fixed &r) const
{
    return (this->fixedPoint <= r.fixedPoint);
}

bool Fixed::operator==(const Fixed &r) const
{
    return (this->fixedPoint == r.fixedPoint);
}

bool Fixed::operator!=(const Fixed &r) const
{
    return (this->fixedPoint != r.fixedPoint);
}

float Fixed::operator*(const Fixed &r)
{
    return (this->toFloat() * r.toFloat());
}

float Fixed::operator/(Fixed &r)
{
    return (this->toFloat() / r.toFloat());
}

float Fixed::operator-(Fixed &r)
{
    return (this->toFloat() - r.toFloat());

}

float Fixed::operator+(const Fixed &r)
{
    return (this->toFloat() + r.toFloat());

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