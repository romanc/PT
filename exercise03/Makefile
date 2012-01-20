main: main.o integrator.o
	g++ -O3 -o main main.o integrator.o
main.o: main.cpp integrator.h
	g++ -O3 -unroll-loops -c main.cpp
integrator.o: integrator.cpp integrator.h
	g++ -O3 -unroll-loops -c integrator.cpp

clean: 
	rm -f main *.o
