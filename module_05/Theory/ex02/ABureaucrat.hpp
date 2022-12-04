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
#define	RESET   "\033[0m"

class AForm;

class ABureaucrat
{
private:
	std::string _name;
	int			_grade;

public:
	ABureaucrat(void);
	ABureaucrat(ABureaucrat const &src);
	ABureaucrat(std::string const &name, int const &grade);

	ABureaucrat	&operator=(ABureaucrat const &rhs);

	std::string	getName(void) const;
	int			getGrade(void) const;
	void		setName(std::string name);
	void		setGrade(int grade);
	void 		signForm(AForm *Rene);
	void 		executeForm(AForm const &form);

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

	~ABureaucrat(void);
};

#endif //CPP_BUREAUCRAT_HPP
