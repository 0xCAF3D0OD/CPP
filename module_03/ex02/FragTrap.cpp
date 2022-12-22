//
// Created by Kevin Di nocera on 11/1/22.
//

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name)
: ClapTrap(name)
{
	this->setHitPnt(100);
	this->setEnergy(100);
	this->setDamage(30);

	std::cout << "constructor FragTrap called " << this->getName() << std::endl;
}

FragTrap::FragTrap(const FragTrap &src)
: ClapTrap(src)
{
	std::cout << "constructor copy FragTrap called " << this->getName() << std::endl << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	ClapTrap::operator=(rhs);
	return (*this);
}

void	FragTrap::attack(const std::string &target)
{
	FragTrap otherOne(target);
	std::cout << BOLD_Y << otherOne.getName() << " and " << FragTrap::getName() << " have: "
			  << otherOne.getEnergy() << " energy points" << std::endl;
	std::cout << otherOne.getName() << " and " << FragTrap::getName() << " have: "
			  << otherOne.getHitP() << " Hit points" << RESET << std::endl << std::endl;
	if (this->getEnergy() && this->getHitP())
	{
		std::cout << BOLD_RED << this->getName() << " attack " << otherOne.getName() << std::endl
				  << "he cause " << this->getDamage() << " points of damage " << RESET << std::endl << std::endl;
		this->setEnergy(this->getEnergy() - 1);
	}
	otherOne.setHitPnt(this->getHitP() - this->getDamage());
	std::cout << BOLD_Y << FragTrap::getName() << " has " << FragTrap::getEnergy() << " Hit points " << std::endl;
	std::cout << otherOne.getName() << " has yet: " << otherOne.getHitP() << " energy points" << RESET << std::endl << std::endl ;
}

void	FragTrap::highFivesGuys()
{
	std::cout << BOLD_G << this->getName() << ": High five boys, skipper what is the new ?!!" << RESET << std::endl << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor of " << this->getName() << " Called" << std::endl;
}