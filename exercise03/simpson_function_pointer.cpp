/* programm, that does integration by simpson-rule
 */
#include<iostream>
#include<cmath>
#include<cassert>
#define PI 3.141592

/* uses simpsons rule to integrate given function pointer of the interval [a,b] with N timesteps
 * (*fp) function pointer of function to integrate
 * [a,b] integration interval
 * N nubmers of steps
 * PRE: N>=0, b >= a
 * POST: returns approximation of \int_a^b (*fp)(x) dx
 */
double simpson_function_pointer(double (*fp)(double), double a, double b, int N) {
	assert(N >= 0);
	assert(b >= a);
	double integral = 0;
	double dx = (b-a)/N;
	for(int i = 0; i < N; ++i) integral += (*fp)(a + i*dx);
	return integral * dx;
}

double f(double x) { return sin(x); }

int main() {
	double a=0;
	double b=PI;
	int N = 1000;
	
	/* call integration function */
	double I = simpson_function_pointer(&f, a, b, N);
	std::cout << "The integral of sin(x) from a=" << a << " to b=" << b << " is given as:\n\\int_a^b sin(x) dx = " << I << std::endl;
	return 0;
}
