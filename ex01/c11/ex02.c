//
// Created by Kevin Di nocera on 10/25/22.
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_any(char **tab, int(*f)(char*))
{
	for(int i = 0; tab[i] != NULL; i++)
	{
		if ((*f)(tab[i]) != 0)
			return (1);
	}
	return (0);
}

int ft_check(char *tab)
{
	for (int i = 0; tab[i]; i++)
	{
		if (atoi(tab) == 0)
			return (1);
		return (0);
	}
	return (0);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_putnbr(int n)
{
	if (n < 0)
	{
		printf("-");
		n -= n;
	}
	else if (n / 10 != 0)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
	return (n);
}

int main(void)
{
	char **tab;
	int h = 10;
	int	rand_num = 0;
	int length = 10;

	tab = (char **) malloc(sizeof (char **) * h);
	for (int i = 0; i <= h; i++)
	{
		if (i == h)
		{
			i = 0;
			break ;
		}
		tab[i] = (char *) malloc(sizeof (char *) * length);
		rand_num = rand()%100;
		tab[i] = ft_putnbr(rand_num);
	}
	ft_any(tab, &ft_check);
	return (0);
}