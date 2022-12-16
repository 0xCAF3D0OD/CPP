
#include "easyfind.hpp"

const char *noOccurence::what() const throw()
{
	return ("no occurrence found\n");
}

const char *wrongArgs::what() const throw()
{
	return ("Less args\n");
}

const char *occurence::what() const throw()
{
	return ("bravo you found the occurrence\n");
}

int main (int ac, char **av)
{
	std::vector<int>p;
	try
	{
		if (!ac)
			throw wrongArgs();
		int len = ac;
		int	input = 0;
		for (int i = 0; i < len; i++)
			p.push_back(atoi(av[i]));
		while(1)
		{
			std::cout << "put your check number:	";
			std::cin >> input;
			if (!easyfind(p, input))
				throw noOccurence();
			else
				throw occurence();
		}

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "Les pommes de terre c racist\n";
	return (0);
}