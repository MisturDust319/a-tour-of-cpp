#include <iostream>
#include <vector>

class Point {
public:
	int x, y;

	Point() : x{ 0 }, y{ 0 } {}
	Point(int xx, int yy) : x{ xx }, y{ yy } {}
};

class Shape {
	// base classes like this can be used as interfaces
	// they also reduce the clutter in super classes
	// unlike concrete classes, these abstract classes
	//	are typically allocated on free storage w/ new
	//	and accessed through references
public:
	virtual Point center() const = 0;
	virtual void move(Point to) = 0;

	virtual void draw() const = 0;
	virtual void rotate(int angle) = 0;

	virtual ~Shape() {};
};

// No data will be shared between classes that inherit
// from this abstract class, minus the vtbl

// this will work with any class derived from Shape:
void rotate_all(std::vector<Shape*>& v, int angle) {
	for (auto p : v)
		p->rotate(angle);
}

// create a class that inherits from Shape
class Circle : public Shape {
public:
	Circle(Point p, int rr); // constructor

	Point center() const { return x; }
	void move(Point to) { x = to; }
	void draw() const;
	void rotate(int) {}
	// pretty simple to rotate a circle
private:
	Point x; // center
	int r; // radius
};

class Smiley : public Circle {
	// use circle as base for a face
public:
	Smiley(Point p, int r) : Circle{ p, r }, mouth{ nullptr } {}
	
	~Smiley() {
		delete mouth;
		for (auto p : eyes)
			delete p; // note how the contents of the eyes vector
			// are individually deleted
	}

	void move(Point to) override;
	// override is more of a reminder, saying "this function
	//	is meant to override a virtual function"
	// when classes become sufficiently complicated
	//	and names are vague like "move", this can clarify
	//	this was meant to override a virtual function

	void draw() const;
	void rotate(int);

	void add_eye(Shape* s) { eyes.push_back(s); }
	void set_mouth(Shape* s);
	virtual void wink(int i); // wink eye number i

	// ...

private:
	std::vector<Shape*> eyes; // usually two
	Shape* mouth;
};

void Smiley::draw() const {
	Circle::draw();
	for (auto p : eyes)
		p->draw();
	mouth->draw();
}

enum class Kind { circle, triangle, smiley };

/*
Shape* read_shape(std::istream& is) {
	// read shape descriptions from istream

	// here you would read is somehow into k
	Kind k;
	switch (k) {
		// read circle data into p and r
	case Kind::circle:
		return new Circle{ p, r };
	case Kind::triangle:
		// read triangle data
		return new Triangle{ p1, p2, p3 };
	case Kind::smiley:
		Smiley* ps = new Smiley{ p,r };
		ps->add_eye(e1);
		ps->add_eye(e2);
		ps->set_mouth(m);
		return ps;
	}
}
*/
// note that allocating data from free store is dangerous
// you can choose to allocate pointers to a unique_ptr from the std lib
// unique_ptr will handle garbage collection
std::unique_ptr<Shape> read_shape(std::istream& is) {
	int p = 3, r = 3;

	Kind k = Kind::circle;

	switch (k) {
	case Kind::circle:
		// read circle data into p and r
		return std::unique_ptr<Shape>{ new Circle{ p, r } };
		/*
		case Kind::triangle:
			// read triangle data
			return std::unique_ptr<Shape>{new Triangle{ p1, p2, p3 }};
		case Kind::smiley:
			Smiley* ps = new Smiley{ p,r };
			ps->add_eye(e1);
			ps->add_eye(e2);
			ps->set_mouth(m);
			return std::unique_ptr<Shape>{ ps };
		}
		*/
	}
}

void user() {
	std::vector<std::unique_ptr<Shape>> v;
	while (cin)
		v.push_back(read_shape(cin));
	/*
	draw_all(v); // do various things w/ the pointers
	*/
}
// you can use dynamic casting to have access to child classes values
//	while still using the parent child's pointer
void demonstrate_dynamic_cast() {
	Shape* ps{ read_shape(std::cin) };

	if (Smiley* p = dynamic_cast<Smiley*>(ps)) {
		// create a pointer p that is of type smiley 
		// that can access the data in ps

		// do something
	}
	else {
		// if ps doesn't point to a Smiley object
		// or one derived from Smiley
		// the dynamic cast will return a nullptr
		
		// do this
	}
}
// a dynamic cast can be used to check for a proper type
// you dynamic cast to a reference type, and if it's not the expected
//	type, you throw a bad_cast
Shape* ps{ read_shape(std::cin) };
Smiley& r{ dynamic_cast<Smiley&>(*ps) }; // somewhere, catch std::bad_cast
// dynamic casts should be used sparingly to keep code clean
// however, if you're using the base class interface to pass data,
//	casts can be used to clarify what the intended returned data type should
//	be
// these operations are known as "is kind/instance of" operations

