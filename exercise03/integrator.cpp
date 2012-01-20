/* integration functions to be included for numeric integration
 */
#include<cassert>
#include "integrator.h"

/* uses simpsons rule to integrate given function pointer of the interval [a,b] with N timesteps
 * (*fp) function pointer of function to integrate
 * [a,b] integration interval
 * N nubmers of steps
 * PRE: N>=0, b >= a
 * POST: returns approximation of \int_a^b (*fp)(x) dx
 */
double simpson(double (*fp)(double), double a, double b, int N) {
        assert(N >= 0);
        assert(b >= a);
        double integral = 0;
        double dx = (b-a)/N;
        for(int i = 0; i < N; ++i) integral += (*fp)(a + i*dx);
        return integral * dx;
}
