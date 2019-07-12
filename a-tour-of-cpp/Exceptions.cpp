#include <iostream>
#include "Vector.h"

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
}

void f(Vector& v) {
	// try is a block of code that will redirect errors to a handler
	try {
		v[v.size()] = 7;
		// try to access beyond end of v
	}
	// catch defines an error handler
	catch (std::out_of_range) {
		std::cerr << "Out of range";
	}
}

// a function that will never throw an exception can be declared noexcept
void user(int sz) noexcept {
	Vector v(sz);
	// ...
}