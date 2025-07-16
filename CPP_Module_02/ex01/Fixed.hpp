#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed{
    private:
        int _fixedPointValue;
        static const int _fractionalBits;
    public:
        Fixed();
        Fixed(const Fixed &copy);
        Fixed(const int n);
        Fixed(const float f); 
        Fixed& operator=(const Fixed& copy);
        ~Fixed();
        float toFloat( void ) const;
        int toInt( void ) const;
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif