#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() {}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& other) : tree_bag(other) {}

searchable_tree_bag&	searchable_tree_bag::operator=(const searchable_tree_bag& other)
{
	if (this != & other)
		tree_bag::operator=(other);
	return *this;
}

bool	searchable_tree_bag::has(int n) const
{
	node	*node = tree;
	while (node)
	{
		if (node->value == n)
			return true;
		else if (n > node->value)
			node = node->r;
		else
			node = node->l;
	}
	return false;
}

