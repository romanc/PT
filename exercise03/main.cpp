/* programm, that includes integrator-header-file
 * uses simpson integrator to integrate sin(x)
 */
#include<iostream>
#include<cmath>
#include "integrator.h"

double f(double x) { return sin(x); }

#define PI 3.141592
int main() {
	double a=0;
	double b=PI;
	int N = 1000;
	
	double I = simpson(&f, a, b, N);
	std::cout << "The integral I of sin(x) from 0 to pi is: I=" << I << std::endl;

	return 0;
}
