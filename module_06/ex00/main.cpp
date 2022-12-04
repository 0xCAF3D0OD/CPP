//
// Created by Kevin Di nocera on 11/6/22.
//

#include "Bureaucrat.hpp"

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
		std::cout << "result of res => " << res << std::endl;
		std::cout << "result of str => " << str << std::endl;
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

int main(int ac, char **av)
{
	Bureaucrat	Bernard;
	int 		res = 0;

	if (ac != 3)
		return (1);
	Bernard.setName(av[1]);
	Bernard.setGrade(std::stoi(av[2]));
	res = checkAv(Bernard.getGrade(), Bernard.getName());
	if (!res)
		std::cout << Bernard.getName() << ", bureaucrat grade " << Bernard.getGrade() << std::endl;

		return (0);
}