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
		std::cout << BOLD_Y << "⚬ tap 1 => normal animals sound (cat, dog and animal)." << std::endl;
		std::cout << "⚬ tap 2 => wrong animals sound (cat)." << RESET << std::endl << std::endl;

		std::cout << "- take your input: ";
		std::cin >> input;
		std::cout << std::endl;

		if (!input.compare("exit"))
		{
			std::cout << BOLD_RED << "⚬ you exit the program" << RESET << std::endl;
			break ;
		}
		if (!input.compare("2"))
		{
			const	WrongAnimal *WA = new WrongCat();

			std::cout << std::endl << BOLD_G << "⚬ call the type: " <<  WA->getType() << std::endl << std::endl;
			WA->makeSound();
			delete WA;
		}
		else if (input == "1")
		{
			const	Animal *meta = new Animal();
			const	Animal *j = new Dog();
			const	Animal *i = new Cat();
			std::cout << std::endl << BOLD_G << "⚬ call the type: " << j->getType() << " " << std::endl;
			std::cout << "⚬ call the type: " << i->getType() << " " << RESET << std::endl << std::endl;
			i->makeSound(); //will output the cat sound!
			j->makeSound();
			meta->makeSound();
			std::cout << std::endl;
			delete	j;
			delete	i;
			delete	meta;
		}
		else
		{
			std::cerr << std::endl << BOLD_RED << "🚫 Must be a digit, he must be 1 or 2"
			<< RESET << std::endl;
			exit(1);
		}
	}
	return 0;
}