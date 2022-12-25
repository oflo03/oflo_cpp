#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle() :p1(), p2()
{
}
Rectangle::Rectangle(const Point& a, const Point& b) : p1(a), p2(b)
{
}
Rectangle::Rectangle(const Rectangle& other) : p1(other.p1), p2(other.p2)
{
}
Rectangle::~Rectangle()
{
}

std::ostream& Rectangle::operatorOut(std::ostream& os)
{
	os << "Rectangle " << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << " ";
	return os;
}
std::istream& Rectangle::operatorIn(std::istream& is)
{
	is >> p1.x >> p1.y >> p2.x >> p2.y;
	return is;
}

void Rectangle::draw() const
{
	std::cout << "»ç°¢Çü - (" << p1.x << "," << p1.y << "), (" << p2.x << "," << p2.y << ")" << std::endl;
}