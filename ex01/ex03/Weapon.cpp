//
// Created by Kevin Di nocera on 10/20/22.
//

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
: _type(type) {}

std::string	Weapon::getType()
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}

Weapon::~Weapon() {}