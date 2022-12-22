//
// Created by Kevin Di nocera on 10/27/22.
//

#include "fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = value << Fixed::_fractBits;
 }

//	"Roundf" return the integral value that is nearest to "(value * (1 << Fixed::_fractbits))"
//	with halfway cases rounded away from zero. => avec des cas intermédiaires arrondis à partir de zéro.
//	the return : The value of x rounded to the nearest integral (as a floating-point value).
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(value * (1 << Fixed::_fractBits));
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}
int	Fixed::getRawBits() const
{
	std::cout << "get function called" << std::endl;
	return (this->_rawBits);
}

void Fixed::setRawBits(const int rawBits)
{
	std::cout << "set function called" << std::endl;
	this->_rawBits = rawBits;
}

float Fixed::toFloat() const
{
	return ((float )this->_rawBits / (1 << Fixed::_fractBits));
}

int Fixed::toInt() const
{
	return (this->_rawBits >> Fixed::_fractBits);
}

std::ostream &operator<<(std::ostream &sortie, const Fixed &rhs)
{
	sortie << rhs.toFloat();
	return (sortie);
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "copy assignation operator called" << std::endl;
	this->_rawBits = rhs._rawBits;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
