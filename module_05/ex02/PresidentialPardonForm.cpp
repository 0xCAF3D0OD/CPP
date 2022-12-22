//
// Created by Kevin Di nocera on 11/29/22.
//

#include "PresidentialPardonForm.hpp"

const char *PresidentialPardonForm::GradeIsFalseException::what() const throw()
{
	return (BOLD_RED, "✪ Zaphod Beeblebrox hasn't forgive\n");
}

PresidentialPardonForm::PresidentialPardonForm(void)
{
	std::cout << "✪ default constructor presidential is called\n" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &name, int const &execGrade, int const &signGrade)
:	AForm(name, execGrade, signGrade), _target(name + " the President")
{
	std::cout << "✪ constructor presidential is called\n" << std::endl;
}

void PresidentialPardonForm::executeAction(void) const
{
	if (getExecuteGrade() <= 5 && getSignedGrade() <= 25)
		std::cout << BOLD_G << "☑︎ " << this->_target
				  << " has been forgive by Zaphod Beeblebrox." << std::endl
				  <<  std::endl << RESET;
	else
		throw GradeIsFalseException();
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src)
:	AForm(src)
{
	std::cout << "✪ constructor copy presidential is called\n" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	_target = rhs._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "✪ destructor presidential is called\n" << std::endl;
}