//
// Created by Kevin Di nocera on 12/4/22.
//

#ifndef CPP_INTERN_HPP
#define CPP_INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class	Intern
{
private:
	typedef struct	s_forms
	{
		std::string	_name;
		AForm		*_formClass;
	} 				t_forms;

public:
	Intern(void);
	Intern(Intern const &src);

//	Intern	&operator=(Intern const &rhs);
	AForm	*makeForm(std::string const &formName, std::string const &formTarget);

	~Intern(void);
};
#endif //CPP_INTERN_HPP
