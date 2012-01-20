/* programm to determine endianness of a system
 */
#include<iostream>

int main() {
	std::cout << "checking you system's endianness ... \n";
	int i = 1;
	char *p;
	p = reinterpret_cast<char*>(&i);

	if( *p == 1 ) std::cout << "little endian\n";
	else if( *(p + sizeof(int) - 1) == 1 ) std::cout << "big endian\n";
	else std::cout << "something bad happend\n";

	return 0;
}
