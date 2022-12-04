//
// Created by Kevin Di nocera on 11/7/22.
//

#include "Bureaucrat.hpp"
#include "Form.hpp"

std::ostream	&operator<<(std::ostream &sortie, Bureaucrat const &str);

Bureaucrat::Bureaucrat(void)
:	_name(""), _grade()
{
	std::cout << "Default constructor is called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int const &grade)
:	_name(name), _grade(grade)
{
	std::cout << "Default constructor is called" << std::endl;
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

int Bureaucrat::getGrade()
{
	return (this->_grade);
}

std::string Bureaucrat::getName()
{
	return (this->_name);
}

void	Bureaucrat::signForm(Form &Rene)
{
	if (Rene.getSigned())
		std::cout  << std::endl << BOLD_RED <<  "the formulaire is signed" << std::endl <<  std::endl << RESET;
	else
		std::cout << std::endl << BOLD_RED << "the formulaire couldn't be signed because "
					 "the grade is superior autorisation grade" << std::endl << std::endl << RESET;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("the number is to low\n");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("the number is to high\n");
}

const char *Bureaucrat::NameNotCharException::what() const throw()
{
	return ("the name is not a array\n");
}

std::ostream	&operator<<(std::ostream &sortie, Bureaucrat &str)
{
	sortie << str.getName();
	sortie << str.getGrade();
	return (sortie);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor is called" << std::endl;
}