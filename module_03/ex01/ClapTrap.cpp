//
// Created by Kevin Di nocera on 10/29/22.
//

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string const &name)
: _name(name), _HitPoint(10), _EnergyPoint(10), _AttackDamage(0)
{
	std::cout << "constructor ClapTrap called " << _name << std::endl << std::endl;
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
	ClapTrap	JeJe(target);
	std::cout << JeJe.getName() << " and " << ClapTrap::getName() << " has: " << JeJe.getEnergy() << " energy points" << std::endl;
	std::cout << JeJe.getName() << " and " << ClapTrap::getName() << " has: " << JeJe.getHitP() << " Hit points" << std::endl << std::endl;
	if (this->getEnergy() && this->getHitP())
	{
		std::cout << this->getName() << " attack " << JeJe.getName() << std::endl
				  << "he cause " << this->getDamage() << " points of damage " << std::endl << std::endl;
		this->setEnergy(this->getEnergy() - 1);
	}
	JeJe.setHitPnt(this->getHitP() - this->getDamage());
	std::cout << ClapTrap::getName() << " has " << ClapTrap::getEnergy() << " energy points " << std::endl;
	std::cout << JeJe.getName() << " has yet: " << JeJe.getHitP() << " Hit points" << std::endl << std::endl ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_AttackDamage = amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->_EnergyPoint += amount;
	std::cout << "ClapTrap retrieve " << _EnergyPoint << " energy points." << std::endl << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}