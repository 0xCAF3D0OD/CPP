//
// Created by Kevin Di nocera on 10/20/22.
//
#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
: _name(name), _weapon(NULL) {}

void	HumanB::setWeapon(Weapon weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack()
{
	if (_weapon != NULL)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " attack with his fist" << std::endl;
}

HumanB::~HumanB() {}