#include <iostream>
#include "Vector.h"

// abstract types are used as a template for other classes
// there should be no actual local variables in an abstract type
// and we have to allocate objects on free store and access through
// pointers and references

class Container {
public:
	// note the lack of a constructor
	virtual double& operator[](int) = 0;
	// a pure virtual function
	// virtual means it may be derived in a child class
	// the =0 marks this as a pure virtual function
	//	so it HAS to be redefined in a child class
	// AND you can't instantiate an object of this class
	// the presence of one pure virtual function marks
	//	an abstract class

	virtual int size() const = 0;
	// const member function 

	// the destructor is virtual
	// this helps clarify what implementation of the child destructor
	// should be called
	virtual ~Container() {}
};

class Vector_container : public Container {
	// Vector_Container inherits from the abstract Container type
	// Vector_Container is the superclass, while Container is the subclass
	Vector v;
public:
	Vector_container(int s) : v(s) {} // vector of s elems
	~Vector_container() {}
	// this will also implicitly invoke ~Vector() destructor

	double& operator[](int i) { return v[i]; }
	int size() const { return v.size(); }
};

// you can use an abstract class to operate on child class objects:
void use(Container& c) {
	const int sz = c.size();

	for (int i = 0; i != sz; ++i) {
		std::cout << c[i] << std::endl;
	}
}