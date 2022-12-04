//
// Created by Kevin Di nocera on 11/29/22.
//

#include "PresidentialPardonForm.hpp"

const char *PresidentialPardonForm::GradeIsFalseException::what() const throw()
{
	return (BOLD_RED, "Zaphod Beeblebrox hasn't forgive\n");
}

PresidentialPardonForm::PresidentialPardonForm(void)
{
	std::cout << "constructor presidential is called\n" << std::endl;
}

void	PresidentialPardonForm::set_Target(std::string const &name)
{
	this->_target = name;
}

void PresidentialPardonForm::executeAction(void) const
{
	std::cout << BOLD_RED <<  this->_target
	<< " has been forgive by Zaphod Beeblebrox." << std::endl
	<<  std::endl << RESET;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src)
:	AForm(src)
{
	std::cout << "constructor copy presidential is called\n" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	_target = rhs._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "destructor presidential is called\n" << std::endl;
}