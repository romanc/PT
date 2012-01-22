#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <exception>
#include <stdexcept>
#include <sys/time.h>

using namespace std;

template<class Iterator>
class Sorter
{
public:
	virtual double sort(Iterator begin, Iterator end) const = 0;
};

template<class Iterator>
class BubbleSort : public Sorter<Iterator>
{
public:
	double sort(Iterator begin, Iterator end) const{
		// http://en.wikipedia.org/wiki/Bubble_sort
		timeval t_start, t_end;
		gettimeofday(&t_start, 0);
		bool swapped;
		do{
			swapped = false;
			for(Iterator i = begin ; i != (end-1); ++i ) {
				if( *i > *(i+1) ) {
					swap(*i, *(i+1));
					swapped = true;
				}
			}
		} while(swapped);
		gettimeofday(&t_end, 0);

		return t_end.tv_sec - t_start.tv_sec + (t_end.tv_usec - t_start.tv_usec) * 1e-6;
	}
};

template<class Iterator>
class StdSort : public Sorter<Iterator>
{
public:
	double sort(Iterator begin, Iterator end) const
	{
		timeval t_start, t_end;
		gettimeofday(&t_start, 0);
		std::sort(begin, end);
		gettimeofday(&t_end, 0);
		return t_end.tv_sec - t_start.tv_sec + (t_end.tv_usec - t_start.tv_usec) * 1e-6;
	}
};

template<class Iterator>
class InsertionSort : public Sorter<Iterator>
{
	typedef typename Iterator::value_type value_t;
	typedef list<value_t> storage_t;
public:
	double sort(Iterator begin, Iterator end) const {
	        // http://en.wikipedia.org/wiki/Insertionsort
		timeval t_start, t_end;
		gettimeofday(&t_start, 0);
		for( Iterator i = begin; i != (end-1); ++i ) {
			value_t value = *(i+1);
			Iterator j = i;
			while( j >= begin && *(j) > value ) {
				*(j+1) = *(j);
				j = j-1;
			}
			*(j+1) = value;
		}
		gettimeofday(&t_end, 0);
		return t_end.tv_sec - t_start.tv_sec + (t_end.tv_usec - t_start.tv_usec) * 1e-6;
	}
};

template<class Iterator>
Sorter<Iterator> * sortingFactory(string algorithm)
{
	Sorter<Iterator> * tmp;
	if( algorithm == "InsertionSort" ) {
		tmp = new InsertionSort<Iterator>;
	} else if( algorithm == "BubbleSort" ) {
		tmp = new BubbleSort<Iterator>;
	} else if( algorithm == "StdSort" ) {
		tmp = new StdSort<Iterator>;
	} else {
		throw std::range_error("Choose an algorithm out of 'BubbleSort', 'InsertionSort', 'StdSort'");
	}
	return tmp;
}

typedef double T;
typedef vector<T>::iterator iterator_t;

int main(int argc, char ** argv)
{
	if (argc != 2) {
		cerr << argv[0] << " <sorting algorithm>" << endl;
		exit(1);
	}
	
	Sorter<iterator_t> *mysort = sortingFactory<iterator_t>(string(argv[1]));
	
    cout << "Please insert your sequence of numbers (stop the sequence with Ctrl+D):" << endl;
	vector<T> foo;
	copy(istream_iterator<T>(cin),
		 istream_iterator<T>(),
		 back_inserter(foo));
	
	double time = mysort->sort(foo.begin(), foo.end());
	cout << "time used to sort: " << time << "sec" << endl;
	
    cout << endl << "The sorted sequence is:" << endl;
	copy(foo.begin(), foo.end(), ostream_iterator<T>(cout, "\n"));
	cout << endl;
	
	delete mysort;
}

