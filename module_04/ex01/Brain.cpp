//
// Created by Kevin Di nocera on 11/4/22.
//

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "⚬ 🧠 constructor is called" << std::endl;
}

Brain::Brain(const Brain &src) : Animal(src) {}

Brain &Brain::operator=(const Brain &rhs)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = rhs._ideas[i];
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "⚬ 🧠 destructor is called" << std::endl;
}