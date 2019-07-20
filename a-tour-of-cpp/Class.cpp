#include <iostream>

class complex {
	double re, im; // two doubles
public:
	complex(double r, double i) : re{ r }, im{ i } {}
	// construct from two scalars
	complex(double r) : re{ r }, im{ 0 } {}
	complex() : re{ 0 }, im{ 0 } {}

	double real() const { return re; }
	// functions def'd in a class are automatically inlined
	// this makes it so they don't generate function calls in machine code
	// this can be explicitly done with the 'inline' keyword

	void real(double d) { re = d; }
	double imag() const { return im; }
	void imag(double d) { im = d; }

	complex& operator+=(complex z) { re += z.re, im += z.im; return *this; }
	// add to re and im and return results
	complex& operator-=(complex z) { re -= z.re, im -= z.im; return *this; }
	complex& operator*=(complex z);
	complex& operator/=(complex z); // defined elsewhere
	
};

// some operators don't need to be (or can't be) def'd in a class
complex operator+(complex a, complex b) { return a += b; }
complex operator-(complex a, complex b) { return a -= b; }
complex operator-(complex a) { return { -a.real(), -a.imag() }; }
// unary minus ^
complex operator*(complex a, complex b) { return a *= b; }
complex operator/(complex a, complex b) { return a /= b; }

bool operator==(complex a, complex b) {
	// equality
	return a.real() == b.real() && a.imag() == b.imag();
}

bool operator!=(complex a, complex b) {
	// not equal
	return !(a == b);
}

complex sqrt(complex); // defined elsewhere