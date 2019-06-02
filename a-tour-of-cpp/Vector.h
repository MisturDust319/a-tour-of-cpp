// Vector.h
// this is a header file, which contains declarations for the Vector class

class Vector {
public:
	Vector(int s);
	double& operator[](int i);
	int size();

private:
	double* elem; // elem points to an array of sz doubles
	int sz;
};