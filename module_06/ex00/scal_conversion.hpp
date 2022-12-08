//
// Created by Kevin Di nocera on 11/7/22.
//

#ifndef CPP_BUREAUCRAT_HPP
#define CPP_BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

class Scal_conversion
{
private:
	char	*_retn;
	float 	_flt;

public:
	Scal_conversion();
	Scal_conversion(char *av, float const ret);
	Scal_conversion(Scal_conversion const &src);

	Scal_conversion	&operator=(Scal_conversion const &rhs);
	float	getf(void) {return (this->_flt);};

	operator	int();
	operator	char();
	operator	float();
	operator	double();


	char	*get_retn(void);

	class	moreThanOne : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class	wrongConversion : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class	impossible : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	~Scal_conversion();
};
#endif //CPP_BUREAUCRAT_HPP
