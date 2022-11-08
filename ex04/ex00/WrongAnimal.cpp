//
// Created by Kevin Di nocera on 11/6/22.
//
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
:	_type("WrongAnimal")
{
	std::cout << getType() << " constructor is called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	*this = src;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
	this->_type = rhs.getType();
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (this->_type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << this->_type << " 🦄: is a animal ?!! we don't know what sound he make"
			  << std::endl << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << getType() << " destructor is called" << std::endl;
}