//
// Created by Kevin Di nocera on 11/9/22.
//

#include "Form.hpp"

Form::Form(void)
:	_name(""), _executeGrade(0), _signedGrade(0), _isSigned(false)
{
	std::cout << "☐ default constructor is called" << std::endl;
}

Form::Form(std::string const &name, int const executeGrade,
			int const signedGrade)
			: _name(name), _executeGrade(executeGrade), _signedGrade(signedGrade), _isSigned(false)
{
	std::cout << "☐ initialiser constructor is called" << std::endl;
}

Form::Form(Form const &src)
:	_name(src._name), _executeGrade(src._executeGrade),
	_signedGrade(src._signedGrade), _isSigned(src._isSigned)
{
	std::cout << "☐ copy constructor is called" << std::endl << std::endl;
}

Form &Form::operator=(Form const &rhs)
{
	_isSigned = rhs._isSigned;
	std::cout << "☒ isSigned is the only one to be initialised with operator '=' the others are const"
	<< std::endl;
	return (*this);
}

std::string	Form::getName()
{
	return (this->_name);
}

int	Form::getExecuteGrade()
{
	return (_executeGrade);
}

int	Form::getSignedGrade()
{
	return (_signedGrade);
}

bool	Form::getSigned()
{
	return (_isSigned);
}

bool	Form::beSigned(Bureaucrat &Bernard)
{
	if (Bernard.getGrade() <= getSignedGrade())
	{
		_isSigned = true;
		return (true);
	}

	return (false);
}

const char *Form::GradeTooLowException::what() const throw()
{
	return (BOLD_RED "\n△ For the form, the number is to low\n" RESET);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return (BOLD_RED "\n△ For the form, the number is to high\n" RESET);
}

const char *Form::NameNotCharException::what() const throw()
{
	return (BOLD_RED "\n△ For the form, the name is not a array\n" RESET);
}

const char *Form::GradeNotDigitException::what() const throw()
{
	return (BOLD_RED "\n△ For the form, the grade is not a digit or is equal to 0\n" RESET);
}

Form::~Form(void)
{
	std::cout << "☐ Form destructor is called" << std::endl;
}