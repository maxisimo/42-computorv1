#include "computorv1.h"

void	display_equalities(t_data *d)
{
	if (d->degree == 0)
	{
		ft_adapt_putnbr(d->lequ.m.c);
		ft_putstr("x^0");
	}
	else if (d->degree == 1)
	{
		if (d->lequ.m.b == -1)
			ft_putchar('-');
		if (d->lequ.m.b != 1 && d->lequ.m.b != -1)
			ft_adapt_putnbr(d->lequ.m.b);
		if (d->lequ.m.c == 0)
			ft_putchar('x');
		else
			(d->lequ.m.c > 0) ? ft_adapt_putstr("x + ", d->lequ.m.c) : ft_adapt_putstr("x - ", -d->lequ.m.c);
	}
	else
	{
		if (d->m.a == -1)
			ft_putchar('-');
		if (d->m.a != 1 && d->m.a != -1)
			ft_adapt_putnbr(d->m.a);
		if (d->lequ.m.b != 0)
		{
			if (d->lequ.m.c != 0)
			{
				(d->lequ.m.b > 0) ? ft_adapt_putstr("x^2 + ", d->lequ.m.b) : ft_adapt_putstr("x^2 - ", -d->lequ.m.b);
				(d->lequ.m.c > 0) ? ft_adapt_putstr("x + ", d->lequ.m.c) : ft_adapt_putstr("x - ", -d->lequ.m.c);
			}
			else
				(d->lequ.m.c > 0) ? ft_adapt_putstr("x^2 + ", d->lequ.m.c) : ft_adapt_putstr("x^2 - ", -d->lequ.m.c);
		}
		else
			(d->lequ.m.b > 0) ? ft_adapt_putstr("x^2 + ", d->lequ.m.b) : ft_adapt_putstr("x^2 - ", -d->lequ.m.b);
	}
	d->degree = 0;
}

void	display_solution(t_data *d)
{
	solve(d);
	if (d->degree == 1)
	{
		ft_adapt_putstr("The solution is: ", d->result.x1);
		ft_putchar('\n');
	}
	else if (d->degree == 2)
	{
		if (d->delta > 0)
		{
			ft_putstr("Discriminant: b^2 - 4ac = ");
			ft_adapt_putnbr(d->delta);
			ft_putstr("\nIt is strictly positive, the two solutions are:\nx1: ");
			ft_adapt_putnbr(d->result.x1);
			ft_putstr("\nx2: ");
			ft_adapt_putnbr(d->result.x2);
		}
		else if (d->delta == 0)
		{
			ft_putstr("Discriminant is strictly equal to 0, the solution is:\n");
			ft_adapt_putnbr(d->result.x1);
		}
		else if (d->delta < 0)
		{
			ft_adapt_putstr("Discriminant: b^2 - 4ac = ", d->delta);
			ft_putstr("\nIt is strictly negative, the two solution are:\nx1: ");
			if (d->square - (int)d->square == 0)
			{
				d->square /= d->denominator;
				if (d->m.b == 0)
				{
					if (-d->square == -1)
						ft_putchar('-');
					if (d->square != 1 && d->square != -1)
						ft_adapt_putnbr(-d->square);
					ft_putstr("i\nx2: ");
					if (d->square < 0)
						ft_putchar('-');
				}
				else
				{
					ft_adapt_putnbr(d->result.x1);
					(-d->square > 0) ? ft_putstr(" + ") : ft_putstr(" - ");
					if (d->square != 1 && d->square != -1)
						ft_adapt_putnbr(abs(d->square));
					ft_putstr("i\nx2: ");
					ft_adapt_putnbr(d->result.x2);
					(d->square > 0) ? ft_putstr(" + ") : ft_putstr(" - ");
				}
				if (d->square != 1 && d->square != -1)
					ft_adapt_putnbr(abs(d->square));
				ft_putstr("i\n");
			}
			else
			{
				ft_adapt_putnbr(-d->m.b);
				ft_adapt_putstr(" - sqrt(", -d->delta);
				ft_adapt_putstr(")i / ", d->denominator);
				ft_putstr("\nx2: ");
				ft_adapt_putnbr(-d->m.b);
				ft_adapt_putstr(" + sqrt(", -d->delta);
				ft_adapt_putstr(")i / ", d->denominator);
				ft_putchar('\n');
			}
		}
	}
}

void	display_degree_0(t_data *d)
{
	d->degree = 0;

	ft_putstr("Reduced form: ");
	if (d->lequ.m.c == d->requ.m.c)
	{
		display_equalities(d);
		ft_putstr(" = ");
		display_equalities(d);
		ft_putstr("\nPolynomial degree: 0\n");
		ft_putstr("All reals numbers are solution.\n");
	}
	else
	{
		ft_adapt_putnbr(d->m.c);
		ft_putstr(" = 0");
		ft_putstr("\nPolynomial degree: 0\n");
		ft_putstr("No real number is solution.\n");
	}	
}

void	display_degree_1(t_data *d)
{
	d->degree = 1;

	if (d->m.b == 0)
		display_degree_0(d);
	else if (d->m.b != 0 && d->lequ.m.b == d->requ.m.b)
	{
		if (d->lequ.m.c == d->requ.m.c)
		{
			ft_putstr("Reduced form: ");
			display_equalities(d);
			ft_putstr(" = ");
			display_equalities(d);
			ft_putstr("\nPolynomial degree: 1\n");
			ft_putstr("All reals numbers are solution.\n");
		}
		else
			display_degree_0(d);
	}
	else
	{
		(d->m.b == -1) ? ft_putstr("Reduced form: -") : ft_putstr("Reduced form: ");
		if (d->m.b != 1 && d->m.b != -1)
			ft_adapt_putnbr(d->m.b);
		if (d->lequ.m.c == d->requ.m.c)
			ft_putchar('x');
		else
			(d->m.c >= 0) ? ft_adapt_putstr("x + ", d->m.c) : ft_adapt_putstr("x - ", -d->m.c);
		ft_putstr(" = 0\n");
		ft_putstr("Polynomial degree: 1\n");
		display_solution(d);
	}
}

void	display_degree_2(t_data *d)
{
	d->degree = 2;

	if (d->m.a == 0)
		display_degree_1(d);
	else if (d->m.a != 0 && d->lequ.m.a == d->requ.m.a)
	{
		if (d->lequ.m.b == d->requ.m.b)
		{
			if (d->lequ.m.c == d->requ.m.c)
			{
				ft_putstr("Reduced form: ");
				display_equalities(d);
				ft_putstr(" = ");
				display_equalities(d);
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
		if (d->m.a == -1)
			ft_putchar('-');
		if (d->m.a != 1 && d->m.a != -1)
			ft_adapt_putnbr(d->m.a);
		if (d->lequ.m.b == d->requ.m.b)
		{
			if (d->lequ.m.c == d->requ.m.c)
				ft_putstr("x^2");
			else
				(d->m.c > 0) ? ft_adapt_putstr("x^2 + ", d->m.c) : ft_adapt_putstr("x^2 - ", -d->m.c);
		}
		else if (d->lequ.m.c == d->requ.m.c)
		{
			(d->m.b > 0) ? ft_putstr("x^2 + ") : ft_putstr("x^2 - ");
			if (d->m.b != 1 && d->m.b != -1)
				(d->m.b > 0) ? ft_adapt_putnbr(d->m.b) : ft_adapt_putnbr(-d->m.b);
			ft_putchar('x');
		}
		else
		{
			(d->m.b > 0) ? ft_putstr("x^2 + ") : ft_putstr("x^2 - ");
			if (d->m.b != 1 && d->m.b != -1)
				(d->m.b > 0) ? ft_adapt_putnbr(d->m.b) : ft_adapt_putnbr(-d->m.b);
			(d->m.c > 0) ? ft_adapt_putstr("x + ", d->m.c) : ft_adapt_putstr("x - ", -d->m.c);
		}
		ft_putstr(" = 0\n");
		ft_putstr("Polynomial degree: 2\n");
		display_solution(d);
	}
}
