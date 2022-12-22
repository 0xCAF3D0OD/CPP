//
// Created by Kevin Di nocera on 11/7/22.
//

#ifndef CPP_BUREAUCRAT_HPP
#define CPP_BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

#define	BOLD_BLACK	"\033[1m\033[30m"
#define BOLD_RED	"\033[1m\033[31m"
#define BOLD_G		"\033[1m\033[32m"
#define	RESET   	"\033[0m"
#define DARK_Y		"\033[1m\033[33m"

class AForm;

class Bureaucrat
{
private:
	std::string _name;
	int			_grade;

public:
	Bureaucrat(void);
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat(std::string const &name, int const &grade);

	Bureaucrat	&operator=(Bureaucrat const &rhs);

	std::string	getName(void) const;
	int			getGrade(void) const;
	void		setName(std::string name);
	void		setGrade(int grade);
	void 		signForm(AForm *Rene);

	void		executeForm(AForm const &form) const;

	class	GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};
	class	GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};
	class	NameNotCharException : public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};
	class	GradeNotDigitException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	~Bureaucrat(void);
};

#endif //CPP_BUREAUCRAT_HPP
