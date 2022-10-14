//
// Created by Kevin Di nocera on 10/13/22.
//

#ifndef CPP_HUMANA_HPP
#define CPP_HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
	public:
		Weapon	type;
		void	attack();
		void	getName(std::string name);
};
#endif //CPP_HUMANA_HPP
