//
// Created by Kevin Di nocera on 10/25/22.
//
#include <stdio.h>
#include <unistd.h>

int *ft_map(int *tab, int length, int (*f)(int))
{
	for (int i = 0; i <= length; i++)
		(*f)(tab[i] = i + 1);
	return (tab);
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
	int	length = 13;
	int	tab = (int *) malloc(sizeof (int *) * length);

	tab = ft_map(tab, length, &ft_putnbr);
	for (int i = 0; i <= length; i++)
		printf("%d\n", tab[i]);
	free(tab);
	return (0);
}