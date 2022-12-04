//
// Created by Kevin Di nocera on 11/6/22.
//

#include "ABureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void printInfo(AForm *paper, ABureaucrat Bernard, int i)
{
	if (i == 1)
		std::cout << "bureaucrat grade is :	" << BOLD_RED <<  Bernard.getGrade() << std::endl << std::endl  << RESET ;
	if (i == 3)
		std::cout << "the grade required to signe the formulaire is :	" << BOLD_RED << paper->getSignedGrade() << std::endl << std::endl  << RESET ;
}

void printInfoClass(AForm *President)
{
	std::cout << "target grade is :	" << BOLD_RED <<  President->getExecuteGrade() << std::endl << std::endl  << RESET ;
}
void	printInfoArgs(void)
{
	std::cout << "argument 1:	take the" << BOLD_RED << " name " << RESET << "of the " << BOLD_RED << "ABureaucrat." << RESET << std::endl
	<< "argument 2:	take the" << BOLD_RED << " grade " << RESET << "of the " << BOLD_RED << "ABureaucrat." << RESET << std::endl
	<< "argument 3:	take the" << BOLD_RED << " name " << RESET << "of the " << BOLD_RED << "formulaire." << RESET << std::endl
	<< "argument 4:	take the" << BOLD_RED << " execute grade " << RESET << "to execute the " << BOLD_RED << "formulaire." << RESET << std::endl
	<< "argument 5:	take the" << BOLD_RED << " signing grade " << RESET << "to sign the " << BOLD_RED << "formulaire." << RESET << std::endl
	<< "argument 6:	take the" << BOLD_RED << " index " << RESET << "for the different class " << RESET << std::endl;
	exit(1);
}

void	return_nameSRP(ShrubberyCreationForm *Shrubbery, RobotomyRequestForm *Robotomy, PresidentialPardonForm *President, int i)
{
	std::string	name;

	std::cout << "give a name to the target: ";
	if (i == 1)
	{
		std::cin >> name;
		std::cout << std::endl;
		Shrubbery->set_Target(name);
//		Shrubbery->executeAction();
	}
	if (i == 2)
	{
		std::cin >> name;
		std::cout << std::endl;
		Robotomy->set_Target(name);
//		Robotomy->executeAction();
	}
	if (i == 3)
	{
		std::cin >> name;
		std::cout << std::endl;
		President->set_Target(name);
//		President->executeAction();
	}
}

int main(int ac, char **av)
{
	if (ac != 7)
		printInfoArgs();
	try
	{
		AForm *Paper = new AForm(av[3], std::stoi(av[4]), std::stoi(av[5]));
		ABureaucrat Bernard = ABureaucrat(av[1], std::stoi(av[2]));
		ShrubberyCreationForm	Shrubbery;
		RobotomyRequestForm		Robotomy;
		PresidentialPardonForm	President;

		if (strcmp(av[6], "1") == 0)
			return_nameSRP(&Shrubbery, &Robotomy, &President, 1);
		if (strcmp(av[6], "2") == 0)
			return_nameSRP(&Shrubbery, &Robotomy, &President, 2);
		if (strcmp(av[6], "3") == 0)
			return_nameSRP(&Shrubbery, &Robotomy, &President, 3);

		printInfo(Paper, Bernard, 1);
		printInfo(Paper, Bernard, 2);
		printInfoClass(&President);

		Paper->beSigned(&Bernard);
		Bernard.signForm(Paper);

	}
	catch (std::exception &exe)
	{
		std::cerr << exe.what() << std::endl;
		std::exit(1);
	}
	return (0);
}
