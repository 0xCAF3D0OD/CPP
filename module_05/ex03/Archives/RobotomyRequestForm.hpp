//
// Created by Kevin Di nocera on 11/29/22.
//
#include "AForm.hpp"
#include "Bureaucrat.hpp"

#ifndef CPP_ROBOTOMYREQUESTFORM_HPP
#define CPP_ROBOTOMYREQUESTFORM_HPP

class RobotomyRequestForm  : public AForm
{
private:
	std::string _target;
public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(std::string const &name, int const &execGrade, int const &signGrade);
	RobotomyRequestForm(RobotomyRequestForm const &src);

	RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
	void	set_Target(std::string const &name);
	void	cmp_grade_time(void);

	void	executeAction(void) const;

	class RandomFalseException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class RandomRandException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	~RobotomyRequestForm(void);
};

#endif //CPP_ROBOTOMYREQUESTFORM_HPP
