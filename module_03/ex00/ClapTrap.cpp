//
// Created by Kevin Di nocera on 10/29/22.
//

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string const &name)
: _name(name), _HitPoint(10), _EnergyPoint(10), _AttackDamage(0)
{
	std::cout << "constructor called " << _name << std::endl;
}

std::string	&ClapTrap::getName()
{
	return (_name);
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	this->_name = rhs._name;
	this->_EnergyPoint = rhs._EnergyPoint;
	this->_HitPoint = rhs._HitPoint;
	this->_AttackDamage = rhs._AttackDamage;
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	ClapTrap	JeJe(target);
	std::cout << BOLD_Y << "JeJe has: " << JeJe._EnergyPoint << " energy points" << std::endl;
	std::cout << "JeJe has: " << JeJe._HitPoint << " Hit points" << RESET << std::endl;

	if (JeJe._EnergyPoint && JeJe._HitPoint)
	{
		JeJe._HitPoint -= _AttackDamage;
		_EnergyPoint--;
	}

	std::cout <<  BOLD_Y << "JeJe has: " << JeJe._HitPoint << " Hit points" << std::endl;
	std::cout << "JeJe has: " << JeJe._EnergyPoint << " energy points" << std::endl;
	std::cout << "ClapTrap has " << ClapTrap::_EnergyPoint << " energy points " << std::endl << std::endl;
	std::cout << BOLD_RED << "ClapTrap " << ClapTrap::_name << " attacks " << JeJe._name
	<< ", causing " << ClapTrap::_AttackDamage << " points of damage." << RESET << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_AttackDamage = amount;
	std::cout << BOLD_RED << "ClapTrap cause " << _AttackDamage << " damages." << RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_EnergyPoint)
	{
		this->_EnergyPoint += amount;
		std::cout << BOLD_G << "ClapTrap retrieve " << _EnergyPoint << " energy points." << RESET << std::endl;
	}
	else
		exit(1);
}

ClapTrap::~ClapTrap()
{
	std::cout << "destructor called" << std::endl;
}