#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, int lenght, void (* function)(T))
{
    for(int i = 0; i < lenght; i++)
        function(array[i]);
}

#endif