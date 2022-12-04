//
// Created by Kevin Di nocera on 11/29/22.
//
#include "AForm.hpp"
#include "Bureaucrat.hpp"

#ifndef CPP_PRESIDENTIALPARDONFORM_HPP
#define CPP_PRESIDENTIALPARDONFORM_HPP

class	PresidentialPardonForm : public AForm
{
private:
	std::string _target;
public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string const &name, int const &execGrade, int const &signGrade);
	PresidentialPardonForm(PresidentialPardonForm const &src);

	PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);
	void	set_Target(std::string const &name);
	void	cmp_grade(void);

	void	executeAction(void) const;
	class GradeIsFalseException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	~PresidentialPardonForm(void);
};
#endif //CPP_PRESIDENTIALPARDONFORM_HPP
