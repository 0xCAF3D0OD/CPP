//
// Created by Kevin Di nocera on 10/25/22.
//
#include <unistd.h>
#include <stdio.h>

int fct(char c, char *str)
{
	printf("%c\n", c);
	printf("%s\n", str);
	return (0);
}

int main(void)
{
	int (*ptr)(char, char *);

	ptr = &fct;
	(*ptr)('c', "str");
	printf("%p\n", fct);
	printf("%p\n", ptr);
	return (0);
}