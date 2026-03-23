#include "bigint.hpp"

void	bigint::normalize()
{
	int pos = 0;
	while (_str[pos] && _str[pos] == '0')
		pos++;
	if (pos > 0)
		_str.erase(0, pos);
}

void	bigint::validate(const std::string& str)
{
	if (str.empty())
		throw	std::invalid_argument("Error empty str");
	for (size_t i = 0; i < str.size(); i++)
		if (!std::isdigit(str[i]))
			throw	std::invalid_argument("Error invalid char in str");
}

static unsigned	long long	str_to_ull(const std::string& str)
{
	unsigned long long res = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
			throw	std::invalid_argument("Error invalid char in str bit shift");
		res = res * 10 + str[i] - '0';
	}
	return res;
}

bigint::bigint() : _str("0") {}

bigint::bigint(unsigned int n)
{
	std::ostringstream os;
	os << n;
	_str = os.str();
	normalize();
}

bigint::bigint(const std::string& str)
{
	validate(str);
	_str = str;
	normalize();
}

bigint::bigint(const bigint& other) : _str(other._str) {}

bigint&	bigint::operator=(const bigint& other)
{
	validate(other._str);
	if (this != &other)
		_str = other._str;
	return *this;
}

bigint::~bigint() {}

std::string	bigint::getStr() const
{
	return(_str);
}

bigint	bigint::operator+(const bigint& other) const
{
	std::string a = _str;
	std::string b = other._str;
	std::string res = "";

	int i = a.size() - 1;
	int j = b.size() - 1;
	int carry = 0;
	while (i >= 0 || j >= 0 || carry)
	{
		int da = (i >= 0) ? a[i] - '0' : 0;
		int db = (j >= 0) ? b[j] - '0' : 0;

		int sum = da + db + carry;
		carry = sum / 10;
		res.insert(res.begin(), char(sum % 10) + '0');

		i--;
		j--;
	}
	return bigint(res);
}

bigint	bigint::operator-(const bigint& other) const
{
	std::string a = _str;
	std::string b = other._str;
	std::string res = "";

	int i = a.size() - 1;
	int j = b.size() - 1;
	int borrow = 0;

	while (i >= 0)
	{
		int da = a[i] - '0' - borrow;
		int db = (j >= 0) ? b[i] - '0' : 0;

		if (da < db)
		{
			da += 10;
			borrow = 1;
		}
		else
			borrow = 0;
		
		int dif = da - db;
		res.insert(res.begin(), char(dif % 10));
		i--;
		j--;
	}
	bigint result(res);
	result.normalize();
	return result;
}

bigint&	bigint::operator+=(const bigint& other)
{
	*this = *this + other;
	return *this;
}

bigint	bigint::operator++(int)
{
	bigint tmp = *this;
	*this += bigint(1);
	return tmp;
}

bigint&	bigint::operator++()
{
	*this += bigint(1);
	return *this;
}

bool	bigint::operator<(const bigint& other)
{
	return (_str.size() < other._str.size() &&  _str < other._str);
}

bool	bigint::operator>(const bigint& other)
{
	return !(*this < other);
}

bool	bigint::operator<=(const bigint& other)
{
	return !(this > &other);
}

bool	bigint::operator>=(const bigint& other)
{
	return !(this < &other);
}

bool	bigint::operator==(const bigint& other)
{
	return _str == other._str;
}

bool	bigint::operator!=(const bigint& other)
{
	return !(*this == other);
}

bigint	bigint::operator<<(unsigned int n)
{
	if (_str == "0") return *this;
	bigint res(*this);
	res._str.append(n, '0');
	return res;
}

bigint	bigint::operator<<(const bigint& other)
{
	unsigned long long shift = str_to_ull(other._str);
	return *this << (unsigned int) shift;
}

bigint	bigint::operator>>(unsigned int n)
{
	if (n >= this->_str.size()) return bigint("0");
	bigint res(*this);
	res._str.erase(res._str.size() - n);
	return res;
}

bigint	bigint::operator>>(const bigint& other)
{
	unsigned long long shift = str_to_ull(other._str);
	return *this >> (unsigned int) shift;
}

bigint&	bigint::operator<<=(unsigned int n)
{
	*this = *this << n;
	return *this;
}

bigint& bigint::operator<<=(const bigint& other)
{
	unsigned long long shift = str_to_ull(other._str);
	return *this <<= (unsigned int) shift;
}

bigint&	bigint::operator>>=(unsigned int n)
{
	*this = *this >> n;
	return *this;
}

bigint& bigint::operator>>=(const bigint& other)
{
	unsigned long long shift = str_to_ull(other._str);
	return *this >>= (unsigned int) shift;
}

std::ostream&	operator<<(std::ostream& os, const bigint& other)
{
	os << other.getStr();
	return os;
}
