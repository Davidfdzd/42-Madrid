#ifndef VECT2_HPP
# define VECT2_HPP

#include <iostream>
#include <vector>
#include <stdexcept> 

class vect2
{
	private:
		int	_x;
		int _y;
	
	public:
		vect2();
		vect2(int, int);
		vect2(const vect2&);

		~vect2();

		vect2& 		operator=(const vect2&);
		
		int&		operator[](int);
		const int&	operator[](int) const;

		// aritmética
		vect2	operator+(const vect2&) const;
		vect2	operator-(const vect2&) const;
		vect2	operator*(int) const;

		vect2&	operator+=(const vect2&);
		vect2&	operator-=(const vect2&);
		vect2&	operator*=(int);

		vect2&	operator++();
		vect2	operator++(int);
		vect2&	operator--();
		vect2	operator--(int);

		vect2	operator-() const;

		// comparaciones
		bool	operator==(const vect2&) const;
		bool	operator!=(const vect2&) const;
};

// multiplicaciones
vect2	operator*(int, const vect2&);

// output
std::ostream&	operator<<(std::ostream&, const vect2&);

#endif
