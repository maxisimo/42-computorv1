#include "computorv1.h"

int		ft_error(int code, t_data *d)
{
	if (code == UNDEFINED_CHAR)
	{
		ft_putstr("Undefined char has been detected !\n");
		ft_putstr("Authorised chars : \"0123456789+-=^*.xX \"\n\n");
		ft_putstr("For more informations please refer to the README.md\n");
	}
	else if (code == UNDEFINED_POWER)
	{
		ft_putstr("Current monomial: ");
		ft_putstr(d->current_monomial);
		ft_putstr("\nUndefined power has been detected !\n");
		ft_putstr("Authorised power: 0 1 2, otherwise any numbers will be accept but I'll can't solve.\n\n");
		ft_putstr("For more informations please refer to the README.md\n");
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
	if (fabs(decimal) - fabs(n) == 0)
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

double	ft_adapt_atoi(char const *str)
{
	int		is_negative;
	size_t	i;
	double	integer;
	int		power;

	is_negative = 0;
	i = 0;
	integer = 0;
	power = -1;
	if (str[0] == 'x' || str[0] == 'X')
		return 1;
	if (str[0] == '-' && (str[1] == 'x' || str[1] == 'X'))
		return (-1);
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') \
		|| (str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		is_negative = 1;
	if (str[i] == '-' || str[i] == '+' || str[i] == '.')
		i++;
	while (str[i] && str[i] != '^')
	{
		if (str[i] == '.' && power == -1)
			power = 0;
		if (str[i] >= 48 && str[i] <= 57)
		{
			integer = integer * 10 + (str[i] - '0');
			if (power >= 0)
				power++;
		}
		i++;
	}
	if (is_negative)
		integer = integer * -1;
	if (power != -1)
		integer = integer / pow(10, power);
	return (integer);
}
