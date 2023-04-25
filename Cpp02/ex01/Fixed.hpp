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
};

std::ostream &operator << (std::ostream &output, const Fixed &fixed);

#endif

//istream sınıfı giriş için, ostream ise çıkış için  kullanılır .
