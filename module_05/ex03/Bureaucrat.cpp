//
// Created by Kevin Di nocera on 11/7/22.
//
#include "Bureaucrat.hpp"
#include "AForm.hpp"

std::ostream	&operator<<(std::ostream &sortie, Bureaucrat const &str);

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return (BOLD_RED "\n▲︎ For the Bureaucrat, the number is to low\n" RESET);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return (BOLD_RED "\n▲ For the Bureaucrat, the number is to high\n" RESET);
}

const char *Bureaucrat::NameNotCharException::what() const throw()
{
	return (BOLD_RED "\n▲ For the Bureaucrat, the name is not a array\n" RESET);
}

const char *Bureaucrat::GradeNotDigitException::what() const throw()
{
	return (BOLD_RED "▲ For the Bureaucrat, the grade is not a digit\n" RESET);
}

Bureaucrat::Bureaucrat(void)
:	_name(""), _grade()
{
	std::cout << "◼︎ Default constructor is called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int const &grade)
:	_name(name), _grade(grade)
{
	for (size_t i = 0; i < _name.length(); i++)
	{
		if (!isalpha(_name[i]))
			throw Bureaucrat::NameNotCharException();
	}
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
	std::cout << "◼︎ Default constructor is called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	*this = src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	this->_grade = rhs._grade;
	this->_name = rhs._name;
	return (*this);
}

void Bureaucrat::setName(std::string name)
{
	this->_name = name;
}

void Bureaucrat::setGrade(int grade)
{
	this->_grade = grade;
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

void	Bureaucrat::signForm(AForm *Rene)
{
	if (Rene->getSigned())
		std::cout << BOLD_G << "☑︎ the formulaire is signed" << std::endl << RESET;
	else
		std::cout << std::endl << BOLD_RED << "▲ the formulaire couldn't be signed because "
					 "the grade is superior autorisation grade" << std::endl << std::endl << RESET;
}

std::ostream	&operator<<(std::ostream &sortie, Bureaucrat &str)
{
	sortie << str.getName();
	sortie << str.getGrade();
	return (sortie);
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "◼︎ Bureaucrat destructor is called" << std::endl;
}