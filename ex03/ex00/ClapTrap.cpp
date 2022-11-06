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
	std::cout << "JeJe has: " << JeJe._EnergyPoint << " energy points" << std::endl;
	std::cout << "JeJe has: " << JeJe._HitPoint << " Hit points" << std::endl;
	if (JeJe._EnergyPoint && JeJe._HitPoint)
	{
		JeJe._HitPoint -= _AttackDamage;
		_EnergyPoint--;
	}

	std::cout << "JeJe has: " << JeJe._HitPoint << " Hit points" << std::endl;
	std::cout << "JeJe has: " << JeJe._EnergyPoint << " energy points" << std::endl;
	std::cout << "ClapTrap has " << ClapTrap::_EnergyPoint << " energy points " << std::endl;
	std::cout << "ClapTrap " << ClapTrap::_name << " attacks " << JeJe._name
	<< ", causing " << ClapTrap::_AttackDamage << " points of damage." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_AttackDamage = amount;
	std::cout << "ClapTrap cause " << _AttackDamage << " damages." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->_EnergyPoint += amount;
	std::cout << "ClapTrap retrieve " << _EnergyPoint << " energy points." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "destructor called" << std::endl;
}