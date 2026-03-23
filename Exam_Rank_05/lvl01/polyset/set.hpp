#ifndef SET_HPP
#define SET_HPP

#include <iostream>
#include "searchable_bag.hpp"

class set
{
	private:
		searchable_bag	*_bag;

	public:
		set();
		set(const set&);
		set(searchable_bag&);
		set&	operator=(const set&);

		~set();

		void	print();
		void	insert(int);
		void	insert(int *, int);
		void	clear();
		
		bool	has(int) const;
		
		searchable_bag&		get_bag() const;
};

#endif