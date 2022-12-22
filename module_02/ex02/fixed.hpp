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

	Fixed	&operator=(const Fixed &rhs);

	bool	operator==(const Fixed &rhs) const;
	bool	operator>=(const Fixed &rhs) const;
	bool	operator<=(const Fixed &rhs) const;
	bool	operator!=(const Fixed &rhs) const;
	bool	operator<(const Fixed &rhs) const;
	bool	operator>(const Fixed &rhs) const;

	Fixed	operator+(const Fixed &rhs) const;
	Fixed	operator-(const Fixed &rhs) const;
	Fixed	operator*(const Fixed &rhs) const;
	Fixed	operator/(const Fixed &rhs) const;

	Fixed	&operator++();
	Fixed	operator++(int);
	Fixed	&operator--();
	Fixed	operator--(int);

	int		getRawBits(void) const;
	void	setRawBits(const int raw);

	static Fixed	min(Fixed &fMin1, Fixed &fMin2);
	static Fixed	max(Fixed &fMax1, Fixed &fMax2);
	static Fixed	min(const Fixed &fMin1, const Fixed &fMin2);
	static Fixed	max(const Fixed &fMax1, const Fixed &fMax2);

	~Fixed();
};

std::ostream	&operator<<(std::ostream &sortie, Fixed const &rhs);

#endif //EX02_FIXED_HPP
