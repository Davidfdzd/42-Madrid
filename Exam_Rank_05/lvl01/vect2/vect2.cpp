#include "vect2.hpp"

// --- CONSTRUCTORES DE CLASE --- //
vect2::vect2() : _x(0), _y(0) {}

vect2::vect2(int n1, int n2) : _x(n1), _y(n2) {}

vect2::vect2(const vect2& other) : _x(other._x), _y(other._y) {}

vect2::~vect2() {}

vect2&	vect2::operator=(const vect2& other)
{
	if (this != &other)
	{
		_x = other._x;
		_y = other._y;
	}
	return *this;
}

// --- OPERADOR DE RETORNO DE VALOR --- //
int&	vect2::operator[](int n)
{
	return (n == 0 ? _x : _y);
}

const int&	vect2::operator[](int n) const
{
	return (n == 0 ? _x : _y);
}

// --- OPERADORES DE ARITMÉTICA --- //
vect2	vect2::operator+(const vect2& other) const
{
	int v1 = _x + other._x;
	int v2 = _y + other._y;
	return (vect2(v1, v2));
}

vect2	vect2::operator-(const vect2& other) const
{
	int v1 = _x - other._x;
	int v2 = _y - other._y;
	return (vect2(v1, v2));
}

vect2	vect2::operator*(int n) const
{
	int v1 = _x * n;
	int v2 = _y * n;
	return (vect2(v1, v2));
}

vect2&	vect2::operator+=(const vect2& other)
{
	_x += other._x;
	_y += other._y;
	return *this;
}

vect2&	vect2::operator-=(const vect2& other)
{
	_x -= other._x;
	_y -= other._y;
	return *this;
}

vect2&	vect2::operator*=(int n)
{
	_x *= n;
	_y *= n;
	return *this;
}

vect2&	vect2::operator++()
{
	_x += 1;
	_y += 1;
	return *this;
}

vect2	vect2::operator++(int)
{
	vect2 tmp = *this;
	_x += 1;
	_y += 1;
	return tmp;
}

vect2&	vect2::operator--()
{
	_x -= 1;
	_y -= 1;
	return *this;
}

vect2	vect2::operator--(int)
{
	vect2 tmp = *this;
	_x -= 1;
	_y -= 1;
	return tmp;
}

vect2	vect2::operator-() const
{
	return vect2(-_x, -_y);
}

bool	vect2::operator==(const vect2& other) const
{
	return (_x == other._x && _y == other._y);
}

bool	vect2::operator!=(const vect2& other) const
{
	return !(*this == other);
}

vect2	operator*(int n, const vect2& other)
{
	return vect2(other[0] * n, other[1] * n);
}

std::ostream&	operator<<(std::ostream& os, const vect2& other)
{
	os << "{" << other[0] << ", " << other[1] << "}";
	return os; 
}
