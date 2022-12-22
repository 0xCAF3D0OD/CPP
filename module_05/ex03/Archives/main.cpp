//
// Created by Kevin Di nocera on 11/6/22.
//

#include "Archives/Bureaucrat.hpp"
#include "Archives/PresidentialPardonForm.hpp"
#include "Archives/RobotomyRequestForm.hpp"
#include "Archives/ShrubberyCreationForm.hpp"
#include "Intern.hpp"

void	printInfoArgs(void)
{
	std::cout << "argument 1:	take the" << BOLD_RED << " name " << RESET << "of the " << BOLD_RED << "Bureaucrat." << RESET << std::endl
	<< "argument 2:	take the" << BOLD_RED << " grade " << RESET << "of the " << BOLD_RED << "Bureaucrat." << RESET << std::endl
	<< "argument 3:	take the" << BOLD_RED << " name " << RESET << "of the " << BOLD_RED << "formulaire." << RESET << std::endl
	<< "argument 4:	take the" << BOLD_RED << " execute grade " << RESET << "to execute the " << BOLD_RED << "formulaire." << RESET << std::endl
	<< "argument 5:	take the" << BOLD_RED << " signing grade " << RESET << "to sign the " << BOLD_RED << "formulaire." << RESET << std::endl;
	exit(1);
}

int main(int ac, char **av)
{
	if (ac != 6)
		printInfoArgs();
	try
	{
		Bureaucrat Bernard = Bureaucrat(av[1], std::stoi(av[2]));

		ShrubberyCreationForm *SCPaper = new ShrubberyCreationForm(av[3], std::stoi(av[4]), std::stoi(av[5]));
		RobotomyRequestForm *RRPaper = new RobotomyRequestForm(av[3], std::stoi(av[4]), std::stoi(av[5]));
		PresidentialPardonForm *PPPaper = new PresidentialPardonForm(av[3], std::stoi(av[4]), std::stoi(av[5]));

		Intern *test = new Intern();

		AForm *testing = test->makeForm("shrubbery", "SCPaper");

//		testing->beSigned(&Bernard);
//		SCPaper->beSigned(&Bernard);
//		RRPaper->beSigned(&Bernard);
//		PPPaper->beSigned(&Bernard);

//		Bernard.signForm(testing);
//
//		Bernard.executeForm(*testing);

		delete test;
		delete testing;
		delete PPPaper;
		delete RRPaper;
		delete SCPaper;
	}
	catch (std::exception &exe)
	{
		std::cerr << exe.what() << std::endl;
		std::exit(1);
	}
	return (0);
}

//
// Created by Kevin Di nocera on 11/6/22.
//

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	check_args(int bad, int gradeBur, int ExGrFor, int siGrFor)
{
	try {
		if (bad && !gradeBur)
			throw Bureaucrat::GradeNotDigitException();
		else if ((bad && !ExGrFor) || (bad && !siGrFor))
			throw AForm::GradeNotDigitException();
	}
	catch (Bureaucrat::GradeNotDigitException &exe) {
		std::cerr << exe.what() << std::endl;
		return (1);
	}
	catch (AForm::GradeNotDigitException &exe) {
		std::cerr << exe.what() << std::endl;
		return (1);
	}
	return (0);
}

int main(void)
{
	std::string	nameBur;
	std::string	gradeBur;
	std::string	nameFor;
	std::string	ExGrFor;
	std::string	siGrFor;

	int bad = 0;

	std::cout << "● argument 1:	take the" << BOLD_RED << " name " << RESET << "of the " << BOLD_RED << "Bureaucrat: " << RESET;
	std::cin >> nameBur;
	std::cout << "● argument 2:	take the" << BOLD_RED << " grade " << RESET << "of the " << BOLD_RED << "Bureaucrat: " << RESET;
	std::cin >> gradeBur;
	std::cout << "● argument 3:	take the" << BOLD_RED << " name " << RESET << "of the " << BOLD_RED << "formulaire: " << RESET;
	std::cin >> nameFor;
	std::cout << "● argument 4:	take the" << BOLD_RED << " execute grade " << RESET << "to execute the " << BOLD_RED << "formulaire: " << RESET;
	std::cin >> ExGrFor;
	std::cout << "● argument 5:	take the" << BOLD_RED << " signing grade " << RESET << "to sign the " << BOLD_RED << "formulaire: " << RESET;
	std::cin >> siGrFor;
	if (!std::cin.fail())
		bad = 1;
	std::cout << std::endl;
	if (check_args(bad, std::atoi(gradeBur.c_str()), std::atoi(ExGrFor.c_str()), std::atoi(siGrFor.c_str())))
		return (1);
	try
	{
		Bureaucrat Bernard = Bureaucrat(nameBur, std::atoi(gradeBur.c_str()));

		ShrubberyCreationForm *SCPaper = new ShrubberyCreationForm(nameFor, std::atoi(ExGrFor.c_str()), std::atoi(siGrFor.c_str()));
		RobotomyRequestForm *RRPaper = new RobotomyRequestForm(nameFor, std::atoi(ExGrFor.c_str()), std::atoi(siGrFor.c_str()));
		PresidentialPardonForm *PPPaper = new PresidentialPardonForm(nameFor, std::atoi(ExGrFor.c_str()), std::atoi(siGrFor.c_str()));

		Intern *test = new Intern();

		AForm *testing = test->makeForm("shrubbery", "SCPaper");

//		testing->beSigned(&Bernard);
//		SCPaper->beSigned(&Bernard);
//		RRPaper->beSigned(&Bernard);
//		PPPaper->beSigned(&Bernard);

//		Bernard.signForm(testing);
//
//		Bernard.executeForm(*testing);

		delete test;
		delete testing;
		delete PPPaper;
		delete RRPaper;
		delete SCPaper;
	}
	catch (std::exception &exe)
	{
		std::cerr << exe.what() << std::endl;
		std::exit(1);
	}
	return (0);
}
