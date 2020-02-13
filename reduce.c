#include "computorv1.h"

int		identify_left_monomes(t_data *d, int i, int j)
{
	while (d->lequ.tab[i])
	{
		d->current_monomial = d->lequ.tab[i];
		j = 0;
		if (ft_strchr(d->lequ.tab[i], 'x') == NULL && ft_strchr(d->lequ.tab[i], 'X') == NULL)
			d->lequ.m.c += (float)ft_atoi(d->lequ.tab[i]);
		else if (ft_strchr(d->lequ.tab[i], '^') == NULL)
			d->lequ.m.b += (float)ft_atoi(d->lequ.tab[i]);
		else if (ft_strchr(d->lequ.tab[i], '^') != NULL)
		{
			while (d->lequ.tab[i][j])
			{
				if (d->lequ.tab[i][j] == '^')
				{
					j++;
					if (!(d->lequ.tab[i][j] >= 48 && 57 >= d->lequ.tab[i][j]))
						ft_error(UNDEFINED_POWER, d);
					while (d->lequ.tab[i][j] >= 48 && 57 >= d->lequ.tab[i][j])
					{
						d->degree = d->degree * 10 + (d->lequ.tab[i][j] - '0');
						j++;
					}
					if (d->degree == 2)
						d->lequ.m.a += (float)ft_atoi(d->lequ.tab[i]);
					else if (d->degree == 1)
						d->lequ.m.b += (float)ft_atoi(d->lequ.tab[i]);
					else if (d->degree == 0)
						d->lequ.m.c += (float)ft_atoi(d->lequ.tab[i]);
					else if (d->degree > 2)
						ft_error(d->degree, d);
				}
				j++;
			}
		}
		i++;
	}
	return 0;
}

int		identify_right_monomes(t_data *d, int i, int j)
{
	while (d->requ.tab[i])
	{
		j = 0;
		d->degree = 0;
		if (ft_strchr(d->requ.tab[i], 'x') == NULL && ft_strchr(d->requ.tab[i], 'X') == NULL)
			d->requ.m.c += (float)ft_atoi(d->requ.tab[i]);
		else if (ft_strchr(d->requ.tab[i], '^') == NULL)
			d->requ.m.b += (float)ft_atoi(d->requ.tab[i]);
		else if (ft_strchr(d->requ.tab[i], '^') != NULL)
		{
			while (d->requ.tab[i][j])
			{
				if (d->requ.tab[i][j] == '^')
				{
					j++;
					while (d->requ.tab[i][j] >= 48 && 57 >= d->requ.tab[i][j])
					{
						d->degree = d->degree * 10 + (d->requ.tab[i][j] - '0');
						j++;
					}
					if (d->degree == 2)
						d->requ.m.a += (float)ft_atoi(d->requ.tab[i]);
					else if (d->degree == 1)
						d->requ.m.b += (float)ft_atoi(d->requ.tab[i]);
					else if (d->degree == 0)
						d->requ.m.c += (float)ft_atoi(d->requ.tab[i]);
					else if (d->degree > 2)
					{
						d->current_monomial = d->requ.tab[i];
						ft_error(d->degree, d);
					}
				}
				j++;
			}
		}
		i++;
	}
	return 0;
}

void	reduce_equation(t_data *d)
{
	if (d->lequ.m.a == 0 && d->requ.m.a == 0)
	{
		if ((d->lequ.m.b == 0 && d->requ.m.b == 0) || (d->lequ.m.b == d->requ.m.b))
		{
			d->m.c = d->lequ.m.c - d->requ.m.c;
			display_degree_0(d);
		}
		else if (d->lequ.m.b != 0 || d->requ.m.b != 0)
		{
			d->m.b = d->lequ.m.b - d->requ.m.b;
			d->m.c = d->lequ.m.c - d->requ.m.c;
			display_degree_1(d);
		}
	}
	else if (d->lequ.m.a != 0 || d->requ.m.a != 0)
	{
		d->m.a = d->lequ.m.a - d->requ.m.a;
		d->m.b = d->lequ.m.b - d->requ.m.b;
		d->m.c = d->lequ.m.c - d->requ.m.c;
		display_degree_2(d);
	}
}

void	reduce(t_data *d)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	identify_left_monomes(d, i, j);
	identify_right_monomes(d, i, j);
	reduce_equation(d);
}