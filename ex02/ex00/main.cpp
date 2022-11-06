//
// Created by Kevin Di nocera on 10/27/22.
//

#include "fixed.hpp"

const int Fixed::_n = 8;

int main( void ) {
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;
	a.setRawBits(0);
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}
