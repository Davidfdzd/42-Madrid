#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>

class RPN {
    private:
        std::stack<int> s;

    public:
        RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();
        
        int evaluate(const std::string& expression);
};

#endif