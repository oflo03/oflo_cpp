#include <iostream>
#include "Circle.h"

Circle::Circle() : center(), rad(0.0)
{
}

Circle::Circle(const Point& c, int r) : center(c), rad(r)
{
}

Circle::Circle(const Circle& other) : center(other.center), rad(other.rad)
{
}

Circle::~Circle()
{
}

std::ostream& Circle::operatorOut(std::ostream& os)
{
	os << "Circle " << center.x << " " << center.y << " " << rad << " ";
	return os;
}
std::istream& Circle::operatorIn(std::istream& is)
{
	is >> center.x >> center.y >> rad;
	return is;
}
void Circle::draw() const
{
	std::cout << "원 - 중심점(" << center.x << "," << center.y << ") 반지름 " << rad << std::endl;
}