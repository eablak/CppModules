#include "Span.hpp"

Span::Span(){ this->_size = 0; }
Span::Span(unsigned int number) { this->_size = number; }
Span::Span(const Span &copyS) { *this = copyS; }
Span &Span::operator=(const Span &copyS){ 
    this->_size = copyS._size;
    this->my_vector = copyS.my_vector;
    return *this; }
Span::~Span(){}

void Span::addNumber(int number)
{
    if (my_vector.size() >= this->_size )
        throw VectorFull();
    my_vector.push_back(number);
}

unsigned int Span::shortestSpan()
{
    if (my_vector.size() == 0 || my_vector.size() == 1)
        throw NoSpan();

    int shortest = 2147483647;
    for(unsigned int i = 0;i < my_vector.size(); i++)
        for(unsigned int j = i + 1; j < my_vector.size(); j++)
            if (abs(my_vector[i] - my_vector[j]) < shortest )
                shortest = abs(my_vector[i] - my_vector[j]);
    return (shortest);
}

unsigned int Span::longestSpan()
{
    if (my_vector.size() == 0 || my_vector.size() == 1)
        throw NoSpan();

    int longest = 0;
    for(unsigned int i = 0;i < my_vector.size(); i++)
        for(unsigned int j = i + 1; j < my_vector.size(); j++)
            if (abs(my_vector[i] - my_vector[j]) > longest )
                longest = abs(my_vector[i] - my_vector[j]);
    return (longest);
}

void Span::print_vector()
{
    for(unsigned int i = 0; i < my_vector.size(); i++)
        std::cout << my_vector[i] << std::endl;
}