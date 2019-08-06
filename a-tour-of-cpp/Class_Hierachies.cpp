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

Shape* read_shape(std::istream& is) {
	// read shape descriptions from istream

	// here you would read is somehow into k

	switch (Kind k) {
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

// you can use dynamic casting to have access to child classes values
//	while still using the parent child's pointer
void demonstrate_dynamic_caste() {
	Shape* ps{ read_shape(cin) };

	if (Smiley* p = dynamic_cast<Smiley*>(ps)) {
		// create a pointer p that is of type smiley
		// that can access the data in ps

		// do something
	}
	else {
		// if ps doesn't point to a Smiley object
		// or derived from Smiley
		// the dynamic cast will return a nullptr
		
		// do this
	}
}