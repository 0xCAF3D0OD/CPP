//
// Created by Kevin Di nocera on 11/6/22.
//

#include "Bureaucrat.hpp"
#include "Form.hpp"

std::string	manageNameError(std::string name)
{
	for (size_t i = 0; i < name.length(); i++)
	{
		if (!isalpha(name[i]))
		{
			throw Bureaucrat::NameNotCharException();
			break ;
		}
	}
	return (name);
}

int	manageGradeError(int number, bool which)
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
	return (number);
}

int	checkAvRoger(int numberEx, int numberSi, std::string name)
{
	std::string strFor;
	int gradeForEx;
	int gradeForSi;
	try {
		gradeForEx = manageGradeError(numberEx, false);
		gradeForSi = manageGradeError(numberSi, false);
		strFor = manageNameError(name);
		std::cout << "result of strFor => " << strFor << std::endl;
		std::cout << "result of gradeForEx => " << gradeForEx << std::endl;
		std::cout << "result of gradeForSi => " << gradeForSi << std::endl;
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
	std::string strBur;
	int gradeBur;
	try {
		gradeBur = manageGradeError(number, true);
		strBur = manageNameError(name);
		std::cout << "result of gradeBur => " << gradeBur << std::endl;
		std::cout << "result of strBur => " << strBur << std::endl;
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

void	manageBernard(char **av, Bureaucrat &Bernard)
{
	Bernard.setName(av[1]);
	Bernard.setGrade(std::stoi(av[2]));
}

void	manageRoger(char **av, Form &Rene)
{
	Rene.setName(av[3]);
	Rene.setExecuteG(std::stoi(av[4]));
	Rene.setSignedG(std::stoi(av[5]));
}

int main(int ac, char **av)
{
	Bureaucrat	Bernard;
	Form		Roger;
	int 		res = 0;

	if (ac != 6)
		return (1);
	manageBernard(av, Bernard);
	manageRoger(av, Roger);
	res = checkAvBernard(Bernard.getGrade(), Bernard.getName());
	if (!res)
		std::cout << Bernard.getName() << ", bureaucrat grade " << Bernard.getGrade() << std::endl;
	res = checkAvRoger(Roger.getExecuteGrade(), Roger.getSignedGrade(), Roger.getName());
	if (!res)
		std::cout << Bernard.getName() << ", bureaucrat grade " << Bernard.getGrade() << std::endl;
	return (0);
}