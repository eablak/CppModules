#include <iostream>
#include "Point.hpp"

int main( void )
{
    const Point a(1.f, 1.f);
    const Point b(2.f, 5.f);
    const Point c(5.f, 4.f);
    const Point p1(2.f, 3.f);
    const Point p2(3.f, 2.f);
    const Point p3(3.f, 3.f);
    const Point p4(5.0f, 0.f);

    std::cout << "p1 is " << (bsp(a, b, c, p1) ? "in" : "not in") << " the triangle" << std::endl;
    std::cout << "p2 is " << (bsp(a, b, c, p2) ? "in" : "not in") << " the triangle" << std::endl;
    std::cout << "p3 is " << (bsp(a, b, c, p3) ? "in" : "not in") << " the triangle" << std::endl;
    std::cout << "p4 is " << (bsp(a, b, c, p4) ? "in" : "not in") << " the triangle" << std::endl;
}
