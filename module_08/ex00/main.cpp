
#include "easyfind.hpp"

const char *noOccurence::what() const throw()
{
	return (BOLD_RED "\n✘ no occurrence found\n" RESET);
}

const char *wrongArgs::what() const throw()
{
	return (BOLD_RED "\n✘ Less args -> please put minimum 2 digits\n" RESET);
}

const char *occurence::what() const throw()
{
	return (BOLD_G "\n✔︎ bravo you found the occurrence\n" RESET);
}

int main (int ac, char **av)
{
	std::vector<int>p;

	try
	{
		if (ac < 2)
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
	return (0);
}
//template <typename T>
//void	displayIterator( T it, T end )
//{
//	if (it != end)
//		std::cout << "iterator: " << *it << std::endl;
//	else
//		std::cout << "iterator reached the end of container" << std::endl;
//}
//
//int	main( void )
//{
//	std::vector<int>			vect;
//	std::vector<int>::iterator	it;
//
//	for (int i = 1; i < 59; i += 2)
//		vect.push_back(i);
//	it = easyfind(vect, 43);
//	displayIterator(it, vect.end());
//	it = easyfind(vect, 42);
//	displayIterator(it, vect.end());
//	return (0);
//}
