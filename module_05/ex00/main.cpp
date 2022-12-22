//
// Created by Kevin Di nocera on 11/6/22.
//

#include "Bureaucrat.hpp"

#define	BOLD_BLACK	"\033[1m\033[30m"
#define BOLD_RED	"\033[1m\033[31m"
#define BOLD_G		"\033[1m\033[32m"
#define	RESET   	"\033[0m"
#define BOLD_Y		"\033[1m\033[33m"
#define BOLD_W		"\033[1m\033[37m"

std::string	manageNameError(std::string name)
{
	for (size_t i = 0; i < name.length(); i++)
	{
		if (!isalpha(name[i]))
			throw Bureaucrat::NameNotCharException();
	}
	return (name);
}

int	manageGradeError(int number)
{
	if (number > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (number < 1)
		throw Bureaucrat::GradeTooLowException();
	return (number);
}

int	checkAv(int number, std::string name)
{
	std::string str;
	int res;

	try
	{
		res = manageGradeError(number);
		str = manageNameError(name);
		std::cout  << std::endl << BOLD_W << "→ result of res = " << res << std::endl;
		std::cout << BOLD_W << "→ result of str = " << str << std::endl;
	}
	catch (Bureaucrat::NameNotCharException &exe)
	{
		std::cerr << exe.what() << std::endl;
		return (1);
	}
	catch (Bureaucrat::GradeTooLowException &exe)
	{
		std::cerr << exe.what() << std::endl;
		return (1);
	}
	catch (Bureaucrat::GradeTooHighException &exe)
	{
		std::cerr << exe.what() << std::endl;
		return (1);
	}
	return (0);
}

int main(void)
{
	Bureaucrat	Bernard;
	std::string name;
	std::string grade;
	int 		res = 0;

	std::cout  << std::endl << BOLD_Y << "❏ For this exercise put in first place the name : " << BOLD_W;
	std::cin >> name;
	std::cout << BOLD_Y << "❏ In the second place put the grade, between 150 and 1: " << BOLD_W;
	std::cin >> grade;
	std::cout << RESET;
	if (!std::cin.fail() && !std::atoi(grade.c_str()))
	{
		std::cerr << std::endl << BOLD_RED << "✘ the number can't be a letter" << RESET << std::endl << std::endl;
		return (1);
	}
	Bernard.setName(name);
	Bernard.setGrade(std::atoi(grade.c_str()));
	res = checkAv(Bernard.getGrade(), Bernard.getName());
	if (!res)
		std::cout << std::endl << BOLD_G << "⚬ " << Bernard.getName() << ", bureaucrat grade "
		<< Bernard.getGrade() << RESET << std::endl;

	return (0);
}