//
// Created by Kevin Di nocera on 10/13/22.
//

#ifndef CPP_HUMANA_HPP
#define CPP_HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string _name;
		Weapon		&_weapon;

	public:
		HumanA(std::string name, Weapon &weapon);

		void	attack();

		~HumanA();
};
#endif //CPP_HUMANA_HPP
