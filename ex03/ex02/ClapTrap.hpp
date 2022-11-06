//
// Created by Kevin Di nocera on 10/29/22.
//

#ifndef CPP_CLAPTRAP_HPP
#define CPP_CLAPTRAP_HPP

#include <iostream>
#include <string>
#include <cctype>

class	ClapTrap
{
private:
	std::string _name;
	int _HitPoint;
	int _EnergyPoint;
	int	_AttackDamage;

public:
	ClapTrap(std::string const &name);
	ClapTrap(ClapTrap const &src);

	ClapTrap &operator=(ClapTrap const &rhs);

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	std::string	getName(void) const;
	int			getEnergy(void) const;
	int			getHitP(void) const;
	int			getDamage(void) const;

	void	setName(std::string name);
	void	setDamage(int damage);
	void	setHitPnt(int hitPnt);
	void	setEnergy(int Nrj);


	~ClapTrap();
};
#endif //CPP_CLAPTRAP_HPP
