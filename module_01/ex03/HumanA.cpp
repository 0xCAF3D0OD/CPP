//
// Created by Kevin Di nocera on 10/20/22.
//
#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
: _name(name), _weapon(weapon) {}

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}

HumanA::~HumanA() {}