#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main(void) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Point a1;
	Point b2;
	Point c2;
	Point point;
	if (a != b)
		cout << "Now we're talking" << endl;
	bsp(a1, b2, c2, point);
	return 0;
}