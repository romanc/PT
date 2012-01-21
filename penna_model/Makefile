test: test.o genome.o animal.o
	g++ -O3 -unroll-loops -o test test.o genome.o animal.o
test.o: test.cpp genome.hpp animal.hpp
	g++ -O3 -unroll-loops -c test.cpp
animal.o: animal.cpp animal.hpp
	g++ -O3 -unroll-loops -c animal.cpp
genome.o: genome.cpp genome.hpp
	g++ -O3 -unroll-loops -c genome.cpp

clean:
	rm -f test *.o
