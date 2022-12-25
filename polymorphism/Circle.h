#include "Point.h"
#include "Shape.h"

class Circle : public Shape
{
	Point center;
	double rad;

public:
	Circle();
	Circle(const Point&, int);
	Circle(const Circle&);
	~Circle();

	virtual std::ostream& operatorOut(std::ostream&) override;
	virtual std::istream& operatorIn(std::istream&) override;
	virtual void draw() const override;
};