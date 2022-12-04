//
// Created by Kevin Di nocera on 10/31/22.
//
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name)
: ClapTrap(name)
{
	this->setHitPnt(100);
	this->setEnergy(50);
	this->setDamage(20);

	std::cout << "constructor ScavTrap called " << this->getName() << std::endl << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src)
: ClapTrap(src)
{
	std::cout << "constructor copy " << this->getName() << " is called." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	ClapTrap::operator=(rhs);
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	ScavTrap newComer(target);
	std::cout << newComer.getName() << " and " << ScavTrap::getName() << " has: "
	<< newComer.getEnergy() << " energy points" << std::endl;
	std::cout << newComer.getName() << " and " << ScavTrap::getName() << " has: "
	<< newComer.getHitP() << " Hit points" << std::endl << std::endl;
	if (this->getEnergy() && this->getHitP())
	{
		std::cout << this->getName() << " attack " << newComer.getName() << std::endl
		<< "he cause " << this->getDamage() << " points of damage " << std::endl << std::endl;
		this->setEnergy(this->getEnergy() - 1);
	}
	newComer.setHitPnt(this->getHitP() - this->getDamage());
	std::cout << ScavTrap::getName() << " has " << ScavTrap::getEnergy() << " energy points " << std::endl;
	std::cout << newComer.getName() << " has yet: " << newComer.getHitP() << " Hit points" << std::endl << std::endl ;
}

void	ScavTrap::guardGates()
{
	std::cout << this->getName() << ": Gate keeper mode ACTIVATED" << std::endl << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor of " << this->getName() << " Called" << std::endl << std::endl;
}

















//ScavTrap::ScavTrap(const std::string &name)
//: ClapTrap(name)
//{
//	this->setHitPnt(100);
//	this->setEnergy(50);
//	this->setDamage(20);
//}
//
//ScavTrap::ScavTrap(const ScavTrap &src)
//: ClapTrap(src)
//{
//	std::cout << "ScavTrap constructor of " << this->getName() << " Called" << std::endl;
//}
//
//ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
//{
//	ClapTrap::operator=(rhs);
//	return (*this);
//}
//
//void	ScavTrap::attack(const std::string &target) const
//{
//	if (getEnergy() && getDamage())
//	{
//		std::cout << this->getName() << " attack " << target << std::endl
//		<< "he cause " << this->getDamage() << std::endl;
////		this->setEnergy(this->getEnergy() - 1);
//	}
//}
//
//void	ScavTrap::guardGates() const
//{
//	std::cout << this->getName() << ": Gate keeper mode ACTIVATED" << std::endl;
//}
//
//ScavTrap::~ScavTrap()
//{
//	std::cout << "destructor is called" << std::endl;
//}