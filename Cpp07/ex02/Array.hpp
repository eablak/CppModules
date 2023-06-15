#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>class Array{

    T* arr;
    int len;

    public:
    Array();
    Array(unsigned int n);
    Array(const Array &copyA);
    Array &operator=(const Array &coppyA);
};

template<typename T>Array<T>::Array()
{
    this->arr = new T[1];
    this->arr[0] = NULL;
    this->len = 0;
}

template<typename T>Array<T>::Array(unsigned int n)
{
    this->arr = new T[n];
    this->len = n;
}

template<typename T>Array<T>::Array(const Array &copyA)
{
    * this = copyA; //
}

#endif