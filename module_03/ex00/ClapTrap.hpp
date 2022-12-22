//
// Created by Kevin Di nocera on 10/29/22.
//

#ifndef CPP_CLAPTRAP_HPP
#define CPP_CLAPTRAP_HPP

#include <iostream>
#include <string>
#include <cctype>

#define	BOLD_BLACK	"\033[1m\033[30m"
#define BOLD_RED	"\033[1m\033[31m"
#define BOLD_G		"\033[1m\033[32m"
#define	RESET   	"\033[0m"
#define BOLD_Y		"\033[1m\033[33m"
#define BOLD_W		"\033[1m\033[37m"

class	ClapTrap
{
private:
	std::string _name;
	int _HitPoint;
	int _EnergyPoint;
	int	_AttackDamage;

public:
	ClapTrap(void);
	ClapTrap(std::string const &name);
	ClapTrap(ClapTrap const &src);

	ClapTrap &operator=(const ClapTrap &rhs);

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
