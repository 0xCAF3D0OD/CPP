//
// Created by Kevin Di nocera on 11/6/22.
//

#ifndef CPP_IMATERIA_HPP
#define CPP_IMATERIA_HPP
#include "Amateria.hpp"

class IMateriaSource
{
public:
	virtual void 		learnMateria(AMateria*) = 0;
	virtual AMateria	*createMateria(std::string const & type) = 0;

	virtual ~IMateriaSource() {}
};

#endif //CPP_IMATERIA_HPP
