/* programm to determine machine epsilon for various floating point types 
 * (float, double, long double) using templates
 */
#include<iostream>
#include<limits>

template <class T>
void calculate_eps() {
	T one = 1; T two = 2;
	T eps = one;
	while( static_cast<T>(one + eps/two) != one ) eps /= two;
	std::cout << "\tcalculated eps:\t\t" << eps << "\n";
	std::cout << "\tnumeric limits eps:\t" << std::numeric_limits<T>::epsilon() << "\n\n";
}

int main() {
	std::cout << "checking your system's machine epsilon ... \n";
	std::cout << "for float: \n";
	calculate_eps<float>();
	std::cout << "for double: \n";
	calculate_eps<double>();
	std::cout << "epsilon for long double: \n";
	calculate_eps<long double>();

	return 0;
}
