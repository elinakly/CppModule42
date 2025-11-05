#include "Fixed.hpp"

int main( void )
{
	Fixed a(0);
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	// std::cout << "a + b = " << a + b << std::endl;
	// std::cout << "a - b = " << a - b << std::endl;
	// std::cout << "a * b = " << a * b << std::endl;
	// std::cout << "a / b = " << a / b << std::endl;
	std::cout << "a  = " << a << std::endl;
	std::cout << "++a  = " << ++a << std::endl;
	std::cout << "a  = " << a << std::endl;
	std::cout << "a++  = " << a++ << std::endl;
	std::cout << "a  = " << a << std::endl;
	std::cout << "b  = " << b << std::endl;
	std::cout << "max (a, b)  = " << Fixed::max( a, b ) << std::endl;

	Fixed c(2147483646);
	Fixed d(2147483647);
	std::cout << "c < d  = " << ((c < d) ? "true" : "false") << std::endl;
	return 0;
}