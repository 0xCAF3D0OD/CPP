//
// Created by Kevin Di nocera on 11/6/22.
//

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	manageNameError(std::string name)
{
	for (size_t i = 0; i < name.length(); i++)
	{
		if (!isalpha(name[i]))
		{
			throw Bureaucrat::NameNotCharException();
			break ;
		}
	}
}

void	manageGradeError(int number, bool which)
{
	if (number > 150)
	{
		if (which)
			throw Bureaucrat::GradeTooHighException();
		throw Form::GradeTooHighException();
	}
	else if (number < 1)
	{
		if (which)
			throw Bureaucrat::GradeTooLowException();
		throw Form::GradeTooLowException();
	}
}

int	checkAvPaper(int numberEx, int numberSi, std::string name)
{

	try {
		manageGradeError(numberEx, false);
		manageGradeError(numberSi, false);
		manageNameError(name);
	}
	catch (Form::NameNotCharException &exe) {
		std::cerr << exe.what() << std::endl;
		return (1);
	}
	catch (Form::GradeTooLowException &exe) {
		std::cerr << exe.what() << std::endl;
		return (1);
	}
	catch (Form::GradeTooHighException &exe) {
		std::cerr << exe.what() << std::endl;
		return (1);
	}
	return (0);
}

int	checkAvBernard(int number, std::string name)
{
	try {
		manageGradeError(number, true);
		manageNameError(name);
	}
	catch (Bureaucrat::NameNotCharException &exe) {
		std::cerr << exe.what() << std::endl;
		return (1);
	}
	catch (Bureaucrat::GradeTooLowException &exe) {
		std::cerr << exe.what() << std::endl;
		return (1);
	}
	catch (Bureaucrat::GradeTooHighException &exe) {
		std::cerr << exe.what() << std::endl;
		return (1);
	}
	return(0);
}

void printInfo(Form paper, Bureaucrat Bernard, int i)
{
	if (i == 1)
		std::cout << "bureaucrat grade is :	" << BOLD_RED <<  Bernard.getGrade() << std::endl << std::endl  << RESET ;
	if (i == 3)
		std::cout << "the grade required to signe the formulaire is :	" << BOLD_RED <<  paper.getSignedGrade() << std::endl << std::endl  << RESET ;
}

int	manageError(Bureaucrat &Bernard, Form &Paper, bool who)
{
	int	ret = 0;
	if (who)
		ret = checkAvBernard(Bernard.getGrade(), Bernard.getName());
	ret = checkAvPaper(Paper.getExecuteGrade(), Paper.getSignedGrade(), Paper.getName());
	return (ret);
}

//void	manageBernard(char **av, Bureaucrat &Bernard)
//{
//	Bernard.setName(av[1]);
//	Bernard.setGrade(std::stoi(av[2]));
//}

void	printInfoArgs(void)
{
	std::cout << "argument 1:	take the" << BOLD_RED << " name " << RESET << "of the " << BOLD_RED << "Bureaucrat." << RESET << std::endl
	<< "argument 2:	take the" << BOLD_RED << " grade " << RESET << "of the " << BOLD_RED << "Bureaucrat." << RESET << std::endl
	<< "argument 3:	take the" << BOLD_RED << " name " << RESET << "of the " << BOLD_RED << "formulaire." << RESET << std::endl
	<< "argument 4:	take the" << BOLD_RED << " execute grade " << RESET << "to execute the " << BOLD_RED << "formulaire." << RESET << std::endl
	<< "argument 5:	take the" << BOLD_RED << " signing grade " << RESET << "to sign the " << BOLD_RED << "formulaire." << RESET << std::endl;
}

int main(int ac, char **av)
{
	int 		ret1 = 0;
	int 		ret2 = 0;

	if (ac != 6)
	{
		printInfoArgs();
		return (1);
	}
	else
	{
		Bureaucrat	Bernard = Bureaucrat(av[1], std::stoi(av[2]));
		Form		Paper(av[3], std::stoi(av[4]),
						  std::stoi(av[5]));
//		manageBernard(av, Bernard);
		ret1 = manageError(Bernard, Paper, 1);
		ret2 = manageError(Bernard, Paper, 1);
		if (!ret1 && !ret2)
		{
			printInfo(Paper, Bernard, 1);
			printInfo(Paper, Bernard, 3);
			Paper.beSigned(Bernard);
			Bernard.signForm(Paper);
		}
	}
	return (0);
}