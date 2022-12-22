//
// Created by Kevin Di nocera on 11/3/22.
//

#include "Cat.hpp"

Cat::Cat(void) : _type("cat")
{
	this->_brain = new Brain();
	std::cout << "⚬ 🐱 " << this->_type << " constructor is called" << std::endl;
}

Cat::Cat(const Cat &src) : AAnimal(src) {}

Cat &Cat::operator=(const Cat &rhs)
{
	AAnimal::operator=(rhs);
	return (*this);
}

std::string 	Cat::getType(void) const
{
	return (this->_type);
}

void	Cat::makeSound(void) const
{
	std::cout << BOLD_W << "⚬ " << getType() << " 🐱:	miaou!" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "⚬ 🐱 " << this->_type << " destructor is called" << std::endl;
	delete this->_brain;
}