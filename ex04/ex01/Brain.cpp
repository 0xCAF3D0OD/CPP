//
// Created by Kevin Di nocera on 11/4/22.
//

#include "Brain.hpp"

Brain::Brain()
{
	std::cout <<"brain constructor is called" << std::endl;
}

Brain::Brain(const Brain &src) : Animal(src) {}

Brain &Brain::operator=(const Brain &rhs)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = rhs._ideas[i];
	return (*this);
}

void	Brain::makeSound() const
{
	std::cout << getType() << "🐱:	miaou!" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor is called" << std::endl;
}