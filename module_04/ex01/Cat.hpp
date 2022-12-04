//
// Created by Kevin Di nocera on 11/3/22.
//

#ifndef CPP_CAT_HPP
#define CPP_CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal
{
private:
	std::string	_type;
	Brain		*_brain;
public:
	Cat(void);
	Cat(Cat const &src);

	Cat	&operator=(Cat const &rhs);
	std::string	getType(void) const;
	void		makeSound(void) const;

	~Cat(void);
};
#endif //CPP_CAT_HPP
