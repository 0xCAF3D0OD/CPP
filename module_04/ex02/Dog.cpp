//
// Created by Kevin Di nocera on 11/3/22.
//

#include "Dog.hpp"

Dog::Dog()
: _type("Dog")
{
	this->_brain = new Brain();
	std::cout << this->_type <<" constructor is called" << std::endl;
}

Dog::Dog(const Dog &src) : AAnimal(src) {}

Dog &Dog::operator=(const Dog &rhs)
{
	AAnimal::operator=(rhs);
	return (*this);
}

std::string 	Dog::getType() const
{
	return (this->_type);
}

void	Dog::makeSound() const
{
	std::cout << getType() << " 🐶:	Wooouuuuuuf !" << std::endl;
}

Dog::~Dog()
{
	std::cout << getType() << " destructor is called" << std::endl;
}