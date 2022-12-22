//
// Created by Kevin Di nocera on 11/8/22.
//

#ifndef CPP_FORM_HPP
#define CPP_FORM_HPP

#include "Bureaucrat.hpp"

#define	BOLD_BLACK	"\033[1m\033[30m"
#define BOLD_RED	"\033[1m\033[31m"
#define BOLD_G		"\033[1m\033[32m"
#define	RESET   	"\033[0m"
#define BOLD_Y		"\033[1m\033[33m"
#define BOLD_W		"\033[1m\033[37m"

class Bureaucrat;
class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class	AForm
{
private:
	std::string const	_name;
	int	const			_executeGrade;
	int const 			_signedGrade;
	bool				_isSigned;

public:
	AForm(void);
	AForm(std::string const &name, int const executeGrade,
		 	int const signedGrade);
	AForm(AForm const &src);

	AForm &operator=(AForm const &rhs);

	std::string		getName() const;
	bool 			getSigned() const;
	int 			getExecuteGrade() const;
	int 			getSignedGrade() const;

	bool 			beSigned(Bureaucrat *Bernard);
	void			execute(Bureaucrat const &executor) const;
	virtual void	executeAction(void) const = 0;

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

	class	NotSigned : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class	GradeNotDigitException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	virtual ~AForm(void);
};
#endif //CPP_FORM_HPP
