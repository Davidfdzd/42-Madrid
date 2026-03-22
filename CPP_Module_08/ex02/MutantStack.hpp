#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>{
    private:

    public:
        MutantStack();	
        MutantStack(const MutantStack& other);
        MutantStack& operator=(const MutantStack& other);
        ~MutantStack();
        
        typedef typename std::stack<T, Container>::container_type::iterator iterator;

        iterator begin();
        iterator end();
};

#include "MutantStack.tpp"

#endif