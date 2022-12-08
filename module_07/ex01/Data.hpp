//
// Created by Kevin Di nocera on 12/7/22.
//

#ifndef CPP_DATA_HPP
#define CPP_DATA_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

#define	BOLD_BLACK	"\033[1m\033[30m"
#define BOLD_RED	"\033[1m\033[31m"
#define BOLD_G		"\033[1m\033[32m"
#define	RESET   	"\033[0m"
#define BOLD_Y		"\033[1m\033[33m"

class	Data
{
private:
	int	_i;
	double _flt;

public:
	Data(void);
	Data(int i, float flt);
	Data(Data const &src);

	Data &operator=(Data const &rhs);

	uintptr_t serialize(Data* ptr);
	Data* deserialize(uintptr_t raw);

	int		get_i(void);
	double 	get_flt(void);

	virtual ~Data(void);
};
#endif //CPP_DATA_HPP
