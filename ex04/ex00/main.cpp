//
// Created by Kevin Di nocera on 11/3/22.
//
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	std::string	input;

	while (1)
	{
		std::cout << std::endl;
		std::cout << "tap 1 => normal animals sound (cat, dog and animal)." << std::endl;
		std::cout << "tap 2 => wrong animals sound (cat)." << std::endl << std::endl;
		do
		{
			std::cout << "take your input: ";
			std::cin >> input;
			std::cout << std::endl;
		}
		while((input.empty()) && ((input.compare("1") != 0) ||
			(input.compare("2") != 0) || (input.compare("exit") != 0)));
		if (!input.compare("exit"))
		{
			std::cout << "you exit the program" << std::endl;
			break ;
		}
		if (!input.compare("2"))
		{
			const	WrongAnimal *WA = new WrongCat();

			std::cout << "call the type: " <<  WA->getType() << std::endl;
			WA->makeSound();
			delete WA;
		}
		else
		{
			const	Animal *meta = new Animal();
			const	Animal *j = new Dog();
			const	Animal *i = new Cat();
			std::cout << "call the type: " << j->getType() << " " << std::endl;
			std::cout << "call the type: " << i->getType() << " " << std::endl;
			i->makeSound(); //will output the cat sound!
			j->makeSound();
			meta->makeSound();
			std::cout << std::endl;
			delete	j;
			delete	i;
			delete	meta;
		}
	}
	return 0;
}