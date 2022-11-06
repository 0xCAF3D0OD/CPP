//
// Created by Kevin Di nocera on 10/29/22.
//
#include "ClapTrap.hpp"

int	manageError(int args)
{
	if (isdigit(args))
	{
		std::cerr << "argument must be a digit." << std::endl;
		return (1);
	}
	else if ((args > 10) || (args < 0))
	{
		std::cerr << "digits must be equivalent or bigger to 0 "
		<<	"and equivalent or lesser to 10." << std::endl;
		return (1);
	}
	return (0);
}

int	manageEStr(std::string str)
{
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (str.find(str[i]) != std::string::npos)
		{
			std::cerr << "argument must be a array." << std::endl;
			return (1);
			break ;
		}
	}
	return (0);
}

int main(void)
{
	ClapTrap	nonSens("Hajar");
	ScavTrap	goodSens("Victor");
	int 		Repaired;
	int 		Damage;

//	{
//		ClapTrap blop = nonSens;
//		std::cout << "constr. blop called= " << std::endl;
//		std::cout << "constr. blop = " << blop.getName() << std::endl;
//	}
//	{
//		ClapTrap blop(nonSens);
//	}

	while (1)
	{
		std::cout << "1 argument is the the repaired input." << std::endl
		<< "2 argument is the damage input." << std::endl
		<< "3 argument is the name of the target" << std::endl;
		std::cout << "please enter a number less than 10 and equivalent to 0" << std::endl << std::endl;
		do
		{
			std::cout << "enter the Repaired input: ";
			std::cin >> Repaired;
			manageError(Repaired);
			std::cout << "enter the Damage input:	";
			std::cin >> Damage;
			manageError(Damage);
			std::cout << std::endl;
		}
		while ((!(Repaired)) || (!(Damage)));
		nonSens.takeDamage(Damage);
		nonSens.attack("Jerome");
		nonSens.beRepaired(Repaired);

		goodSens.attack("new comer");
		goodSens.guardGates();

		break ;
	}

	return (0);
}