#include "Vector.h" // include the vector header
// quotes indicate it should look in the local directory
#include <iostream>
// brackets indicate it should look in the project path

// This is contains the implementation of the Vector class declared in Vector.h
// By seperating declaration from implementation, you can decrease compile time and errors
//	and helps keep code organised

/*
// a class is a basically handle that holds a pointer to the attributes and methods
class Vector {
	// this is a concrete class. It behaves just like a built in data type
public:
	// constructor w/ shorthand initialization
	//	this is called a member initialization list
	Vector(int s) :elem(new double[s]), sz(s) {}
	// overwrite the element access operator
	//	so it uses the standard array interface for access
	double& operator[](int i) { return elem[i]; }
	int size() { return sz; }
private:
	double* elem; // pointer to elements
	int sz;	// size of the vector
};
*/

// you have to declare the scope of the class when implementing
//	a class's methods
Vector::Vector(int s)
{
	if (s < 0)
		throw std::length_error{"Vector size must be a positive int"};
	elem = new double[s];
}

// the return type is put before the scope resolution
double& Vector::operator[] (int i) {
	if (i < 0 || size() <= i)
		throw std::out_of_range{ "Vector::operator[]" };
	// throw will return an error
	// it passes control to a handler
	// this handler unwinds the call stack to get the context
	// of the caller
	// this will exit scopes and functions as needed to get
	// a caller that will handle the exception
	else
		return elem[i];
	// in the current implementation assumes that elem points
	//	to an array of size sz filled w/ doubles
	// the class invariant states what is assumed to be true
	//	the class constructor should establish the class's invariant
}

int Vector::size() {
	return sz;
}

double read_and_sum(int s) {
	// read s ints from cin and return their sum
	Vector v(s); // init a Vector of size s
	for (int i = 0; i != v.size(); ++i)
		std::cin >> v[i];

	double sum = 0;
	for (int i = 0; i != s; ++i)
		sum += v[i];

	return sum;
}

/* VECTOR AS A STRUCTURE
// Vector struct that will be built up to demonstrate C++
struct Vector
{
	int sz;	// num of elements
	double* elem; // pointer to elements
};

void vector_init(Vector& v, int s) {
	v.elem = new double[s]; // allocate array of s doubles from heap
	v.sz = s;
}

double read_and_sum(int s) {
	// read s ints from cin and return their sum
	Vector v;
	vector_init(v, s); // allocate s elements in v
	for (int i = 0; i != s; ++i)
		cin >> v.elem[i];

	double sum = 0;
	for (int i = 0; i != s; ++i)
		sum += v.elem[i];

	return sum;
}
*/