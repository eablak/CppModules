#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    Fixed const x;
    Fixed const y;

    public:
    Point();
    Point(const float x, const float y);
    Point(const Point &copyPoint);
    Point &operator = (const Point &copyPoint);
    ~Point();

    Fixed const getX(void) const;
    Fixed const getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif