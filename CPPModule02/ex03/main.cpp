#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main(void) {
	Point a(0, 15);
	Point b(3, 12);
	Point c(5, 13);
	Point point(3, 13);
	if (bsp(a, b, c, point) == true)
		cout << "Point is inside the triangle" << endl;
	else
		cout << "Point is not inside the triangle" << endl;
	return 0;
}