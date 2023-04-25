#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
    int fixedPoint;
    static const int mantissa = 8;
    
    public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed &copyFixed);
    Fixed &operator = (const Fixed &copyFixed);
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;

    bool operator>(const Fixed &r);
    bool operator<(const Fixed &r);
    bool operator>=(const Fixed &r);
    bool operator<=(const Fixed &r);
    bool operator==(const Fixed &r);
    bool operator!=(const Fixed &r);

    Fixed operator*(const Fixed &r);
    Fixed operator/(const Fixed &r);
    Fixed operator-(const Fixed &r);
    Fixed operator+(const Fixed &r);

    Fixed &operator++();
    Fixed &operator--();
    Fixed operator++(int);
    Fixed operator--(int);


    static Fixed &min(Fixed &r1, Fixed&r2);
    static const Fixed &min(const Fixed &r1, const Fixed&r2);
    static Fixed &max(Fixed &r1, Fixed&r2);
    static const Fixed &max(const Fixed &r1, const Fixed&r2);
};

std::ostream &operator << (std::ostream &output, const Fixed &fixed);

#endif
