#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
    int fixed_point_number;
    static const int bits = 8;
    
    public:
    Fixed();
    Fixed(const Fixed &copyFixed);
    Fixed &operator = (const Fixed &copyFixed);
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

#endif