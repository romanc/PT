#include<cstdlib>
#include<iostream>
#include<sys/time.h>

inline void set(double *A, double *B, const int n);

inline void mult(const double *A, const double *B, double *C, const int n);
inline void mult1(const double *A, const double *B, double *C, const int n);
inline void mult2(const double *A, const double *B, double *C, const int n);
inline void mult3(const double *A, const double *B, double *C, const int n);

inline void strassen2(const double *A, const double *B, double *C);
inline void strassen4(const double *A, const double *B, double *C);

void print( const double *A, unsigned int n);

double operator- (const timeval& t1, const timeval& t2) {
        return t1.tv_sec - t2.tv_sec + (t1.tv_usec - t2.tv_usec) * 1e-6;
}

int main(){

	const int n = 700;
	int n_iterations = 10;
	
	double *A = new double[n * n];	
	double *B = new double[n * n];
	double *C = new double[n * n];
	double *D = new double[n * n];
	
	timeval start,end;

	set(A, B, n);
	
	if( n < 10 ) {
		std::cout << "printing A" << "\n";
		print(A, n);
		std::cout << "printing B" << "\n";
		print(B, n);
	}
	gettimeofday(&start, 0);
	for (int i = 0; i < n_iterations; ++i) {
		mult(A, B, C, n);
	}
	gettimeofday(&end, 0);
	std::cout << "trival implementation used " << double(end - start) / n_iterations << "sec.\n";
	if(n < 10 ) print(C, n);		

	gettimeofday(&start, 0);
	for(int i = 0; i < n_iterations; ++i) {
		mult2(A, B, D, n);
	}
	gettimeofday(&end, 0);
        std::cout << "enhanced implementaion used " << double(end - start) / n_iterations << "sec.\n";
	if( n < 10 ) print(D, n);

	if( n == 4 ) {
		double *Z = new double[16];
	
		gettimeofday(&start, 0);
		for(int i = 0; i < n_iterations; ++i) {
			strassen4(A, B, Z);
		}
		gettimeofday(&end, 0);
        	std::cout << "strassen implementation used " << double(end - start) / n_iterations << "sec.\n";	
		print(Z, 4);
	
        	delete[] Z;
	}
	delete[] D;
	delete[] C;
        delete[] A;
        delete[] B;	
}

// strassen algorithm works, but is slow for small matrices (n=4)
// implemenation is surely not optimal
inline void strassen4(const double *A, const double *B, double *C) {
	double *A11 = new double[2*2];	double *B11 = new double[2*2];
        double *A12 = new double[2*2];	double *B12 = new double[2*2];
        double *A21 = new double[2*2];	double *B21 = new double[2*2];
        double *A22 = new double[2*2];	double *B22 = new double[2*2];
	for(int i = 0; i < 2; ++i) {
		for(int j = 0; j < 2; ++j) {
			A11[i*2+j] = A[i*4+j];
			A12[i*2+j] = A[i*4+j+2];
			B11[i*2+j] = B[i*4+j];
			B12[i*2+j] = B[i*4+j+2];
			
			A21[i*2+j] = A[(i+2)*4+j];
			B21[i*2+j] = B[(i+2)*4+j];
			A22[i*2+j] = A[(i+2)*4+j+2];
			B22[i*2+j] = B[(i+2)*4+j+2];
		}
	}
	
	double *X = new double[4];
	double *Y = new double[4];
	strassen2(A11, B11, X);
	strassen2(A12, B21, Y);
	for(int i=0; i < 2; ++i) 
		for( int j = 0; j < 2; ++j)
			C[i*4+j] = X[i*2+j] + Y[i*2+j];
	
	strassen2(A11, B12, X);
	strassen2(A12, B22, Y);
	for(int i=0; i < 2; ++i) 
                for( int j = 0; j < 2; ++j) 
                        C[i*4+j+2] = X[i*2+j] + Y[i*2+j];

	strassen2(A21, B11, X);
	strassen2(A22, B21, Y);
        for(int i=0; i < 2; ++i) 
                for( int j = 0; j < 2; ++j) 
                        C[(i+2)*4+j] = X[i*2+j] + Y[i*2+j];

	strassen2(A21, B12, X); 
	strassen2(A22, B22, Y);
        for(int i=0; i < 2; ++i) 
                for( int j = 0; j < 2; ++j) 
                        C[(i+2)*4+j+2] = X[i*2+j] + Y[i*2+j];

	delete[] X; 	delete[] Y;
	delete[] A11;	delete[] B11;
        delete[] A12;	delete[] B12;
        delete[] A21;	delete[] B21;
        delete[] A22;	delete[] B22;
}


inline void strassen2(const double *A, const double *B, double *C) {
	double m1 = (A[0] + A[3])*(B[0] + B[3]);
	double m2 = (A[2] + A[3])*B[0];
	double m3 = A[0] * (B[1] - B[3]);
	double m4 = A[3] * (B[2] - B[0]);
	double m5 = (A[0] + A[1]) * B[3];
	double m6 = (A[2] - A[0])*(B[0] + B[1]);
	double m7 = (A[1] - A[3])*(B[2] + B[3]);

	C[0] = m1 + m4 - m5 + m7;
	C[1] = m3 + m5;
	C[2] = m2 + m4;
	C[3] = m1 - m2 + m3 + m6;
}

inline void set(double *A, double *B, const int n)
{
	for(unsigned int i = 0; i < n; ++i) 
		for(unsigned int j = 0; j < n; ++j) {
			A[i*n+j] = static_cast<int>(5*drand48()+3);
			B[i*n+j] = static_cast<int>(4*drand48()-2);
		}
}

inline void mult(const double *A, const double *B, double *C, const int n) {
	unsigned int i,j,k;
	for(i=0; i<n; ++i) 
		for(j=0; j<n; ++j) {
			C[i*n + j] = 0; // reset 
			for(k=0; k<n; ++k)
				C[i*n + j] += A[i*n +k] * B[k*n + j];
		}
}

// about factor 3 faster than mult for large matrices (n=700)
inline void mult1(const double *A, const double *B, double *C, const int n)
{
	unsigned int i,j,k;
	for(i=0; i < n*n; ++i) C[i] = 0;
	for(i=0; i <n; ++i) 
		for(k=0; k<n; ++k) {
			double tmp = A[i*n + k];
			for(j=0; j<n; ++j) 
				C[i*n + j] += tmp * B[k*n + j];
		}
}

// as fast as mult1 for big matrices (n=700)
// faster for very small matrices (n=4)
inline void mult2(const double *A, const double *B, double *C, const int n) {
        unsigned int i,j,k,in, kn;
        double tmp;
	for(i=0; i<n*n; ++i) C[i] = 0;
        for(i=0;i<n; ++i) {
                in = i*n;
                for(k=0;k<n;++k) {
                        tmp=A[in + k];
                        kn = k*n;
                        for(j=0; j<n; ++j) {
                                C[in+j] += tmp * B[kn+j];
                         }
                }
        }
}

// slightly slower than mult2 for big matrices (n=700)
// slightly faster for very small matrices (n=4)
inline void mult3(const double *A, const double *B, double *C, const int n) {
	unsigned int i,j,k,l, in, kn;
	double tmp;
	for(i=0; i<n*n; ++i) C[i] = 0;
	for(i=0;i<n; ++i) {
		in = i*n;
		for(k=0;k<n;++k) {
			tmp=A[in + k];
			kn = k*n;
			for(j=in, l=kn; j<in+n; ++j, ++l) {
				C[j] += tmp * B[l];
			 }
		}
	}
}

void print(const double *A, unsigned int n) {
//	std::cout << "{ ";
	for(unsigned int i = 0; i<n; ++i) {
//		std::cout << "{ ";
		for(unsigned int j = 0; j<n; ++j) {
			std::cout << A[i*n +j] << "\t";
		}
//		std::cout << "}, ";
		std::cout << "\n";
	}
//	std::cout << "} \n";
}



