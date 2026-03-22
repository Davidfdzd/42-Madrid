#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>
#include <cstddef>

template <typename T>
class Array {
    private:
        T* data;
        size_t len;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();

        T& operator[](size_t index);
        const T& operator[](size_t index) const;

        class IndexOutOfBoundException : public std::exception {
            const char *what() const throw();
        };

        size_t size() const;
};

#include "Array.tpp"

#endif