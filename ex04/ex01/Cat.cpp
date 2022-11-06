//
// Created by Kevin Di nocera on 11/3/22.
//

#include "Cat.hpp"

Cat::Cat()
: type("cat")
{
	this->brain = new Brain();
	std::cout << this->type <<" constructor is called" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src) {}

Cat &Cat::operator=(const Cat &rhs)
{
	Animal::operator=(rhs);
	return (*this);
}

std::string 	Cat::getType() const
{
	return (this->type);
}

void	Cat::makeSound() const
{
	std::cout << getType() << "🐱:	miaou!" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor is called" << std::endl;
}