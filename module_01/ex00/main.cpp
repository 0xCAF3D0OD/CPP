//
// Created by Kevin Di nocera on 12/16/22.
//

#include "Zombie.hpp"

int main (void)
{
	Zombie *albert = newZombie("albert");
	albert->announce();
	randomChump("anne-lise");
	delete albert;
	return (0);
}