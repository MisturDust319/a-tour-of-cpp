#include <iostream>

using namespace std;

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