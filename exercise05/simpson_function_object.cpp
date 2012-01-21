#include<iostream>
#include<cassert>
#include<cmath>

#define PI 3.141592

/* uses simpsons rule to integrate given function object of the interval [a,b] with N timesteps
 * REMARK: This function is NOT failsafe:
 * 1) your boundaries have to be of the same type
 * 2) the return value will be the same, as your boundary values
 *  => if you have integer boundaries, your return value will be integer
 */
/* function parameters and PRE / POST condition
 * f function object
 * [a,b] integration interval
 * N nubmers of steps
 * PRE: b >= a
 * POST: returns approximation of \int_a^b f(x) dx 
 */
/* concepts for type T:
 - subtractable
 - summable
 - multiplicable with T and int
 - devideable by int
 - constructable from 0
 - copy-constructable (for passing arg by value)
 - assignable and += assignable
 - convertable to double (for function call)
 - convertable from double (return value of function call is double)
 - less-then-comparable (for assert)
*/
template<class F, class T>
double simpson(F f, T a, T b, unsigned int N) {
        assert(b >= a);
        T integral = T(0);
        T dx = static_cast<T>((b-a)/N);
        for(int i = 0; i < N; ++i) integral += f(a + i*dx);
        return integral * dx;
}

/* function object for sin(lambda * x)
 */
class LambdaSin
{
	public:
	double lambda;
	// constructor
	LambdaSin(double x) : lambda(x) {} 
	// operator()
	double operator()(double x) {
		return sin(lambda*x);
	}
};

int main() {
	double lambda = 3;
	/* nice for testing ...
	std::cout << "what should lambda be?\n";
	std::cin >> lambda; */
	double a = 0;
	double b = PI / lambda;
	int N = 1000;
	
	LambdaSin lambdaSin(lambda);
	
	double integral = 0;
	integral = simpson(lambdaSin, a, b, N);
	std::cout << "The integral from 0 to Pi/" << lambda << " of sin(" << lambda << "*x) is: " << integral << std::endl;
	
	return 0;
}
