#include "Point.h"
#include "Shape.h"

class Rectangle : public Shape
{
	Point p1, p2;

public:
	Rectangle();
	Rectangle(const Point&,const Point&);
	Rectangle(const Rectangle&);
	~Rectangle();

	virtual std::ostream& operatorOut(std::ostream&) override;
	virtual std::istream& operatorIn(std::istream&) override;
	virtual void draw() const override;
};