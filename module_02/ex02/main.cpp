//
// Created by Kevin Di nocera on 10/28/22.
//

#include "fixed.hpp"

int main( void ) {
	Fixed	a;
	Fixed	const b(Fixed(5.05f) * Fixed(2));
	Fixed	d;

	d = a + b;
	std::cout << a << " + " << b << " = " << d << std::endl;
	d = a - b;
	std::cout << a << " - " << b << " = " << d << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	return 0;
}