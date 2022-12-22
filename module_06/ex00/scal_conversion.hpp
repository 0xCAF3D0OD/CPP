//
// Created by Kevin Di nocera on 11/7/22.
//

#ifndef CPP_BUREAUCRAT_HPP
#define CPP_BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

#define	BOLD_BLACK	"\033[1m\033[30m"
#define BOLD_RED	"\033[1m\033[31m"
#define BOLD_G		"\033[1m\033[32m"
#define	RESET   	"\033[0m"
#define BOLD_Y		"\033[1m\033[33m"
#define BOLD_W		"\033[1m\033[37m"

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
