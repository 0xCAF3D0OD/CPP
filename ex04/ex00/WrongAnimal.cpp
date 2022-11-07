//
// Created by Kevin Di nocera on 11/6/22.
//
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
:	type("WrongAnimal")
{
	std::cout << getType() << " constructor is called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	*this = src;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
	this->type = rhs.getType();
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << this->type << " 🦄: is a animal ?!! we don't know what sound he make"
			  << std::endl << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << getType() << " destructor is called" << std::endl;
}