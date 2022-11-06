//
// Created by Kevin Di nocera on 11/3/22.
//

#ifndef CPP_CAT_HPP
#define CPP_CAT_HPP

#include "Animal.hpp"

class	Cat : public Animal
{
private:
	std::string type;
public:
	Cat(void);

	std::string	getType(void) const;
	void		makeSound(void) const;

	~Cat(void);
};
#endif //CPP_CAT_HPP
