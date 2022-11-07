//
// Created by Kevin Di nocera on 11/6/22.
//

#ifndef CPP_ICHARACTER_HPP
#define CPP_ICHARACTER_HPP

#include "Amateria.hpp"

class ICharacter
{
public:
	virtual std::string const	&getName() const = 0;
	virtual void 				equip(AMateria* m) = 0;
	virtual void 				unequip(int idx) = 0;
	virtual void 				use(int idx, ICharacter& target) = 0;

	virtual ~ICharacter() {}
};

#endif //CPP_ICHARACTER_HPP
