//
// Created by Kevin Di nocera on 11/6/22.
//

#include "WrongCat.hpp"

WrongCat::WrongCat()
: _type("WrongCat")
{
	std::cout << "⚬ " << this->_type <<" constructor is called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src) {}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
	WrongAnimal::operator=(rhs);
	return (*this);
}

std::string 	WrongCat::getType() const
{
	return (this->_type);
}

void	WrongCat::makeSound() const
{
	WrongAnimal::makeSound();
	std::cout << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "⚬ " << this->_type << " destructor is called" << std::endl;
}