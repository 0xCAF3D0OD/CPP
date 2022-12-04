//
// Created by dino on 27.09.22.
//
#include <iostream>
#include <string.h>

class	LessArguments : public std::exception
{
public:
	virtual const char *what(void) const throw();
};

class	voidArguments : public std::exception
{
public:
	virtual const char *what(void) const throw();
};

const char *LessArguments::what() const throw()
{
	return ("it must be two arguments\n");
}

const char *voidArguments::what() const throw()
{
	return ("it can't be void\n");
}

int manage_error(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw LessArguments();
		if (!av[1] || !av[0])
			throw voidArguments();
	}
	catch (LessArguments &exe)
	{
		std::cerr << exe.what() << std::endl;
		return (1);
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
	LessArguments	error;
	std::string 	args;
	int 			i;

	if (!manage_error(ac, av))
		args = av[1];
	i = -1;
	while (args[++i])
	{
		if (strcmp(&args[i], "\n"))
			std::cout << (char) toupper(args[i]);
		else if (!strcmp(&args[i], "\n"))
			std::cout << std::endl;
	}
	return (0);
}
