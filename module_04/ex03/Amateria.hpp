//
// Created by Kevin Di nocera on 11/6/22.
//

#ifndef CPP_AMATERIA_HPP
#define CPP_AMATERIA_HPP

#include <iostream>
#include <string>
#include "Icharacter.hpp"

class AMateria
{
protected:

public:
	AMateria(std::string const & type);

	std::string const 	&getType() const; //Returns the materia type
	virtual AMateria 	*clone() const = 0;
	virtual void 		use(ICharacter& target);

	~AMateria(void);
};

#endif //CPP_AMATERIA_HPP
