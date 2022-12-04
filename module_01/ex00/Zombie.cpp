#include "Zombie.hpp"

Zombie::Zombie(std::string name)
: name(name) {}

Zombie::~Zombie()
{
	std::cout << this->name << ": have enough BraiiiiiiinnnzzzZ...!" << std::endl;
}

void	Zombie::announce() const
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie  *newZombie(std::string name)
{
	return new Zombie(name);
}

void	randomChump(std::string name)
{
	Zombie anne = name;
	anne.announce();
}

int main (void)
{
	Zombie *albert = newZombie("albert");
	albert->announce();
	randomChump("anne-lise");
	delete albert;
	return (0);
}