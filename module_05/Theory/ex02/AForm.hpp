//
// Created by Kevin Di nocera on 11/8/22.
//

#ifndef CPP_FORM_HPP
#define CPP_FORM_HPP

#include "ABureaucrat.hpp"

class ABureaucrat;

class	AForm
{
private:
	std::string const	_name;
	int	const			_executeGrade;
	int const 			_signedGrade;
	bool				_isSigned;

public:
	AForm(void);
	AForm(std::string const &name, int const &executeGrade,
		 	int const &signedGrade);
	AForm(AForm const &src);

	AForm &operator=(AForm const &rhs);

	std::string			getName();
	virtual bool 		getSigned();
	virtual int 		getExecuteGrade();
	virtual int 		getSignedGrade();
	void				execute(ABureaucrat const &executor) const;

	bool 				beSigned(ABureaucrat *Bernard);
	virtual void 		executeAction(void) const;

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

	~AForm(void);
};
#endif //CPP_FORM_HPP
