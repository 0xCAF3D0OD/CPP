//
// Created by Kevin Di nocera on 10/20/22.
//
#include "sed.hpp"

void	manageError(std::string filename, std::string str1, std::string str2)
{
	if (filename.empty() || str1.empty() || str2.empty())
	{
		if (filename.empty())
			std::cerr << "filename is empty: " << filename << std::endl;
		else if (str1.empty())
			std::cerr << "str n. 1 is empty: " << str1 << std::endl;
		else if (str2.empty())
			std::cerr << "str n. 2 is empty: " << str2 << std::endl;
	}
}

std::string strReplace(std::string &line, std::string str1, std::string str2)
{
	size_t 			found = 0;

	found = line.find(str1);
	if (found != std::string::npos)
	{
		line.erase(found, str1.length());
		line.insert(found, str2);
	}
	else
		std::cout << "occurrence don't found !" << std::endl;
	while ((found = line.find(str1, found + 1)) != std::string::npos)
	{
		line.erase(found, str1.length());
		line.insert(found, str2);
	}
	return (line);
}

int	getSed(std::string filename, std::string str1, std::string str2)
{
	std::string 	line;
	std::ifstream	output(filename.c_str());
	std::ofstream 	input(filename + ".replace");

	manageError(filename, str1, str2);
	if (input && output)
	{
		while (std::getline(output, line))
		{
			if (line.empty() || str1.empty() || str2.empty())
				break ;
			line = strReplace(line, str1, str2);
			input << line << std::endl;
		}
	}
	return (0);
}

int main(int ac, char **av)
{
	std::cout << "hello everyone !" << std::endl << std::endl;
	if (ac <= 4)
	{
		std::cout << "you must put 3 arguments" << std::endl;
		std::cout << "1: the name of the file" << std::endl;
		std::cout << "2: the first string" << std::endl;
		std::cout << "3: the second string" << std::endl;
	}
	else
		getSed(av[1], av[2], av[3]);
	return (0);
}