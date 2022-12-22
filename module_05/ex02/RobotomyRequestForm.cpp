//
// Created by Kevin Di nocera on 11/29/22.
//

#include "RobotomyRequestForm.hpp"

const char *RobotomyRequestForm::RandomFalseException::what() const throw()
{
	return (BOLD_RED "▲ the robotomy has failed wrong grade\n" RESET);
}

const char *RobotomyRequestForm::RandomRandException::what() const throw()
{
	return (BOLD_RED "\n☒ the robotomy has failed 50% fail\n" RESET);
}

RobotomyRequestForm::RobotomyRequestForm(void)
{
	std::cout << "◆ constructor presidential is called\n" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &name, int const &execGrade, int const &signGrade)
:	AForm(name, execGrade, signGrade), _target(name + " the Robotomised")
{
	std::cout << "◆ constructor presidential is called\n" << std::endl;
}

void	RobotomyRequestForm::set_Target(std::string const &name)
{
	this->_target = name;
}

void RobotomyRequestForm::executeAction(void) const
{
	int random;
	if (getExecuteGrade() <= 72 && getSignedGrade() <= 45)
	{
		srand(time(NULL));
		 random = rand() % 100;
		if (random % 2)
			std::cout << std::endl << BOLD_G << "☑︎ " <<  this->_target
					  << " has been robotomised with success" << std::endl << std::endl
					  << RESET;
		else
			throw RandomRandException();
	}
	else
		throw RandomFalseException();
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src)
		:	AForm(src)
{
	std::cout << "◆ constructor copy Robotomy is called\n" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	_target = rhs._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "◆ destructor presidential is called\n" << std::endl;
}