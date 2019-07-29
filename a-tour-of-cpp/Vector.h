// Vector.h
// this is a header file, which contains declarations for the Vector class
#pragma once

class Vector {
public:
	// simple constructor
	Vector();
	Vector(int s);
	double& operator[](int i);
	// init w/ initializer list
	// that is, a list of this form: {v1, v2, ... , vn}, which the compiler
	// generates
	Vector(std::initializer_list<double>); // init w/ list of doubles
	// destructor begins w/ tilde
	~Vector();

	// const means size wont change any values
	int size() const;
	// push operation
	void push_back(double); // add element to end
	Vector read(std::istream& is);

	// operator overload
	double& operator[](int i);
	
private:
	double* elem; // elem points to an array of sz doubles
	int sz;
};