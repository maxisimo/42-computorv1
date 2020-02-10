#include "computorv1.h"

int		ft_error(int code)
{
	if (code == UNDEFINED_CHAR)
	{
		ft_putstr("Undefined char has been detected !\n");
		ft_putstr("Authorised chars : \"0123456789+-=^*.xX \"\n\n");
		ft_putstr("For more informations please enter : ./computorv1 -h\n");
	}
	else if (code == UPPER_DEGREE)
	{
		ft_putstr("Polynomial degree is greater than 10 !\n");
		ft_putstr("Please use a degree smaller than 2.");
	}
	else if (code >= 3 && 9 >= code)
	{
		ft_putstr("Polynomial degree: ");
		ft_putnbr(code);
		ft_putstr("\nThe polynomial degree is stricly greater than 2, I can't solve.\n");
	}
	exit(-1);
}

void	ft_adapt_putnbr(float n)
{
	long	nb;
	int		tab[30];
	int		i;
	int		precision;

	i = 0;
	n = n * 10e6;
	nb = (int)n;
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	while (nb != 0)
	{
		tab[i] = nb % 10;
		nb = nb / 10;
		i++;
	}
	while (i > 0)
	{
		i--;
		precision = i - 6;
		if (precision == 0)
			ft_putchar('.');
		if (precision > -2)
			ft_putchar(tab[i] + '0');
		precision--;
	}
}
