#include "computorv1.h"

void	display_degree_0(t_data *d)
{
	if (d->lequ.m.c == d->requ.m.c)
	{
		ft_putstr("Reduced form: ");
		ft_adapt_putnbr(d->lequ.m.c);
		ft_putstr(" = ");
		ft_adapt_putnbr(d->requ.m.c);
		ft_putstr("\nPolynomial degree: 0\n");
		ft_putstr("All reals numbers are solution.\n");
	}
	else
	{
		ft_putstr("Reduced form: ");
		ft_adapt_putnbr(d->m.c);
		ft_putstr(" = 0");
		ft_putstr("\nPolynomial degree: 0\n");
		ft_putstr("No real number is solution.\n");
	}	
}