#ifndef BIGINT_HPP
# define BIGINT_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
#include <sstream>

class bigint
{
	private:
		std::string	_str;
		void	normalize();
		void	validate(const std::string&);
	
	public:
		bigint();
		bigint(unsigned int);
		bigint(const std::string&);
		bigint(const bigint&);

		bigint&	operator=(const bigint&);

		~bigint();

		std::string getStr() const;

		bigint	operator+(const bigint&) const;
		bigint	operator-(const bigint&) const;

		bigint&	operator+=(const bigint&);

		bigint	operator++(int);
		bigint& operator++();

		bool	operator<(const bigint&);
		bool	operator>(const bigint&);
		bool	operator<=(const bigint&);
		bool	operator>=(const bigint&);
		bool	operator==(const bigint&);
		bool	operator!=(const bigint&);

		bigint	operator<<(const bigint&);
		bigint	operator>>(const bigint&);
		bigint&	operator<<=(const bigint&);
		bigint&	operator>>=(const bigint&);

		bigint	operator<<(unsigned int n);
		bigint	operator>>(unsigned int n);
		bigint&	operator<<=(unsigned int n);
		bigint&	operator>>=(unsigned int n);
};

std::ostream&	operator<<(std::ostream&, const bigint&);

#endif