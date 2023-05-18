#include <iostream>
#include <string.h>

class	voidArguments : public std::exception
{
public:
	virtual const char *what(void) const throw();
};

const char *voidArguments::what() const throw()
{
	return ("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
}

int manage_error(int ac)
{
	try
	{
		if (ac == 1)
			throw voidArguments();
	}
	catch (voidArguments &exe)
	{
		std::cerr << exe.what() << std::endl;
		return (1);
	}
	return (0);
}

int main(int ac, char **av)
{
	std::string 	args;

	if (!manage_error(ac)){}

	for (int i = 1; i < ac; i++)
	{
		for (int j = 0; j < (int)strlen(av[i]); j++) {

			if (!strcmp(&args[i], "\n"))
				std::cout << std::endl;
			std::cout << (char) toupper(av[i][j]);
		}
		if (av[i + 1] != NULL)
			std::cout << " ";
	}
	return (0);
}

// rm .git
