//
// Created by Kevin Di nocera on 10/29/22.
//
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	manageEStr(std::string str)
{
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (str.find(str[i]) != std::string::npos)
		{
			std::cerr << "argument must be a array." << std::endl;
			return (1);
		}
	}
	return (0);
}

void	printError (std::string const &target, int const amount)
{
	if (amount == -1)
		std::cerr << std::endl << BOLD_RED << "🚫 " << target << " Must be a digit" << RESET << std::endl;
	else
		std::cerr << std::endl << BOLD_RED << "🚫 " << target << " Must be a digit, he must be bigger than 0 and less than "
				  << amount << RESET << std::endl;
	exit(1);
}

int main(void)
{
	ClapTrap	nonSens("Hajar");
	ScavTrap	goodSens("Victor");
	int 		Repaired = 0;
	int 		Damage = 0;
	int			idx = 0;
	std::string	exitP;
	bool 		bad = false;

	std::cout << BOLD_Y << "⚬ 1 argument is the the repaired input." << std::endl
			  << "⚬ 2 argument is the damage input." << std::endl
			  << "⚬ 3 argument is the name of the target" << RESET << std::endl << std::endl;
	while (1)
	{
		if (idx > 0)
			std::cout <<	"*--------------------------------------------* "<< idx << " turn *----------------------------------*\n";

		std::cout << std::endl << "❌ For exit the program tape exit or if you want to continue tape anything else : ";
		std::cin >> exitP;
		std::cout << std::endl;
		if (!strcmp(exitP.c_str(), "exit"))
			break ;

		std::cout << 		"*------------------------------------* Hajar aggression *-------------------------------*\n";
		std::cout << BOLD_W << "	⚬ Please enter a number less than 10 and bigger than 0" << RESET << std::endl << std::endl;

		std::cout << "	⚬ Enter the Repaired input for Hajar: ";
		std::cin >> Repaired;

		bad = std::cin.fail();
		if (bad)
			printError("repaired", -1);
		if (Repaired < 0 || Repaired > 10)
			printError("repaired", 10);

		std::cout << "	⚬ enter the Damage input: ";
		std::cin >> Damage;
		bad = std::cin.fail();
		if (bad)
			printError("repaired", -1);
		if (Damage < 0 || Damage > 10)
			printError("damage", 10);
		std::cout << std::endl;

		nonSens.takeDamage(Damage);
		nonSens.attack("Jerome");
		nonSens.beRepaired(Repaired);

		std::cout << std::endl << 		"*------------------------------------* Victor aggression *-------------------------------*\n";
		std::cout << BOLD_W << "	⚬ Please enter a number less than 100 and bigger than 0" << RESET << std::endl << std::endl;

		std::cout << "	⚬ Enter the Damage input for Victor: ";
		std::cin >> Damage;
		bad = std::cin.fail();
		if (bad)
			printError("repaired", -1);
		if (Damage < 0 || Damage > 100)
			printError("damage", 10);
		std::cout << std::endl;

		goodSens.takeDamage(Damage);
		goodSens.attack("newcomer");
		goodSens.guardGates();
		idx++;
	}
	return (0);
}
