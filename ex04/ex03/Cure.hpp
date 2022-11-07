//
// Created by Kevin Di nocera on 11/6/22.
//

#ifndef CPP_CURE_H
#define CPP_CURE_H

#include "Amateria.hpp"

class	cure
{
private:
	std::string clon;
public:
	cure(void);
	cure(cure const &src);

	cure	&operator=(cure const &rhs);
	std::string	clone(void);
	ICharacter	use(ICharacter const &str);

	~cure(void);
};
#endif //CPP_CURE_H
