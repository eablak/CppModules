#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &r)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = r;
}

Brain &Brain::operator=(const Brain &r)
{
    std::cout << "Brain copy assignment called" << std::endl;
    for(int i = 0; i < 100; i++)
        this->ideas[i] = r.ideas[i];
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}