//
// Created by Kevin Di nocera on 11/7/22.
//
#include "ABureaucrat.hpp"
#include "AForm.hpp"

std::ostream	&operator<<(std::ostream &sortie, ABureaucrat const &str);

const char *ABureaucrat::GradeTooLowException::what() const throw()
{
	return ("the number is to low\n");
}

const char *ABureaucrat::GradeTooHighException::what() const throw()
{
	return ("the number is to high\n");
}

const char *ABureaucrat::NameNotCharException::what() const throw()
{
	return ("the name is not a array\n");
}

ABureaucrat::ABureaucrat(void)
:	_name(""), _grade()
{
	std::cout << "Default constructor is called" << std::endl;
}

ABureaucrat::ABureaucrat(std::string const &name, int const &grade)
:	_name(name), _grade(grade)
{
	for (size_t i = 0; i < _name.length(); i++)
	{
		if (!isalpha(_name[i]))
			throw ABureaucrat::NameNotCharException();
	}
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
	std::cout << "Default constructor is called" << std::endl;
}

ABureaucrat::ABureaucrat(const ABureaucrat &src)
{
	*this = src;
}

ABureaucrat &ABureaucrat::operator=(const ABureaucrat &rhs)
{
	this->_grade = rhs._grade;
	this->_name = rhs._name;
	return (*this);
}

void ABureaucrat::setName(std::string name)
{
	this->_name = name;
}

void ABureaucrat::setGrade(int grade)
{
	this->_grade = grade;
}

int ABureaucrat::getGrade() const
{
	return (this->_grade);
}

std::string ABureaucrat::getName() const
{
	return (this->_name);
}

void	ABureaucrat::signForm(AForm *Rene)
{
	if (Rene->getSigned())
		std::cout  << std::endl << BOLD_RED <<  "the formulaire is signed" << std::endl <<  std::endl << RESET;
	else
		std::cout << std::endl << BOLD_RED << "the formulaire couldn't be signed because "
					 "the grade is superior autorisation grade" << std::endl << std::endl << RESET;
}

void	ABureaucrat::executeForm(const AForm &form)
{
	try {
		form.execute(*this);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &sortie, ABureaucrat &str)
{
	sortie << str.getName();
	sortie << str.getGrade();
	return (sortie);
}

ABureaucrat::~ABureaucrat(void)
{
	std::cout << "ABureaucrat destructor is called" << std::endl;
}