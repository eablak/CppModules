#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <exception>
#include <cmath>

class Span{

    std::vector<int> my_vector;
    unsigned int _size;

    public:
    Span();
    Span(unsigned int number);
    Span(const Span &copyS);
    Span &operator=(const Span &copyS);
    ~Span();

    void addNumber(int number);

    class VectorFull : public std::exception
    {
        virtual const char* what() const throw()
        {
            return "Vector is Full";
        }
    };

    unsigned int shortestSpan();
    unsigned int longestSpan();

    class NoSpan : std::exception
    {
        virtual const char* what() const throw()
        {
            return "No Span";
        }
    };

    void print_vector();

};

#endif