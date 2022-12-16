//
// Created by Kevin Di nocera on 10/13/22.
//
#include "Zombie.hpp"

Zombie::Zombie()
{}

void	Zombie::announce() const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::setName(std::string name)
{
	this->_name = name;
	return (this->_name);
}

Zombie::~Zombie()
{
	std::cout << this->_name << ": have enough BraiiiiiiinnnzzzZ...!" << std::endl;
}