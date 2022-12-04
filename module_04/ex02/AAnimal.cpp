//
// Created by Kevin Di nocera on 11/3/22.
//

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal constructor is called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
	*this = src;
}

AAnimal &AAnimal::operator=(const AAnimal &rhs)
{
	this->_type = rhs.getType();
	return (*this);
}

std::string AAnimal::getType() const
{
	return (this->_type);
}
//	* function "makeSound" has been pured for abstract the class
//
//void	AAnimal::makeSound() const
//{
//	std::cout << getType() << "🦄:	is a animal ?!! we don't know what sound he make"
//	<< std::endl << std::endl;
//}

AAnimal::~AAnimal()
{
	std::cout << "Animal destructor is called" << std::endl;
}