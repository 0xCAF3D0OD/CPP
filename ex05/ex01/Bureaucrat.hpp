//
// Created by Kevin Di nocera on 11/7/22.
//

#ifndef CPP_BUREAUCRAT_HPP
#define CPP_BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	std::string _name;
	int			_grade;

public:
	Bureaucrat();
	Bureaucrat(Bureaucrat const &src);

	Bureaucrat	&operator=(Bureaucrat const &rhs);

	std::string	getName();
	int			getGrade();
	void		setName(std::string name);
	void		setGrade(int grade);
	void 		signForm(Form &Rene);

	class	GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class	GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class	NameNotCharException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	~Bureaucrat();
};

#endif //CPP_BUREAUCRAT_HPP
