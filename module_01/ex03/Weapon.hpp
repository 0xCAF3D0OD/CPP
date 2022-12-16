//
// Created by Kevin Di nocera on 10/13/22.
//

#ifndef CPP_WEAPON_HPP
#define CPP_WEAPON_HPP

#include <iostream>
#include <string>

class	Weapon
{
	private:
		std::string _type;

	public:
		Weapon(std::string type);

		std::string	getType(void);
		void		setType(std::string type);

		~Weapon(void);
};


#endif //CPP_WEAPON_HPP
