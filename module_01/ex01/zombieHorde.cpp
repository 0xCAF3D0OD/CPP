//
// Created by Kevin Di nocera on 12/16/22.
//

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string set_name)
{
	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		horde[i].setName(set_name);
		horde[i].announce();
	}
	return (horde);
}