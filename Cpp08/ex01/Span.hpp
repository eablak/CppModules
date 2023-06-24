#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <exception>

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

    class AlreadyExist : public std::exception
    {
        virtual const char* what() const throw()
        {
            return "Value Already Exist";
        }
    };

    unsigned int shortestSpan();
    unsigned int longestSpan();

    class NoNumber : std::exception
    {
        virtual const char* what() const throw()
        {
            return "No Number";
        }
    };

    void print_vector();

};

#endif