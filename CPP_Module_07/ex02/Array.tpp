#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template<typename T>
Array<T>::Array(void) : data(NULL), len(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : data(new T[n]()), len(n) {}

template<typename T>
Array<T>::Array(const Array &other) : data(new T[other.len]), len(other.len)
{
	for (size_t i = 0; i < other.len; ++i) {
		data[i] = other.data[i];
	}
}

template<typename T>
Array<T>::~Array(void) {
	delete[] data;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		delete[] data;
		len = other.len;
		data = new T[len];
		for (size_t i = 0; i < len; ++i)
			data[i] = other.data[i];
	}
	return (*this);
}

template<typename T>
T& Array<T>::operator[](size_t index)
{
	if (index >= len)
		throw IndexOutOfBoundException();
	return(data[index]);
}

template<typename T>
const char*	Array<T>::IndexOutOfBoundException::what() const throw() {
	return ("Index out of bounds!!!");
}


template<typename T>
const T& Array<T>::operator[](size_t index) const {
	if (index >= len)
		throw IndexOutOfBoundException();
	return(data[index]);
}

template<typename T>
size_t	Array<T>::size(void) const {
	return (len);
}

#endif