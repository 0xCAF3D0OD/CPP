#include "Zombie.hpp"

Zombie::Zombie(std::string name)
: _name(name) {}

void	Zombie::announce() const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << ": have enough BraiiiiiiinnnzzzZ...!" << std::endl;
}
