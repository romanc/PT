/* programm to determine machine epsilon for various floating point types 
 * (float, double, long double
 */
#include<iostream>
#include<limits>

int main() {
	std::cout << "checking your systems machine epsilon ... \n";
	std::cout << "for float:" << std::endl ;
	float i = 1;
	while( 1 + i != 1 ) {
		i = i/2;
	}
	std::cout << "calculated eps:\t\t" << 2*i << std::endl;
	std::cout << "numeric limits eps:\t" << std::numeric_limits<float>::epsilon() << std::endl << std::endl;
	
	std::cout << "for double:\n";
	double j=1;
	while(1+j != 1) j /= 2;
	std::cout << "calculated eps:\t\t" << 2*j << "\n";
	std::cout << "numeric limits eps:\t" << std::numeric_limits<double>::epsilon() << "\n\n";

	std::cout << "for long double:\n";
	long double k = 1;
	while(1 + k != 1) k /= 2;
	std::cout << "calculated eps:\t\t" << 2*k << "\n";
	std::cout << "numeric limits eps:\t" << std::numeric_limits<long double>::epsilon() << "\n\n";



	return 0;
}
