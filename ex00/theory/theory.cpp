//
// Created by Kevin Di nocera on 11/6/22.
//
/*	Reference =>	is a constant pointer who is always dereferenced and never NULL.
 *
 * */
#include <iostream>

/* exemple
 * int main(void)
{
	int	numberOfBalls = 42;

	int	*ballsPtr = &numberOfBalls;
	int	&ballsRef = numberOfBalls;

	std::cout << numberOfBalls << " " << *ballsPtr << " " << ballsRef << std::endl;

	*ballsPtr = 21;
	std::cout << numberOfBalls << std::endl;
	ballsRef = 84;
	std::cout << numberOfBalls << std::endl;
	return (0);
}

void	byPtr(std::string *str)
{
	*str += " and ponies";
}

void	byConstPtr(std::string const *str)
{
	std::cout << *str << std::endl;
}

void	byRef(std::string &str)
{
	str += " and ponies ";
}

void byConstRef(std::string const &str)
{
	std::cout << str << std::endl;
}

int main(void)
{
	std::string str = "i like butterflies";

	std::cout << str << std::endl;
	byPtr(&str);
	byConstPtr(&str);

	str = "i like otters";

	std::cout << str << std::endl;
	byRef(str);
	byConstRef(str);

	return (0);
}
 */