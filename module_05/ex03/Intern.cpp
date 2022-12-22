//
// Created by Kevin Di nocera on 12/4/22.
//
#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "❍ constructor intern is called" << std::endl;
}

Intern::Intern(const Intern &src)
{
	std::cout << "❍ [Intern] copied from another object" << std::endl;
	*this = src;
}

AForm	*Intern::makeForm(std::string const &formName, std::string const &formTarget)
{
//	int	exec;
//	int	sign;
//
//	std::cout << "give a number for the execute grade and for the signed grade: ";
//
//	std::cin >> exec;
//	std::cout << " ";
//	std::cin >> sign;
//	std::cout << std::endl;
	static const int n = 3;
	t_forms forms[n] = {
			{"Shrubbery", new ShrubberyCreationForm(formTarget, 12, 34)},
			{"Robotomy", new RobotomyRequestForm(formTarget, 12, 34)},
			{"President", new PresidentialPardonForm(formTarget, 45, 34)}
	};

	AForm *ret = NULL;
	for (int i = 0; i < n; i++) {
		if (forms[i]._name == formName)
			ret = forms[i]._formClass;
		else
			delete forms[i]._formClass;
	}

	if (ret != NULL)
		std::cout << BOLD_G << "☑︎ Intern creates " << formName <<  RESET << std::endl;
	else
		std::cout << BOLD_RED << "☒ Intern fails to create " << formName <<  RESET << std::endl;

	return (ret);
}

//Intern &Intern::operator=(const Intern &rhs)
//{
//	 = rhs._target;
//	return (*this);
//}

Intern::~Intern()
{
	std::cout << "❍ Intern Destructor is called." << std::endl;
}