//
// Created by Kevin Di nocera on 11/3/22.
//

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor is called" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}

void	Animal::makeSound() const
{
	std::cout << getType() << "🦄:	is a animal ?!! we don't know what sound he make"
	<< std::endl << std::endl;
}
Animal::~Animal()
{
	std::cout << "Animal destructor is called" << std::endl;
}