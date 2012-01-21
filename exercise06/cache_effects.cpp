/* optimized for L-cache of 512kB */

#include<iostream>
#include<vector>
#include<sys/time.h>

double operator- (const timeval& t1, const timeval& t2) {
	return t1.tv_sec - t2.tv_sec + (t1.tv_usec - t2.tv_usec) * 1e-6;
}

int main() {
	unsigned int jump_sz = 32;
	unsigned int REPEAT = 10000;
	timeval start, end;
	
	std::cout << "#size of array\t time needed for " << REPEAT << " loops" << std::endl;
	for(unsigned int N = 10000; N <= 50000; N+=1000) {
		double time = 1000000;
		std::vector<long double> numbers(N, 0.);
		for(int j=0; j < REPEAT; ++j) {
			gettimeofday(&start, 0);
			for(int i = 0; i < N; i+=jump_sz) {
				numbers[i] = numbers[i] * 0.1 + 3.5 ;
			}
			gettimeofday(&end, 0);
			time = std::min(end - start, time);
		}
		std::cout << N*sizeof(long double) / 1024.0 << "\t" << time << "\n";
	}
	return 0;
}
