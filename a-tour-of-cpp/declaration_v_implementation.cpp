// cpp can separate declaration from implementation
//	declaration defines all that's needed for a function
//	implementation defines the code body of a function

double sqrt(double);
// note you don't have to define the data type

class Vector {
public:
	Vector(int s);
	double& operator[](int i);
	int size();
private:
	double* elem; // elem points to array of sz doubles
	int sz;
};

// implementation includes a definition of the variable name
double sqrt(double d) {
	return d * d;
}

// you have to declare the scope of the class when implementing
//	a class's methods
Vector::Vector(int s)
	:elem{ new double[s] }, sz{ s }
{
}

// the return type is put before the scope resolution
double& Vector::operator[](int i) {
	return elem[i];
}

int Vector::size() {
	return sz;
}