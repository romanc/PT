#include <iostream>

enum Z2 { Plus, Minus };

template<class T>
T identity_element(T dummy) { return T(1); }

// writeme (overload the previous function for Z2)
template <>
Z2 identity_element<Z2>(Z2 dummy) {return Plus;}

Z2 operator*(Z2 a, Z2 b)
{
	if(a==b) /* either Plus*Plus or Minus*Minus */
		return Plus;
	else /* one is Minus the other Plus */
		return Minus;
}

std::ostream& operator<<(std::ostream& os, Z2 a)
{
	if(a==Plus)
		return std::cout << "Plus";
	else
		return std::cout << "Minus";
}

template<class T>
T operator*(T a, Z2 b)
{
	if(b == Minus) a *= -1;
	return a;
}

template<class T>
T operator*(Z2 b, T a)
{
	if(b == Minus) a *= -1;
	return a;
}

template<class T>
T mypow(T a, unsigned int n)
{
	T pow = identity_element(a);
	for(int i=0; i < n; ++i) {
		pow = pow * a;
	}
	return pow;

}

int main()
{
	std::cout << "testing implementation and operator*..\n";
	std::cout << "Plus: " << Plus << std::endl;
	std::cout << "Minus: "  << Minus << std::endl;
	std::cout << "Plus*Plus: " << Plus*Plus << std::endl;
	std::cout << "Minus*Minus: " << Minus*Minus << std::endl;
	// some testing - add your own!
	std::cout << "Plus*Minus: " << Plus*Minus << std::endl;
	std::cout << "Identity Element of Z2: " << identity_element(Plus) << std::endl;
	
	std::cout << "\ntesting action of group element on numbers ... \n";
	std::cout << "5*Plus=" << 5*Plus << std::endl;
	std::cout << "Plus*5=" << Plus*5 << std::endl;
	std::cout << "42*Minus=" << 42*Minus << std::endl;
	std::cout << "Minus*42=" << Minus*42 << std::endl;
	std::cout << "Plus*-1*Minus=" << Plus*-1*Minus << std::endl;
	
	std::cout << "\ntesting power-method ... \n";
	std::cout << "3^3=" << mypow(3,3) << std::endl;
	std::cout << "Plus^5=" << mypow(Plus, 5) << std::endl;
	std::cout << "(1+3)*Minus^4=" << (1.+3.)*mypow(Minus,4) << std::endl;
}
