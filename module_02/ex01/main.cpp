//
// Created by Kevin Di nocera on 10/27/22.
//

#include "fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}

//	float i = 1.6; // = 350.6   350 / 256 1   .55   2 ** 8;
//	std::cout << i << std::endl;
//	i = 1 << 8; //00000000100
//	std::cout << i << std::endl;
//	i = (float)(1 >> 8);
//	std::cout << i << std::endl;