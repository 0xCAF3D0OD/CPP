//
// Created by Kevin Di nocera on 10/27/22.
//

/*	the problem with the flying point number is that the computer can't take a infinity of number the flying point number allow you
 *	to compact big number, it's easier for the computer to manage them. flying point consist to multiply 1 or 2 by power 2.
 *	the power is the "exposant", it's a number powered by 2: 10^2, 10^4, 10^6, 10^18, 10^32, etc. ... . he's size is 8 for 32 bits architecture and
 *	11 in a 64 bits.
 *	for the mantisse => in 1,XXXXX * 10^(e) (e = exposant) the mantisse is the XXXXX party he is composed of 23 bits in a 32 bits architecture and
 *	52 bits in an 64 bits.
 *	for a better understanding check this reference => https://www.redlab.io/le-monde-merveilleux-des-flottants/ .
 * */
#include "fixed.hpp"

Fixed::Fixed(void) : _rawBits(0)
{
//	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
//	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = value << Fixed::_fractBits;
 }

//	"Roundf" return the integral value that is nearest to "(value * (1 << Fixed::_fractbits))"
//	with halfway cases rounded away from zero. => avec des cas intermédiaires arrondis à partir de zéro.
//	the return : The value of x rounded to the nearest integral (as a floating-point value).
Fixed::Fixed(const float value)
{
//	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(value * (1 << Fixed::_fractBits));
}

Fixed::Fixed(const Fixed &src)
{
//	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}
int	Fixed::getRawBits() const
{
//	std::cout << "get function called" << std::endl;
	return (this->_rawBits);
}

void Fixed::setRawBits(const int rawBits)
{
//	std::cout << "set function called" << std::endl;
	this->_rawBits = rawBits;
}

float Fixed::toFloat() const
{
	return ((float )this->_rawBits / (1 << Fixed::_fractBits));
}

int	Fixed::toInt() const
{
	return(this->_rawBits >> Fixed::_fractBits);
}

std::ostream &operator<<(std::ostream &sortie, const Fixed &rhs)
{
	sortie << rhs.toFloat();
	return (sortie);
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
//	std::cout << "copy assignation operator called" << std::endl;
	this->_rawBits = rhs._rawBits;
	return (*this);
}

bool	Fixed::operator==(const Fixed &rhs) const
{
//	std::cout << "comparator assignation operator called" << std::endl;
	return (this->_rawBits == rhs._rawBits);
}

bool	Fixed::operator<=(const Fixed &rhs)  const
{
//	std::cout << "less than ... assignation operator called" << std::endl;
	return (this->_rawBits <= rhs._rawBits);
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
//	std::cout << "bigger than ... assignation operator called" << std::endl;
	return (this->_rawBits >= rhs._rawBits);
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
//	std::cout << "different than ... assignation operator called" << std::endl;
	return (this->_rawBits != rhs._rawBits);
}

bool	Fixed::operator<(const Fixed &rhs)  const
{
//	std::cout << "less than ... assignation operator called" << std::endl;
	return (this->_rawBits < rhs._rawBits);
}

bool	Fixed::operator>(const Fixed &rhs)  const
{
//	std::cout << "less than ... assignation operator called" << std::endl;
	return (this->_rawBits > rhs._rawBits);
}

//	pourquoi la deuxième variante renvoi pas la meme chose
//	0 + 10.1016 = 10.1016 => actuelle, 0 + 10.1016 = 2586 => commentaire.
Fixed	Fixed::operator+(const Fixed &rhs) const
{
	Fixed	pos;
	pos._rawBits = (this->_rawBits + rhs.getRawBits());

//	std::cout << "assignation operator '+' called from =>	" << this->_rawBits
//			  << " and " << rhs.getRawBits() << std::endl;
	return (pos);
//	2ème variante => return (Fixed(this->_rawBits + rhs.getRawBits()));
}

Fixed	&Fixed::operator++(void)
{
//	std::cout << "assignation operator '++' called from =>	" << this->_rawBits
//	<< std::endl;
	++(this->_rawBits);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	prev(*this);

//	std::cout << "assignation operator '++' called from =>	" << this->_rawBits
//			  << std::endl;
	++(this->_rawBits);
	return (prev);
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	Fixed	neg;
	neg._rawBits = (this->_rawBits - rhs.getRawBits());
//	std::cout << "assignation operator '-' called from =>	" << this->_rawBits
//			  << " and " << rhs.getRawBits() << std::endl;
	return (neg);
//	2ème variante => return (Fixed(this->_rawBits - rhs.getRawBits()));
}

Fixed	&Fixed::operator--(void)
{
	this->_rawBits--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	old(*this);

	--(*this);
	return (old);
}

//the result must be in point number so the function toFloat must be use if I use rawBits variable the result is false.
Fixed	Fixed::operator*(const Fixed &rhs) const
{
	Fixed	mult;

	mult = (this->toFloat() * rhs.toFloat());
//	std::cout << "assignation operator '*' called from =>	" << this->_rawBits
//			  << " and " << rhs.getRawBits() << std::endl;
	return (mult);
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	Fixed	div;

	div = (this->toFloat() / rhs.toFloat());
//	std::cout << "assignation operator '/' called from =>	" << this->_rawBits
//			  << " and " << rhs.getRawBits() << std::endl;
	return (div);
}

//	question pourquoi on peut pas definir la function en float ??!!!
Fixed	Fixed::min(Fixed &fMin1, Fixed &fMin2)
{
	if (fMin1 < fMin2)
		return (fMin1);
	return (fMin2);
}

//	question pourquoi on peut pas definir la function en float ??!!!
Fixed	Fixed::min(const Fixed &fMin1, const Fixed &fMin2)
{
	if (fMin1 < fMin2)
		return (fMin1);
	return (fMin2);
}

//	question pourquoi on peut pas definir la function en float ??!!!
Fixed	Fixed::max(Fixed &fMax1, Fixed &fMax2)
{
	if (fMax1 > fMax2)
		return fMax1;
	return (fMax2);
}

//	question pourquoi on peut pas definir la function en float ??!!!
Fixed	Fixed::max(const Fixed &fMax1, const Fixed &fMax2)
{
	if (fMax1 > fMax2)
		return fMax1;
	return (fMax2);
}

Fixed::~Fixed()
{
//	std::cout << "Destructor called" << std::endl;
}
