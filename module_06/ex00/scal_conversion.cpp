//
// Created by Kevin Di nocera on 11/7/22.
//

#include "scal_conversion.hpp"

const char *Scal_conversion::wrongConversion::what() const throw()
{
	return (BOLD_RED "✘ conversion has failed\n" RESET);
}

const char *Scal_conversion::impossible::what() const throw()
{
	return (BOLD_RED "✘ char: no display\n" RESET);
}

const char *Scal_conversion::moreThanOne::what() const throw()
{
	return (BOLD_RED "✘ you have put to much letter\n" RESET);
}

Scal_conversion::Scal_conversion(void)
:	_retn(0), _flt(0.0)
{
//	std::cout << "scal constructor is called" << std::endl;
}

Scal_conversion::Scal_conversion(char *av, float const ret)
:	_retn(av), _flt(ret)
{
//	std::cout << ret << " scal constructor is called" << std::endl;
}

Scal_conversion::Scal_conversion(const Scal_conversion &src)
{
	*this = src;
}

Scal_conversion &Scal_conversion::operator=(const Scal_conversion &rhs)
{
	this->_retn = rhs._retn;
	return (*this);
}

char	*Scal_conversion::get_retn()
{
	return (this->_retn);
}

Scal_conversion::operator int()
{
	return (static_cast<int>(this->_flt));
}

Scal_conversion::operator char()
{
	return (static_cast<char>(this->_flt));
}

Scal_conversion::operator double()
{
	return (static_cast<double>(this->_flt));
}

Scal_conversion::~Scal_conversion()
{
//	std::cout << "scal destructor is called" << std::endl;
}
