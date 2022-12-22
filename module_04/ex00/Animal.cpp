//
// Created by Kevin Di nocera on 11/3/22.
//

#include "Animal.hpp"

Animal::Animal()
:	_type("Animal")
{
	std::cout << "⚬ " << _type << " constructor is called" << std::endl;
}

Animal::Animal(const Animal &src)
{
	*this = src;
}

Animal &Animal::operator=(const Animal &rhs)
{
	this->_type = rhs.getType();
	return (*this);
}

std::string Animal::getType() const
{
	return (this->_type);
}

void	Animal::makeSound() const
{
	std::cout << BOLD_W << "⚬ " << _type << " 🦄: is a animal ?!! we don't know what sound he make" << RESET
			  << std::endl << std::endl;
}

Animal::~Animal()
{
	std::cout << "⚬ " << _type << " destructor is called" << std::endl;
}