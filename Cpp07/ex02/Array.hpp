#ifndef ARRAY_HPP
#define ARRAY_HPP

template<class T>class Array{

    T* arr;
    unsigned int len;

    public:
    Array();
    Array(unsigned int n);
    Array(const Array &copyA);
    Array &operator=(const Array &copyA);
    ~Array();

    class OutOfRange: public std::exception
    {
        virtual const char* what() const throw()
        {
            return "Out of Range";
        }
    };
    
    T &operator[](unsigned int x)
    {
        if (x >= this->len)
            throw OutOfRange();
        else
            return this->arr[x];
    }

    unsigned int size(){
        return this->len;
    }
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
    this->len = copyA.len;
    this->arr = new T[this->len];
    for(unsigned int i = 0;i < this->len;i++)
        this->arr[i] = copyA.arr[i];
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &copyA)
{
    this->len = copyA.len;
    this->arr = new T[this->len];
    for(unsigned int i = 0;i<this->len;i++)
        this->arr[i] = copyA.arr[i];
    return (*this);
}

template<typename T>Array<T>
::~Array(){
    delete[] this->arr;
}

#endif