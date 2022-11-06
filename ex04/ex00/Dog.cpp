//
// Created by Kevin Di nocera on 11/3/22.
//

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor is called" << std::endl;
}

std::string 	Dog::getType() const
{
	return (this->type);
}

void	Dog::makeSound() const
{
	std::cout << getType() << "🐶:	Wooouuuuuuf !" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor is called" << std::endl;
}