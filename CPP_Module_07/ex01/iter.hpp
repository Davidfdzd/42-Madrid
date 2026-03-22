#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstddef>

template <typename T_array, typename T_func>
void iter(T_array *array, const size_t length, T_func function) {
    for (size_t i = 0; i < length; ++i) {
        function(array[i]);
    }
}

#endif