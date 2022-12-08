//
// Created by Kevin Di nocera on 11/6/22.
//

#include "Base.hpp"

class	A : public Base {};
class	B : public Base {};
class	C : public Base {};

Base	*generate(void)
{
	std::srand(time(NULL));

	int chance = rand() % 3;
	switch (chance)
	{
		case 0:
			return (new(A));
		case 1:
			return (new(B));
		case 2:
			return (new(C));
	}
	return (NULL);
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "the pointer point of A" << std::endl;
	if (dynamic_cast<B*>(p) != NULL)
		std::cout << "the pointer point of B" << std::endl;
	if (dynamic_cast<C*>(p) != NULL)
		std::cout << "the pointer point of C" << std::endl;
}

void	identify(Base &p)
{
	try {
		A &tmp = dynamic_cast<A&>(p);
		(void) tmp;
		std::cout << "The object referenced by p is A" << std::endl;
	}
	catch (...) {}
	try {
		B &tmp = dynamic_cast<B&>(p);
		(void) tmp;
		std::cout << "The object referenced by p is B" << std::endl;
	}
	catch (...) {}
	try {
		C &tmp = dynamic_cast<C&>(p);
		(void) tmp;
		std::cout << "The object referenced by p is C" << std::endl;
	}
	catch (...) {}
}

int main(void)
{
	Base	*new_c = generate();
	identify(new_c);
	identify(*new_c);
	delete (new_c);
	return (0);
}