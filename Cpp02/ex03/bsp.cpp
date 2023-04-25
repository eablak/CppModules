#include "Point.hpp"
#include <iostream>


bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	// std::cout << b.getX().toFloat() << std::endl;
	float bx, by, cx, cy, x, y;

	bx = b.getX().toFloat() - a.getX().toFloat();
	by = b.getY().toFloat() - a.getY().toFloat();
	cx = c.getX().toFloat() - a.getX().toFloat();
	cy = c.getY().toFloat() - a.getY().toFloat();
	x = point.getX().toFloat() - a.getX().toFloat();
	y = point.getY().toFloat() - a.getY().toFloat();

	float d, WA, WB, WC;
	d = bx * cy - cx * by;
	WA = (x * (by - cy) + y * (cx - bx) + bx * cy - cx * by) / d;
	WB = (x * cy - y * cx) / d;
	WC = (y * bx - x * by) / d;

	// std::cout << "degerler" << std::endl;
	// std::cout << "bx: " << bx << " by: " << by << " cx: " << cy
	//     << " x: " << x << " y: " << y << " d: " << d << " WA: "
	//     << WA << " WB: " << WB << " WC: " << WC << std::endl;
	if ((WA >= 0.f && WA <= 1.f) && (WB >= 0.f && WB <= 1.f) && (WC >= 0.f
			&& WC <= 1.f))
	{
		return (true);
	}
	else
		return (false);
}