//
// Created by Kevin Di nocera on 10/13/22.
//
#include "Zombie.hpp"

Zombie::Zombie()
{}

Zombie::~Zombie()
{
	std::cout << this->name << ": have enough BraiiiiiiinnnzzzZ...!" << std::endl;
}

void	Zombie::announce() const
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::setName(std::string name)
{
	this->name = name;
	return (this->name);
}

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

int	main(void)
{
	Zombie *horde = zombieHorde(5, "Albert");
	delete [] horde;
	return (0);
}