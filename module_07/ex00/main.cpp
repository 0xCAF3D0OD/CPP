
#include "whatever.hpp"

int main(int ac, char **av)
{
	if (ac != 3)
	{
		std::cerr << "less arguments" << std::endl;
		return (1);
	}
	else if (std::isalpha(std::atoi(av[1]) || std::isalpha(std::atoi(av[2]))))
	{
		std::cerr << "letter are in the arguments" << std::endl;
		return (1);
	}
	whatever<float>	a(std::atof(av[1]), std::atof(av[2]));

	std::cout << "biggest => " << a.Max();

	return (0);
}