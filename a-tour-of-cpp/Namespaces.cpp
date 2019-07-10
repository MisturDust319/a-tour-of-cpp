// Namespaces can help group together certain code,
//	and make sure common names clash

#include <iostream>

namespace My_Code {
	class complex {
	public:
		complex(int x1, int x2)
			: x1{ x1 }, x2{ x2 }
		{}

		int real() {
			return x1;
		}
	private:
		int x1, x2;
	};

	complex sqrt(complex complex) {
		return complex;
	}
	// insert more here

	int main();

	int My_Code::main() {
		complex z{ 1, 2 };
		auto z2 = sqrt(z);

		std::cout << '{' << z2.real();
		// and so on
	}
}

// make the default namespace by qualifying it with 
//	'using namespace'
using namespace My_Code;