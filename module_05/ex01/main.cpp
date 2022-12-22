//
// Created by Kevin Di nocera on 11/6/22.
//

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	manageNameError(std::string name, int ret)
{
	for (size_t i = 0; i < name.length(); i++)
	{
		if (!isalpha(name[i]) && ret)
			throw Bureaucrat::NameNotCharException();
		if (!isalpha(name[i]) && !ret)
			throw Form::NameNotCharException();
	}
}

void	manageGradeError(int number, int i)
{
	if (number > 150)
	{
		if (i)
			throw Bureaucrat::GradeTooHighException();
		throw Form::GradeTooHighException();
	}
	else if (number < 1)
	{
		if (i)
			throw Bureaucrat::GradeTooLowException();
		throw Form::GradeTooLowException();
	}
}

int	checkAvPaper(int numberEx, int numberSi, std::string name)
{
	try {
		manageGradeError(numberEx, 0);
		manageGradeError(numberSi, 0);
		manageNameError(name, 0);
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
		manageGradeError(number, 1);
		manageNameError(name, 1);
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
		std::cout << "☐ bureaucrat grade is : " << BOLD_Y <<  Bernard.getGrade() << std::endl << std::endl  << RESET ;
	if (i == 2)
		std::cout << "☐ the grade required to signe the formulate is : " << BOLD_Y <<  paper.getSignedGrade() << std::endl << std::endl  << RESET ;
}

int	manageError(Bureaucrat &Bernard, Form &Paper, int i)
{
	int	ret = 0;
	if (i)
		ret = checkAvBernard(Bernard.getGrade(), Bernard.getName());
	ret = checkAvPaper(Paper.getExecuteGrade(), Paper.getSignedGrade(), Paper.getName());
	return (ret);
}

int	check_args(int bad, int gradeBur, int ExGrFor, int siGrFor)
{
	try {
		if (bad && !gradeBur)
			throw Bureaucrat::GradeNotDigitException();
		else if ((bad && !ExGrFor) || (bad && !siGrFor))
			throw Form::GradeNotDigitException();
	}
	catch (Bureaucrat::GradeNotDigitException &exe) {
		std::cerr << exe.what() << std::endl;
		return (1);
	}
	catch (Form::GradeNotDigitException &exe) {
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
	Bureaucrat	Bernard = Bureaucrat(nameBur, std::atoi(gradeBur.c_str()));
	Form		Paper(nameFor, std::atoi(ExGrFor.c_str()),
					  std::atoi(siGrFor.c_str()));

	if (manageError(Bernard, Paper, 1))
		return (1);
	if (manageError(Bernard, Paper, 0))
		return (1);

	printInfo(Paper, Bernard, 1);
	printInfo(Paper, Bernard, 2);
	Paper.beSigned(Bernard);
	Bernard.signForm(Paper);

	return (0);
}