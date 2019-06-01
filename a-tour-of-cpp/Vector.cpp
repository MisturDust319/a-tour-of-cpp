#include <iostream>

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