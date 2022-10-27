//
// Created by Kevin Di nocera on 10/24/22.
//

#include "Harl.hpp"

Karen::Karen()
{
	std::cout << "a Karen a appeared !! FIGHT" << std::endl;
}

Karen::~Karen()
{
	std::cout << "the Karen ran away !! you win" << std::endl;
}

int	manageError(int ac, std::string args)
{
	if (ac != 2)
	{
		if (ac > 2)
			std::cerr << "to many arguments !!" << std::endl;
		if (ac < 2)
			std::cerr << "less arguments !!" << std::endl;
		return (1);
	}
	if (args.empty())
	{
		std::cerr << "the arguments contain nothing!!" << std::endl;
		return (1);
	}
	return (0);
}

int main(int ac, char **av)
{
	Karen	karen;
	int		ret;
	std::string args;

	args = av[1];
	ret = manageError(ac, args);
	if (!ret)
	{
		karen.complain(args);
	}
	return (0);
}