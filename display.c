#include "computorv1.h"

void	display_degree_0(t_data *d)
{
	if (d->lequ.m.c == d->requ.m.c)
	{
		ft_putstr("Reduced form: ");
		ft_adapt_putnbr(d->lequ.m.c);
		ft_putstr(" * x^0 = ");
		ft_adapt_putnbr(d->requ.m.c);
		ft_putstr(" * x^0\n");
		ft_putstr("Polynomial degree: 0\n");
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

void	display_degree_1(t_data *d)
{
	if (d->lequ.m.b == d->requ.m.b)
	{
		if (d->lequ.m.c == d->requ.m.c)
		{
			ft_putstr("Reduced form: ");
			ft_adapt_putnbr(d->lequ.m.b);
			ft_putstr("x + ");
			ft_adapt_putnbr(d->lequ.m.c);
			ft_putstr(" = ");
			ft_adapt_putnbr(d->requ.m.b);
			ft_putstr("x + ");
			ft_adapt_putnbr(d->requ.m.c);
			ft_putstr("\nPolynomial degree: 1\n");
			ft_putstr("All reals numbers are solution.\n");
		}
		else
			display_degree_0(d);
	}
	else
	{
		ft_putstr("Reduced form: ");
		ft_adapt_putnbr(d->m.b);
		ft_putstr("x + ");
		ft_adapt_putnbr(d->m.c);
		ft_putstr(" = 0\n");
		ft_putstr("Polynomial degree: 1\n");
		// call solve degree 1
	}
}

void	display_degree_2(t_data *d)
{
	if (d->lequ.m.a == d->requ.m.a)
	{
		if (d->lequ.m.b == d->requ.m.b)
		{
			if (d->lequ.m.c == d->requ.m.c)
			{
				ft_putstr("Reduced form: ");
				ft_adapt_putnbr(d->lequ.m.a);
				ft_putstr("x^2 + ");
				ft_adapt_putnbr(d->lequ.m.b);
				ft_putstr("x + ");
				ft_adapt_putnbr(d->lequ.m.c);
				ft_putstr(" = ");
				ft_adapt_putnbr(d->requ.m.a);
				ft_putstr("x^2 + ");
				ft_adapt_putnbr(d->requ.m.b);
				ft_putstr("x + ");
				ft_adapt_putnbr(d->requ.m.c);
				ft_putstr("\nPolynomial degree: 2\n");
				ft_putstr("All reals numbers are solution.\n");
			}
			else
				display_degree_0(d);
		}
		else
			display_degree_1(d);
	}
	else
	{
		ft_putstr("Reduced form: ");
		ft_adapt_putnbr(d->m.a);
		ft_putstr("x^2 + ");
		ft_adapt_putnbr(d->m.b);
		ft_putstr("x + ");
		ft_adapt_putnbr(d->m.c);
		ft_putstr(" = 0\n");
		ft_putstr("Polynomial degree: 2\n");
		// call solve degree 2
	}
}
