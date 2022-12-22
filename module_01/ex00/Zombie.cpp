#include "Zombie.hpp"

Zombie::Zombie(std::string name)
: _name(name)
{
	std::cout << this->_name << " constructor is called" << std::endl;
}

void	Zombie::announce() const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << ": have enough BraiiiiiiinnnzzzZ...!" << std::endl;
}
