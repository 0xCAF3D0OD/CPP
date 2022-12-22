//
// Created by Kevin Di nocera on 11/1/22.
//

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("name"){}

FragTrap::FragTrap(const std::string &name)
: ClapTrap(name)
{
	this->setHitPnt(100);
	this->setEnergy(100);
	this->setDamage(30);

	std::cout << "⚬ " << "constructor FragTrap called " << this->getName() << std::endl;
}

FragTrap::FragTrap(const FragTrap &src)
: ClapTrap(src)
{
	std::cout << "⚬ " << "constructor copy FragTrap called " << this->getName() << std::endl << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	ClapTrap::operator=(rhs);
	return (*this);
}

void	FragTrap::attack(const std::string &target)
{
	std::cout << BOLD_Y << "	⚬ " << target << " has: " << FragTrap::getEnergy() << " energy points" << std::endl;
	std::cout << "	⚬ " << FragTrap::getName() << " has: " << FragTrap::getHitP() << " Hit points" << RESET << std::endl << std::endl;
	if (this->getEnergy() && this->getHitP())
	{
		std::cout << BOLD_RED << "	⚬ " << this->getName() << " attack " << FragTrap::getName() << std::endl
				  << "	⚬ " << "he cause " << this->getDamage() << " points of damage " << std::endl << std::endl;
		this->setEnergy(this->getEnergy() - 1);
	}
	else
	{
		std::cout << BOLD_RED << "	⚬ " << target << " doesn't have enough Hit points => " << FragTrap::getHitP() << RESET << std::endl;
		exit(1);
	}
	FragTrap::setHitPnt(this->getHitP() - this->getDamage());
	std::cout << BOLD_Y << "	⚬ " << FragTrap::getName() << " has " << FragTrap::getEnergy() << " energy points " << std::endl;
	std::cout << "	⚬ " << target << " has yet: " << FragTrap::getHitP() << " hit points." << RESET << std::endl << std::endl ;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	FragTrap::setDamage(amount);
}
void	FragTrap::highFivesGuys()
{
	std::cout << BOLD_G << this->getName() << ": High five boys, skipper what is the new ?!!" << RESET << std::endl << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "⚬ FragTrap destructor of " << this->getName() << " Called" << std::endl;
}