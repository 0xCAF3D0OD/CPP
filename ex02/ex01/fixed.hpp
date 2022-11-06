//
// Created by Kevin Di nocera on 10/27/22.
//

#ifndef EX02_FIXED_HPP
#define EX02_FIXED_HPP

#include <iostream>
#include <ostream>
#include <string>
#include <cmath>

class Fixed
{
private:
	int _rawBits;
	static int const _fractBits = 8;

public:
	Fixed();
	Fixed(const int n);
	Fixed(const float f);
	Fixed(const Fixed &src);

	float	toFloat(void) const;
	int		toInt(void) const;

	Fixed &operator=(const Fixed &rhs);

	int		getRawBits(void) const;
	void	setRawBits(const int raw);

	~Fixed();
};

std::ostream	&operator<<(std::ostream &sortie, Fixed const &rhs);

#endif //EX02_FIXED_HPP
