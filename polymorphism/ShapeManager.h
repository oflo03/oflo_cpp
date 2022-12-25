#include "Shape.h"

class ShapeManager
{
	size_t nShape;
	size_t capacity;
	Shape** shapes;

public:
	ShapeManager() = default;
	explicit ShapeManager(size_t);
	ShapeManager(const ShapeManager&) = default;

	friend std::ostream& operator <<(std::ostream&, const ShapeManager&);
	friend std::istream& operator >>(std::istream&, ShapeManager&);

	~ShapeManager();

	void manage();
	void insert(Shape*);
	void eliminate(size_t);
	void draw() const;
};