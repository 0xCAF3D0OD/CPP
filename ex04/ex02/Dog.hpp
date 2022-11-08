//
// Created by Kevin Di nocera on 11/3/22.
//

#ifndef CPP_DOG_HPP
#define CPP_DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class	Dog : public AAnimal
{
private:
	std::string _type;
	Brain		*_brain;

public:
	Dog(void);
	Dog(Dog const &src);

	Dog	&operator=(Dog const &rhs);
	std::string	getType(void) const;
	void		makeSound(void) const;

	~Dog(void);
};

#endif //CPP_DOG_HPP
