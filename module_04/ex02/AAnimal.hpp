//
// Created by Kevin Di nocera on 11/3/22.
//

#ifndef CPP_BASE_CLASS_HPP
#define CPP_BASE_CLASS_HPP

#include <iostream>
#include <string>

#define	BOLD_BLACK	"\033[1m\033[30m"
#define BOLD_RED	"\033[1m\033[31m"
#define BOLD_G		"\033[1m\033[32m"
#define	RESET   	"\033[0m"
#define BOLD_Y		"\033[1m\033[33m"
#define BOLD_W		"\033[1m\033[37m"

class AAnimal
{
private:
	std::string _type;
public:
	AAnimal(void);
	AAnimal(AAnimal const &src);

	AAnimal	&operator=(AAnimal const &rhs);
	virtual	void 		makeSound(void) const = 0;
	virtual std::string getType(void) const;

	virtual ~AAnimal(void);
};
#endif //CPP_BASE_CLASS_HPP
