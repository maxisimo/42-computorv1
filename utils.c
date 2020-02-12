#include "computorv1.h"

int		ft_error(int code, t_data *d)
{
	if (code == UNDEFINED_CHAR)
	{
		ft_putstr("Undefined char has been detected !\n");
		ft_putstr("Authorised chars : \"0123456789+-=^*.xX \"\n\n");
		ft_putstr("For more informations please enter : ./computorv1 -h\n");
	}
	else if (code >= 3)
	{
		ft_putstr("Current monomial: ");
		ft_putstr(d->current_monomial);
		ft_putstr("\n\nPolynomial degree: ");
		ft_putnbr(code);
		ft_putstr("\nThe polynomial degree is stricly greater than 2, I can't solve.\n");
	}
	exit(-1);
}

void	ft_adapt_putnbr(float n)
{
	long	nb;
	long	dec;
	int		tab[30];
	int		tab2[30];
	int		i;
	int		j;
	float	decimal;

	i = 0;
	decimal = (n >= 0) ? n - (int)n : -(n - (int)n);
	decimal *= 10e6;
	n *= 10e6;
	dec = (int)decimal;
	nb = (int)n;
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (decimal - n == 0)
		ft_putchar('0');
	while (nb != 0)
	{
		tab[i] = nb % 10;
		nb = nb / 10;
		i++;
	}
	while (i > 7)
	{
		i--;
		ft_putchar(tab[i] + '0');
	}
	if (dec != 0)
	{
		ft_putchar('.');
		j = 0;
		while (dec != 0)
		{
			tab2[j] = dec % 10;
			dec = dec / 10;
			j++;
		}
		while (j > 0)
		{
			j--;
			ft_putchar(tab2[j] + '0');
		}
	}
}
