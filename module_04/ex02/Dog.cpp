//
// Created by Kevin Di nocera on 11/3/22.
//

#include "Dog.hpp"

Dog::Dog(void)
		: _type("Dog")
{
	this->_brain = new Brain();
	std::cout << "⚬ 🐶 " << this->_type <<" constructor is called" << std::endl;
}

Dog::Dog(const Dog &src) : AAnimal(src) {}

Dog &Dog::operator=(const Dog &rhs)
{
	AAnimal::operator=(rhs);
	return (*this);
}

std::string 	Dog::getType(void) const
{
	return (this->_type);
}

void	Dog::makeSound(void) const
{
	std::cout << BOLD_W << "⚬ " << getType() << " 🐶:	Wooouuuuuuf !" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "⚬ 🐶 " << this->_type << " destructor is called" << std::endl;
	delete this->_brain;
}