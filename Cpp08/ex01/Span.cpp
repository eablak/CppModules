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
    if (!my_vector.empty())
    {
        for(unsigned int i = 0; i < this->_size; i++)
        {
            if (this->my_vector[i] == number)
                throw AlreadyExist();
        }
    }
    my_vector.push_back(number);
}


void Span::print_vector()
{
    for(unsigned int i = 0; i < my_vector.size(); i++)
        std::cout << my_vector[i] << std::endl;
}