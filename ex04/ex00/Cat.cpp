//
// Created by Kevin Di nocera on 11/3/22.
//

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor is called" << std::endl;
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