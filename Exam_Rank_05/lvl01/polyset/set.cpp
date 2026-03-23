#include "set.hpp"

set::set() : _bag(NULL) {}

set::set(const set& other)
{
	if (other._bag)
		_bag = other._bag;
	else
		_bag = NULL;
}

set::set(searchable_bag& other) : _bag(&other) {}

set&	set::operator=(const set& other)
{
	if (this != &other)
	{
		if (other._bag)
			_bag = other._bag;
		else
			_bag = NULL;
	}
	return *this;
}

set::~set()
{
	_bag->clear();
}

void	set::print()
{
	_bag->print();
}

void	set::insert(int n)
{
	if (!_bag->has(n))
		_bag->insert(n);
}

void	set::insert(int *tab, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!_bag->has(tab[i]))
			_bag->insert(tab[i]);
	}	
}

void	set::clear()
{
	_bag->clear();
}

bool	set::has(int n) const
{
	return _bag->has(n);
}

searchable_bag&	set::get_bag() const
{
	return *_bag;
}
