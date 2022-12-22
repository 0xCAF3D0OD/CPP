//
// Created by Kevin Di nocera on 10/30/22.
//

#ifndef CPP_SCAVTRAP_HPP
#define CPP_SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(std::string const &name);
	ScavTrap(ScavTrap const &src);

	ScavTrap &operator=(ScavTrap const &rhs);

	void	takeDamage(unsigned int amount);
	void	attack(const std::string &target);
	void	guardGates();

	~ScavTrap();
};
#endif //CPP_SCAVTRAP_HPP
