#ifndef _Shape
#define _Shape

class Shape
{
public:
	Shape() {};
	~Shape() {};

	friend std::ostream& operator <<(std::ostream& os, Shape& s)
	{
		return s.operatorOut(os);
	}
	friend std::istream& operator >>(std::istream& is, Shape& s)
	{
		return s.operatorIn(is);
	}

	virtual std::ostream& operatorOut(std::ostream&) = 0;
	virtual std::istream& operatorIn(std::istream&) = 0;
	virtual void draw() const = 0;
};
#endif // _Shape