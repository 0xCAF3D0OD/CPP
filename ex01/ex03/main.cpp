//
// Created by Kevin Di nocera on 10/13/22.
//
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main (void)
{
	{
		Weapon club = Weapon("crude spiked club");

		HumanA Rene("René", club);
		Rene.attack();
		club.setType("some other type of club");
		Rene.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB Albert("Albert");
		Albert.setWeapon(club);
		Albert.attack();
		club.setType("some other type of club");
		Albert.attack();
	}
	return (0);
}
