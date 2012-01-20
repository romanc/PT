#include<iostream>
#include<cmath>
#define PI 3.141592


int main() {
	double a=0;
	double b=PI;
	int N = 1000;
	double integral = 0;

	double dx = (b-a)/N;
	for(int i = 0; i < N; ++i) {
		integral += std::sin(a + i*dx);
	}
	integral *= dx;
	std::cout << "integrating sin(x) from a=" << a << " to b=" << b << " using N=" << N << " steps = " << integral << "\n";

	return 0;
}
