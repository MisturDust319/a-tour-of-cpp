// Namespaces can help group together certain code,
//	and make sure common names clash

#include <iostream>

namespace My_Code {
	class complex {
		complex(int x1, int x2)
			: x1{ x1 }, x2{ x2 }
		{}

		float real() {
			return (float)x1;
		}

		int x1, x2;
	};

	complex sqrt(complex complex) {
		return ;
	}
	// insert more here

	int main();
}

int My_Code::main() {
	complex z{ 1, 2 };
	auto z2 = sqrt(z);

	std::cout << '{' << z2.real();
	// and so on
}