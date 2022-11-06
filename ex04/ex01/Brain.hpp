//
// Created by Kevin Di nocera on 11/3/22.
//

#ifndef CPP_BRAIN_HPP
#define CPP_BRAIN_HPP

#include "Animal.hpp"

class	Brain : public Animal
{
private:
	std::string ideas[100];
public:
	Brain(void);
	Brain(Brain const &src);

	Brain	&operator=(Brain const &rhs);
	std::string	getidea(void) const;
	void		makeSound(void) const;

	~Brain(void);
};
#endif //CPP_BRAIN_HPP
