#include "Point.hpp"

Point::Point(): _x(0), _y(0)
{
}

Point::Point(const float nb1, const float nb2): _x(nb1), _y(nb2)
{
}

Point::Point(const Point &a): _x(a._x), _y(a._y)
{
}

Point &Point::operator=(Point &a){
	return a;
}

Point::~Point(){
}

float Point::getxfloat(void){
	return(_x.toFloat());
}

float Point::getyfloat(void){
	return(_y.toFloat());
}