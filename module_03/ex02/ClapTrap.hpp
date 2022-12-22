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


	virtual ~ClapTrap();
};
#endif //CPP_CLAPTRAP_HPP
