//
// Created by Kevin Di nocera on 11/29/22.
//

#ifndef CPP_SHRUBBERYCREATIONFORM_HPP
#define CPP_SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "ABureaucrat.hpp"
#include <fstream>
class	ShrubberyCreationForm : public AForm
{
private:
	std::string _target;
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(ShrubberyCreationForm const &src);

	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
	void	set_Target(std::string const &name);
	void 	executeAction(void) const;
	class GradeIsFalseException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	~ShrubberyCreationForm(void);
};
#endif //CPP_SHRUBBERYCREATIONFORM_HPP
