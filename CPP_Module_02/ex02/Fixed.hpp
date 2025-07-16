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
        
        Fixed &operator = (const Fixed &src);
        
        ~Fixed();

        bool operator>(const Fixed& fixed)const;
		bool operator<(const Fixed& fixed)const;
		bool operator>=(const Fixed& fixed)const;
		bool operator<=(const Fixed& fixed)const;
		bool operator==(const Fixed& fixed)const;
		bool operator!=(const Fixed& fixed)const;

		Fixed operator+(const Fixed& fixed)const;
		Fixed operator-(const Fixed& fixed)const;
		Fixed operator*(const Fixed& fixed)const;
		Fixed operator/(const Fixed& fixed)const;

		Fixed& operator++();
		Fixed& operator--();

        Fixed operator++(int);
		Fixed operator--(int);

        float toFloat( void ) const;
        int toInt( void ) const;
        
        static Fixed& min(Fixed &a, Fixed &b);
        static const Fixed& min(const Fixed &a, const Fixed &b);
        static Fixed& max(Fixed &a, Fixed &b);
        static const Fixed& max(const Fixed &a, const Fixed &b);

        int getRawBits( void ) const;
        
        void setRawBits( int const raw );
    };
    
std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif