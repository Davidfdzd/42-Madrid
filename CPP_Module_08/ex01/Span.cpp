#include "Span.hpp"

Span::Span(unsigned int N) : _maxN(N) {}

Span::Span(const Span &other)
	: _maxN(other._maxN), _numbers(other._numbers) {}


Span& Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_maxN = other._maxN;
		_numbers = other._numbers;
	}
	return (*this);
}

Span::~Span() {}

void Span::addNumber(int N){
    if (_numbers.size() >= _maxN)
        throw std::runtime_error("Span reached the maximun number of elements");
    if (std::find(_numbers.begin(), _numbers.end(), N) != _numbers.end())
        throw std::runtime_error("Value already exists in Span");
    _numbers.push_back(N);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers");
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    int shortest = INT_MAX;
    for (size_t i = 1; i < sorted.size(); ++i) {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < shortest)
            shortest = diff;
    }
    return shortest;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers");
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    return (max - min);
}

void	Span::addNumber(std::vector<int>::iterator it1, std::vector<int>::iterator it2)
{
	size_t rangeSize = 0;
    std::vector<int>::iterator it = it1;
    while (it != it2) {
        ++rangeSize;
        ++it;
    }
	if (_numbers.size() + rangeSize > _maxN)
		throw std::runtime_error("Span reached the maximum number of elements");
	for (std::vector<int>::iterator it = it1; it != it2; ++it)
	{
		if (std::find(_numbers.begin(), _numbers.end(), *it) != _numbers.end())
			throw std::runtime_error("Duplicate value in range cannot be added");		
		_numbers.push_back(*it);
	}
}