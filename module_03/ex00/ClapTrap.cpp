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
	this->_name = rhs._name;
	this->_EnergyPoint = rhs._EnergyPoint;
	this->_HitPoint = rhs._HitPoint;
	this->_AttackDamage = rhs._AttackDamage;
	return (*this);
}

/* ------------	exercise function ---------------*/


void	ClapTrap::attack(const std::string &target)
{
	std::cout << BOLD_Y << "	⚬ " << this->_name << " has: " << this->_EnergyPoint << " energy points" << std::endl;
	std::cout << "	⚬ " << target << " has: " << this->_HitPoint << " Hit points" << RESET << std::endl << std::endl;
	if (this->_EnergyPoint && this->_HitPoint)
	{
		ClapTrap::_HitPoint -= _AttackDamage;
		_EnergyPoint--;
		std::cout << BOLD_RED << "	⚬ " << this->_name << " attack " << target << std::endl
				  << "	⚬ " << "he cause " << this->_AttackDamage << " points of damage " << std::endl << std::endl;
	}
	else
	{
		std::cout << BOLD_RED << "	⚬ " << target << " doesn't have enough Hit points => " << _HitPoint << RESET << std::endl;
		exit(1);
	}
	std::cout << BOLD_Y << "	⚬ " << this->_name << " has " << this->_EnergyPoint << " energy points " << std::endl;
	std::cout << "	⚬ " << target << " has yet: " << this->_HitPoint << " hit points." << RESET << std::endl << std::endl ;
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
	std::cout << "⚬ ClapTrap " << _name << " destructor called" << std::endl;
}

//ClapTrap::ClapTrap() : _name("name"), _HitPoint(10), _EnergyPoint(10), _AttackDamage(0){}
//
//ClapTrap::ClapTrap(std::string const &name)
//: _name(name), _HitPoint(10), _EnergyPoint(10), _AttackDamage(0)
//{
//	std::cout << "⚬ constructor " << _name << " called " << std::endl;
//}
//
//std::string	&ClapTrap::getName()
//{
//	return (_name);
//}
//
//ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
//{
//	this->_name = rhs._name;
//	this->_EnergyPoint = rhs._EnergyPoint;
//	this->_HitPoint = rhs._HitPoint;
//	this->_AttackDamage = rhs._AttackDamage;
//	return (*this);
//}
//
//void	ClapTrap::attack(const std::string &target)
//{
//	std::cout << BOLD_Y << "ClapTrap has:	" << ClapTrap::_EnergyPoint << " energy points " << std::endl;
//	std::cout << target << " has:	" << ClapTrap::_HitPoint << " Hit points" << std::endl << std::endl;
//	if (ClapTrap::_EnergyPoint && ClapTrap::_HitPoint)
//	{
//		ClapTrap::_HitPoint -= _AttackDamage;
//		_EnergyPoint--;
//	}
//	else
//	{
//		std::cout << BOLD_RED << target << " doesn't have enough Hit points => " << _HitPoint << RESET << std::endl;
//		exit(1);
//	}
//	std::cout << BOLD_RED << "ClapTrap " << ClapTrap::_name << " attacks " << ClapTrap::_name << std::endl;
//	std::cout << "ClapTrap cause " << _AttackDamage << " damages." << RESET << std::endl << std::endl;
//	std::cout << BOLD_Y << target << " has yet:	" << ClapTrap::_HitPoint << " Hit points" << std::endl;
//	std::cout << "ClapTrap has yet:	" << ClapTrap::_EnergyPoint << " energy points " << RESET << std::endl << std::endl;
//}
//
//void	ClapTrap::takeDamage(unsigned int amount)
//{
//	this->_AttackDamage = amount;
//}
//
//void ClapTrap::beRepaired(unsigned int amount)
//{
//	if (_EnergyPoint)
//	{
//		this->_EnergyPoint += amount;
//		std::cout << BOLD_G << "ClapTrap retrieve " << amount << " points. He has yet "
//				  << _EnergyPoint << " energy points." << RESET << std::endl;
//	}
//	else
//	{
//		std::cout << BOLD_RED << _name << " doesn't have enough points => " << amount << RESET << std::endl;
//		exit(1);
//	}
//}
//
//ClapTrap::~ClapTrap()
//{
//	std::cout << "⚬ destructor " << _name << " called" << std::endl;
//}