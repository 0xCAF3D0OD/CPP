//
// Created by Kevin Di nocera on 10/27/22.
//

#ifndef EX02_FIXED_HPP
#define EX02_FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
private:
	int _f;
	static int const _n;
public:
	Fixed();
	Fixed(Fixed const& src);

	Fixed& operator=(Fixed const& rhs);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	~Fixed();
};
#endif //EX02_FIXED_HPP
