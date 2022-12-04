//
// Created by Kevin Di nocera on 11/7/22.
//

#ifndef CPP_BUREAUCRAT_HPP
#define CPP_BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

#define	BOLD_BLACK	"\033[1m\033[30m"
#define BOLD_RED	"\033[1m\033[31m"
#define	RESET   "\033[0m"

class Form;

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

	std::string	getName(void);
	int			getGrade(void);
	void		setName(std::string name);
	void		setGrade(int grade);
	void 		signForm(Form &Rene);

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

	~Bureaucrat(void);
};

#endif //CPP_BUREAUCRAT_HPP
