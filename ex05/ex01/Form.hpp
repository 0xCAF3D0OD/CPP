//
// Created by Kevin Di nocera on 11/8/22.
//

#ifndef CPP_FORM_HPP
#define CPP_FORM_HPP

#include "Bureaucrat.hpp"


class Bureaucrat;

class	Form
{
private:
	std::string const	_name;
	int	const			_executeGrade;
	int const 			_signedGrade;
	bool				_isSigned;

public:
	Form(void);
	Form(std::string const name, int const executeGrade,
		 	int const signedGrade, bool isSigned);
	Form(Form const &src);

	Form &operator=(Form const &rhs);

	std::string	getName();
	bool 		getSigned();
	int 		getExecuteGrade();
	int 		getSignedGrade();

	void		setName(std::string const &name);
	void 		setExecuteG(int const &executeG);
	void 		setSignedG(int const &signedG);
	bool 		beSigned(Bureaucrat &Bernard);

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
	~Form(void);
};
#endif //CPP_FORM_HPP
