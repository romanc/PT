/* programm, that reads in up to 10 numbers
 * normalizes them
 * and prints them in reverse input order
 */
#include<iostream>

int main() {
	std::cout << "please enter up to 10 number (close input with Ctrl-d). they will be normalized, such that they sum up to 1 and printed in reverse order\n";

	double array [10] = {0,0,0,0,0,0,0,0,0,0};
	double sum = 0;
	for(int i = 0; i < 10; ++i) {
		std::cin >> array[i];
		sum += array[i];
	}
	for(int i = 9; i >= 0; --i) {
		if( array[i] != 0 ) {
			std::cout << i+1 << "-th normalized element: " << array[i]/sum << "\n";
		}
	}
	std::cout << std::endl;
	return 0;
}
