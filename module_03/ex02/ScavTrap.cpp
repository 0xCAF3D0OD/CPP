//
// Created by Kevin Di nocera on 10/31/22.
//
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("name"){}

ScavTrap::ScavTrap(const std::string &name)
: ClapTrap(name)
{
	this->setHitPnt(100);
	this->setEnergy(50);
	this->setDamage(20);

	std::cout << "⚬ " << "constructor ScavTrap called " << this->getName() << std::endl << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src)
: ClapTrap(src)
{
	std::cout << "⚬ " << "constructor copy " << this->getName() << " is called." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	ClapTrap::operator=(rhs);
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	std::cout << BOLD_Y << "	⚬ " << target << " has: " << ScavTrap::getEnergy() << " energy points" << std::endl;
	std::cout << "	⚬ " << ScavTrap::getName() << " has: " << ScavTrap::getHitP() << " Hit points" << RESET << std::endl << std::endl;
	if (this->getEnergy() && this->getHitP())
	{
		std::cout << BOLD_RED << "	⚬ " << this->getName() << " attack " << ScavTrap::getName() << std::endl
				<< "	⚬ " << "he cause " << this->getDamage() << " points of damage " << std::endl << std::endl;
		this->setEnergy(this->getEnergy() - 1);
	}
	else
	{
		std::cout << BOLD_RED << "	⚬ " << target << " doesn't have enough Hit points => " << ScavTrap::getHitP() << RESET << std::endl;
		exit(1);
	}
	ScavTrap::setHitPnt(this->getHitP() - this->getDamage());
	std::cout << BOLD_Y << "	⚬ " << ScavTrap::getName() << " has " << ScavTrap::getEnergy() << " energy points " << std::endl;
	std::cout << "	⚬ " << target << " has yet: " << ScavTrap::getHitP() << " hit points." << RESET << std::endl << std::endl ;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	ScavTrap::setDamage(amount);
}

void	ScavTrap::guardGates()
{
	std::cout << BOLD_G << "	⚬ " << this->getName() << ": Gate keeper mode ACTIVATED" << RESET << std::endl << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "⚬ " << "ScavTrap destructor of " << this->getName() << " Called" << std::endl << std::endl;
}
