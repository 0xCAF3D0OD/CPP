//
// Created by Kevin Di nocera on 11/6/22.
//

#include "WrongCat.hpp"

WrongCat::WrongCat()
: type("WrongCat")
{
	std::cout << this->type <<" constructor is called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src) {}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
	WrongAnimal::operator=(rhs);
	return (*this);
}

std::string 	WrongCat::getType() const
{
	return (this->type);
}

void	WrongCat::makeSound() const
{
	WrongAnimal::makeSound();
	std::cout << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << this->type << " destructor is called" << std::endl;
}