//
// Created by Kevin Di nocera on 11/3/22.
//

#include "Animal.hpp"

Animal::Animal()
:	_type("Animal")
{
	std::cout << getType() << " constructor is called" << std::endl;
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
	std::cout << getType() << " 🦄: is a animal ?!! we don't know what sound he make"
			  << std::endl << std::endl;
}

Animal::~Animal()
{
	std::cout << getType() << " destructor is called" << std::endl;
}