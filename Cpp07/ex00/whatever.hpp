#include <iostream>

template <typename T>

void swap(T &x, T &y)
{
    T temp;

    temp = x;
    x = y;
    y = temp;
}


template <typename T2>

T2 min(T2 x, T2 y)
{
    if (x < y)
        return x;
    else
        return y;
}

template <typename T3>

T3 max(T3 x, T3 y)
{
    if (x > y)
        return x;
    else
        return y;
}