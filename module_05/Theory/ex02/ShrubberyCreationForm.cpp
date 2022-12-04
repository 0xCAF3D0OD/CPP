//
// Created by Kevin Di nocera on 11/29/22.
//

#include "ShrubberyCreationForm.hpp"

const char *ShrubberyCreationForm::GradeIsFalseException::what() const throw()
{
	return (BOLD_RED, "wrong grade to display the beautiful tree\n");
}

ShrubberyCreationForm::ShrubberyCreationForm(void)
{
	std::cout << "constructor Shrubbery is called\n" << std::endl;
}

void	ShrubberyCreationForm::set_Target(std::string const &name)
{
	this->_target = name;
}

void ShrubberyCreationForm::executeAction(void) const
{
	std::ofstream file;
	file.open((this->_target + "_shrubbery").c_str());
	file << std::endl;
	file << "                                                         .\n"
			"                                              .         ;\n"
			"                 .              .              ;%     ;;\n"
			"                   ,           ,                :;%  %;\n"
			"                    :         ;                   :;%;'     .,\n"
			"           ,.        %;     %;            ;        %;'    ,;\n"
			"             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
			"              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
			"               ;%;      %;        ;%;        % ;%;  ,%;'\n"
			"                `%;.     ;%;     %;'         `;%%;.%;'\n"
			"                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
			"                    `:%;.  :;bd%;          %;@%;'\n"
			"                      `@%:.  :;%.         ;@@%;'\n"
			"                        `@%.  `;@%.      ;@@%;\n"
			"                          `@%%. `@%%    ;@@%;\n"
			"                            ;@%. :@%%  %@@%;\n"
			"                              %@bd%%%bd%%:;\n"
			"                                #@%%%%%:;;\n"
			"                                %@@%%%::;\n"
			"                                %@@@%(o);  . '\n"
			"                                %@@@o%;:(.,'\n"
			"                            `.. %@@@o%::;\n"
			"                               `)@@@o%::;\n"
			"                                %@@(o)::;\n"
			"                               .%@@@@%::;\n"
			"                               ;%@@@@%::;.\n"
			"                              ;%@@@@%%:;;;.\n"
			"                          ...;%@@@@@%%:;;;;,..    Gilo97\n" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
		:	AForm(src)
{
	std::cout << "constructor copy Shrubbery is called\n" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	_target = rhs._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "destructor Shrubbery is called\n" << std::endl;
}