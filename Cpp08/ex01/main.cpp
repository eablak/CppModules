#include "Span.hpp"
#include <iostream>

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    // sp.print_vector();

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;


    // Span my_sp(10000);
    // for(int i = 0;i < 10000;i++)
    //     my_sp.addNumber(i);


    // std::cout << my_sp.shortestSpan() << std::endl;
    // std::cout << my_sp.longestSpan() << std::endl;
}