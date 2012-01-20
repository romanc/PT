/* integration functions to be used for numeric quadrature
 */

/* uses simpsons rule to integrate given function pointer of the interval [a,b] with N timesteps
 * (*fp) function pointer of function to integrate
 * [a,b] integration interval
 * N nubmers of steps
 * PRE: N>=0, b >= a
 * POST: returns approximation of \int_a^b (*fp)(x) dx
 */
double simpson(double (*fp)(double), double a, double b, int N);
