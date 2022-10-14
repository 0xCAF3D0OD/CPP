//
// Created by Kevin Di nocera on 10/13/22.
//

#ifndef CPP_WEAPON_HPP
#define CPP_WEAPON_HPP

#include <iostream>
#include "HumanA.hpp"
#include "HumanB.hpp"

class	Weapon
{
	private:
		std::string type;
	public:
		std::string getType();
		void		setType();
};


#endif //CPP_WEAPON_HPP
