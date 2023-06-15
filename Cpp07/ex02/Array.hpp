#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>class Array{

    T* arr;
    int len;

    public:
    Array();
    Array(unsigned int n);
    Array(const Array &copyA);
    Array &operator=(const Array &copyA){
        this->len = coppyA.len;
        this->arr = new T[len];
        for(int i = 0;i<len;i++)
            this->arr[i] = coppyA.arr[i];
        return (*this);
    }
    ~Array();

    class OutOfRange: std::exception
    {
        virtual const char* what() const throw()
        {
            return "Out of Range";
        }
    }

    T &opeator[](unsigned int x)
    {
        if (x > =this->len)
            return OutOfRange;
        else
            return this->arr[this->len];
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
    *this = copyA; //
}

template<typename T>Array<T>
::~Array()
{
    delete[] this->arr;
}

// template<typename T>Array<T>
// ::Array &operator=(const Array &copyA)
// {

// }

#endif