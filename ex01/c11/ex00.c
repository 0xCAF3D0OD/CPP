//
// Created by Kevin Di nocera on 10/25/22.
//
#include <stdio.h>
#include <unistd.h>

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i = 0;

	while (i < length)
	{
		f(tab[i++]);
		printf("\n");
	}
}
void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int n)
{
	if (n < 0)
	{
		printf("-");
		n -= n;
	}
	else if (n / 10 != 0)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

void	vaTeFF(int n)
{
	printf("before %d\n", n);
	n += n * 12;

}

int main(void)
{
	int length = 12;
	int tab[length];

	for (int i = 0; i <= length; i++)
		tab[i] = i + 1;
	ft_foreach(tab, length, &ft_putnbr);
	return (0);
}