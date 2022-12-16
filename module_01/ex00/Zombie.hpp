//
// Created by Kevin Di nocera on 10/12/22.
//

#ifndef CPP_ZOMBIE_HPP
#define CPP_ZOMBIE_HPP

#include <iostream>
#include <string>

class	Zombie
{
	private:
		std::string _name;
	public:
		Zombie(std::string name);
		void announce(void) const;
		~Zombie();
};

Zombie  *newZombie(std::string name);
void randomChump(std::string name);

#endif //CPP_ZOMBIE_HPP
