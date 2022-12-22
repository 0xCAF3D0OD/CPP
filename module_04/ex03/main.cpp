//
// Created by Kevin Di nocera on 11/3/22.
//

#include "Amateria.hpp"
#include "Icharacter.hpp"
#include "Imateria.hpp"

int main()
{
	IMateriaSource* src = new IMateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new ICharacter("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new ICharacter("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}