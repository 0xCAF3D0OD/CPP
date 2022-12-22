//
// Created by Kevin Di nocera on 11/7/22.
//

#include "Bureaucrat.hpp"

std::ostream	&operator<<(std::ostream &sortie, Bureaucrat const &str);

Bureaucrat::Bureaucrat()
{
	std::cout << "⚀ "<< this->getName() << " constructor is called" << std::endl;
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

std::ostream	&operator<<(std::ostream &sortie, Bureaucrat &str)
{
	sortie << str.getName();
	sortie << str.getGrade();
	return (sortie);
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return (BOLD_RED "\n⚬ the number is to low\n");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return (BOLD_RED "\n⚬ the number is to high\n");
}

const char *Bureaucrat::NameNotCharException::what() const throw()
{
	return (BOLD_RED "\n⚬ the name is not a array\n");
}

Bureaucrat::~Bureaucrat()
{
	std::cout  << RESET << "⚀ "<< "destructor is called" << std::endl;
}
