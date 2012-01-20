#include<iostream>
#include<vector>
#include<numeric>

int main() {
	std::cout << "please enter enter some numbers.\nthe numbers will be normalized to 1 and printed in reverse order.\n";
	std::cout << "how many numbers will you enter? ";
	int N;
	std::cin >> N;
	
	std::vector<double> numbers;
	numbers.assign(N, 0);
	for(int i = 0; i < N; ++i) std::cin >> numbers[i];
	std::cout << "the numbers you tiped are:";
	for(int i = 0; i <N; ++i) std::cout << " " << numbers[i];
	std::cout << std::endl;

	double sum = accumulate(numbers.begin(), numbers.end(), 0.);
	std::cout << "the normalized numbers in reverse order are:";
	for(int i = N-1; i >= 0; --i) std::cout << " " << numbers[i] / sum;
	std::cout << std::endl;

	return 0;
}
