//
// Created by Kevin Di nocera on 12/16/22.
//

#include "Zombie.hpp"

int	main(int ac, char **av)
{
	if (ac != 3)
		exit(1);
	if (std::atoi(av[1]) <= 0)
		exit(1);
	Zombie *horde = zombieHorde(std::atoi(av[1]), av[2]);
	delete [] horde;
	return (0);
}