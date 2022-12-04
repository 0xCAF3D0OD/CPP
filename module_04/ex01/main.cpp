//
// Created by Kevin Di nocera on 11/3/22.
//

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {

	Animal	*list[100];

	for (int idx = 0; idx < 100; idx++)
	{
		if (idx < 50)
			list[idx] = new Dog();
		else if (idx < 100)
			list[idx] = new Cat();
	}
	for (int i = 0; i < 100; i++)
		delete list[i];

	return 0;
}