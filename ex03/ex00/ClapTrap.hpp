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

	std::string &getName(void);
	int	&getEnergie(void);
	int	&getHitP(void);
	int	&getDamage(void);

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	~ClapTrap();
};
#endif //CPP_CLAPTRAP_HPP
