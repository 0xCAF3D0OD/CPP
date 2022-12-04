//
// Created by Kevin Di nocera on 11/1/22.
//
#include <iostream>
#include <string>

/*	Virtual => transforme the function from static to dynamic.
 *
 * */
class	Character
{
public:
	virtual void	sayHello(std::string const &target);
};

// heritage -> : public Character
class	Warrior	: public Character
{
public:
	virtual void	sayHello(std::string const &target);
};

class Cat
{
	//[...]
};

void	Character::sayHello(const std::string &target)
{
	std::cout << target << " say hello!" << std::endl;
}

void	Warrior::sayHello(const std::string &target)
{
	std::cout << target << " say fuck off" << std::endl;
}

int main(void)
{
	/* it's ok, Warrior is a from the class Warrior*/
	Character	*Chara = new Warrior();
	/* it's also ok, Warrior is also from the class Character => child*/
	Warrior		*Ben = new Warrior();

//	Chara.sayHello("chiara");
//	Ben.sayHello("Ben");

	return (0);
}