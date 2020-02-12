#include "computorv1.h"

void	display_degree_0(t_data *d)
{
	d->degree = 0;

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
	d->degree = 1;

	if (d->lequ.m.b == d->requ.m.b)
	{
		if (d->lequ.m.c == d->requ.m.c)
		{
			ft_putstr("Reduced form: ");
			ft_adapt_putnbr(d->lequ.m.b);
			(d->lequ.m.c >= 0) ? ft_putstr("x + ") : ft_putstr("x - ");
			(d->lequ.m.c >= 0) ? ft_adapt_putnbr(d->lequ.m.c) : ft_adapt_putnbr(-d->lequ.m.c);
			ft_putstr(" = ");
			ft_adapt_putnbr(d->requ.m.b);
			(d->requ.m.c >= 0) ? ft_putstr("x + ") : ft_putstr("x - ");
			(d->requ.m.c >= 0) ? ft_adapt_putnbr(d->requ.m.c) : ft_adapt_putnbr(-d->requ.m.c);
			ft_putstr("\nPolynomial degree: 1\n");
			ft_putstr("All reals numbers are solution.\n");
		}
		else
			display_degree_0(d);
	}
	else
	{
		ft_putstr("Reduced form: ");
		if (d->lequ.m.c == d->requ.m.c)
		{
			if (d->m.b != 1 && d->m.b != -1)
				(d->m.b > 0) ? ft_adapt_putnbr(d->m.b) : ft_adapt_putnbr(-d->m.b);
			ft_putchar('x');
		}
		else
		{
			ft_adapt_putnbr(d->m.b);
			(d->m.c >= 0) ? ft_putstr("x + ") : ft_putstr("x - ");
			(d->m.c >= 0) ? ft_adapt_putnbr(d->m.c) : ft_adapt_putnbr(-d->m.c);
		}
		ft_putstr(" = 0\n");
		ft_putstr("Polynomial degree: 1\n");
		solve(d);
		ft_putstr("The solution is: ");
		ft_adapt_putnbr(d->result.x1);
		ft_putchar('\n');
	}
}

void	display_degree_2(t_data *d)
{
	d->degree = 2;

	if (d->lequ.m.a == d->requ.m.a)
	{
		if (d->lequ.m.b == d->requ.m.b)
		{
			if (d->lequ.m.c == d->requ.m.c)
			{
				ft_putstr("Reduced form: ");
				ft_adapt_putnbr(d->lequ.m.a);
				(d->lequ.m.b >= 0) ? ft_putstr("x^2 + ") : ft_putstr("x^2 - ");
				(d->lequ.m.b >= 0) ? ft_adapt_putnbr(d->lequ.m.b) : ft_adapt_putnbr(-d->lequ.m.b);
				(d->lequ.m.c >= 0) ? ft_putstr("x + ") : ft_putstr("x - ");
				(d->lequ.m.c >= 0) ? ft_adapt_putnbr(d->lequ.m.c) : ft_adapt_putnbr(-d->lequ.m.c);
				ft_putstr(" = ");
				ft_adapt_putnbr(d->requ.m.a);
				(d->requ.m.b >= 0) ? ft_putstr("x^2 + ") : ft_putstr("x^2 - ");
				(d->requ.m.b >= 0) ? ft_adapt_putnbr(d->requ.m.b) : ft_adapt_putnbr(-d->requ.m.b);
				(d->requ.m.c >= 0) ? ft_putstr("x + ") : ft_putstr("x - ");
				(d->requ.m.c >= 0) ? ft_adapt_putnbr(d->requ.m.c) : ft_adapt_putnbr(-d->requ.m.c);
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
		if (d->lequ.m.b == d->requ.m.b)
		{
			if (d->lequ.m.c == d->requ.m.c)
			{
				ft_adapt_putnbr(d->m.a);
				ft_putstr("x^2");
			}
			else
			{
				(d->m.a == 1) ? ft_adapt_putnbr(d->m.a) : 0;
				(d->m.c > 0) ? ft_putstr("x^2 + ") : ft_putstr("x^2 - ");
				ft_adapt_putnbr(d->m.c);
			}
		}
		else if (d->lequ.m.c == d->requ.m.c)
		{
			if (d->m.a != 1 && d->m.a != -1)
				ft_adapt_putnbr(d->m.a);
			if (d->m.a < 0)
				ft_putchar('-');
			(d->m.b > 0) ? ft_putstr("x^2 + ") : ft_putstr("x^2 - ");
			if (d->m.b != 1 && d->m.b != -1)
				(d->m.b > 0) ? ft_adapt_putnbr(d->m.b) : ft_adapt_putnbr(-d->m.b);
			ft_putchar('x');
		}
		else
		{
			ft_adapt_putnbr(d->m.a);
			(d->m.b > 0) ? ft_putstr("x^2 + ") : ft_putstr("x^2 - ");
			(d->m.b > 0) ? ft_adapt_putnbr(d->m.b) : ft_adapt_putnbr(-d->m.b);
			(d->m.c > 0) ? ft_putstr("x + ") : ft_putstr("x - ");
			(d->m.c > 0) ? ft_adapt_putnbr(d->m.c) : ft_adapt_putnbr(-d->m.c);
		}
		ft_putstr(" = 0\n");
		ft_putstr("Polynomial degree: 2\n");
		solve(d);
		if (d->delta > 0)
		{
			ft_putstr("Discriminant (");
			ft_adapt_putnbr(d->delta);
			ft_putstr(") is strictly positive, the two solutions are:\nx1: ");
			ft_adapt_putnbr(d->result.x1);
			ft_putstr("\nx2: ");
			ft_adapt_putnbr(d->result.x2);
		}
		else if (d->delta < 0)
		{
			ft_putstr("Discriminant is strictly negative, the solution is:\n");
			ft_adapt_putnbr(d->result.x1);
		}
	}
}
