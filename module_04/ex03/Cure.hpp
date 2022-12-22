//
// Created by Kevin Di nocera on 11/6/22.
//

#ifndef CPP_CURE_H
#define CPP_CURE_H

#include "Amateria.hpp"

class	Cure
{
private:
	std::string clon;
public:
	Cure(void);
	Cure(Cure const &src);

	Cure		&operator=(Cure const &rhs);
	std::string	clone(void);
	ICharacter	use(ICharacter const &str);

	~Cure(void);
};
#endif //CPP_CURE_H
