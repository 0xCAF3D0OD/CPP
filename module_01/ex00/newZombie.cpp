//
// Created by Kevin Di nocera on 12/16/22.
//

#include "Zombie.hpp"

Zombie  *newZombie(std::string name)
{
	return new Zombie(name);
}
