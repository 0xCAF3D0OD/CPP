//
// Created by Kevin Di nocera on 11/7/22.
//

#ifndef CPP_ITER_HPP
#define CPP_ITER_HPP

#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>

#define	BOLD_BLACK	"\033[1m\033[30m"
#define BOLD_RED	"\033[1m\033[31m"
#define BOLD_G		"\033[1m\033[32m"
#define	RESET   	"\033[0m"
#define BOLD_Y		"\033[1m\033[33m"

template< typename T >
//void	Iter(T array, size_t arr_len, void (*foo)(T &))
//{
//	if (array == NULL || foo == NULL)
//		return ;
//	for (size_t i = 0; i < arr_len; i++)
//		foo(array[i]);
//}
//template <typename T>
void Iter (T *tab, std::size_t tab_size, void (*function)(T&)) {

	if (tab == NULL || function == NULL)
		return ;
	for (std::size_t i = 0; i <= tab_size; i++)
		function(tab[i]);
}

#endif //CPP_ITER_HPP