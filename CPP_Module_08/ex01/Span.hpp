#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <stdexcept>
#include <climits>
#include <vector>
#include <algorithm>

class Span{
    private:
        unsigned int _maxN;
        std::vector<int> _numbers;
    public:
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int N);
        int shortestSpan() const;
        int longestSpan() const;
        void addNumber(std::vector<int>::iterator it1, std::vector<int>::iterator it2);
};

#endif