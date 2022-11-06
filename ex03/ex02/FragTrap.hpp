//
// Created by Kevin Di nocera on 11/1/22.
//

#ifndef CPP_FRAGTRAP_HPP
#define CPP_FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
public:
	FragTrap(std::string const &name);
	FragTrap(FragTrap const &src);

	FragTrap &operator=(FragTrap const &rhs);

	void	attack(const std::string &target);
	void 	highFivesGuys(void);
	~FragTrap();
};
#endif //CPP_FRAGTRAP_HPP
