//
// Created by Kevin Di nocera on 10/29/22.
//

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("name"), _HitPoint(10), _EnergyPoint(10), _AttackDamage(0){}

ClapTrap::ClapTrap(std::string const &name)
: _name(name), _HitPoint(10), _EnergyPoint(10), _AttackDamage(0)
{
	std::cout << "⚬ constructor ClapTrap called " << _name << std::endl << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	*this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	this->_name = rhs.getName();
	this->_EnergyPoint = rhs.getEnergy();
	this->_HitPoint = rhs.getHitP();
	this->_AttackDamage = rhs.getDamage();
	return (*this);
}
/* ------------	get function ---------------*/

std::string	ClapTrap::getName() const
{
	return (this->_name);
}

int	ClapTrap::getDamage() const
{
	return (this->_AttackDamage);
}

int	ClapTrap::getHitP() const
{
	return (this->_HitPoint);
}

int	ClapTrap::getEnergy() const
{
	return (this->_EnergyPoint);
}

/* ------------	set function ---------------*/

void	ClapTrap::setName(std::string name)
{
	this->_name = name;
}

void	ClapTrap::setHitPnt(int hitPnt)
{
	this->_HitPoint = hitPnt;
}

void	ClapTrap::setDamage(int damage)
{
	this->_AttackDamage = damage;
}

void	ClapTrap::setEnergy(int energy)
{
	this->_EnergyPoint = energy;
}

/* ------------	exercise function ---------------*/


void	ClapTrap::attack(const std::string &target)
{
	std::cout << BOLD_Y << "	⚬ " << target << " has: " << ClapTrap::getEnergy() << " energy points" << std::endl;
	std::cout << "	⚬ " << ClapTrap::getName() << " has: " << ClapTrap::getHitP() << " Hit points" << RESET << std::endl << std::endl;
	if (this->getEnergy() && this->getHitP())
	{
		std::cout << BOLD_RED << "	⚬ " << this->getName() << " attack " << ClapTrap::getName() << std::endl
				<< "	⚬ " << "he cause " << this->getDamage() << " points of damage " << std::endl << std::endl;
		this->setEnergy(this->getEnergy() - 1);
	}
	else
	{
		std::cout << BOLD_RED << "	⚬ " << target << " doesn't have enough Hit points => " << _HitPoint << RESET << std::endl;
		exit(1);
	}
	ClapTrap::setHitPnt(this->getHitP() - this->getDamage());
	std::cout << BOLD_Y << "	⚬ " << ClapTrap::getName() << " has " << ClapTrap::getEnergy() << " energy points " << std::endl;
	std::cout << "	⚬ " << target << " has yet: " << ClapTrap::getHitP() << " hit points." << RESET << std::endl << std::endl ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_AttackDamage = amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_EnergyPoint)
	{
		this->_EnergyPoint += amount;
		std::cout << BOLD_G << "	⚬ " << "ClapTrap retrieve " << amount << " points. He has yet "
				  << _EnergyPoint << " energy points." << RESET << std::endl;
	}
	else
	{
		std::cout << BOLD_RED << "	⚬ " << _name << " doesn't have enough points => " << amount << RESET << std::endl;
		exit(1);
	}
}

ClapTrap::~ClapTrap()
{
	std::cout << "⚬ ClapTrap destructor of " << _name << " called" << std::endl;
}
