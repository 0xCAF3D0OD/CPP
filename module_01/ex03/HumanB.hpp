//
// Created by Kevin Di nocera on 10/13/22.
//

#ifndef CPP_HUMANB_HPP
#define CPP_HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string _name;
		Weapon		*_weapon;

	public:
		HumanB(std::string name);

		void	setWeapon(Weapon weapon);
		void	attack();

		~HumanB();
};
#endif //CPP_HUMANB_HPP
