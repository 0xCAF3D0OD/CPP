//
// Created by Kevin Di nocera on 11/7/22.
//

#ifndef CPP_BUREAUCRAT_HPP
#define CPP_BUREAUCRAT_HPP

#include <iostream>
#include <string>

#define	BOLD_BLACK	"\033[1m\033[30m"
#define BOLD_RED	"\033[1m\033[31m"
#define BOLD_G		"\033[1m\033[32m"
#define	RESET   	"\033[0m"
#define BOLD_Y		"\033[1m\033[33m"
#define BOLD_W		"\033[1m\033[37m"

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