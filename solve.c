#include "computorv1.h"

void	solve(t_data *d)
{
	d->denominator = 2 * d->m.a;
	if (d->degree == 1)
	{
		d->result.x1 = (d->m.c == 0) ? 0 : (-d->m.c) / d->m.b;
	}
	else if (d->degree == 2)
	{
		d->delta = (d->m.b * d->m.b) - 4 * d->m.a * d->m.c;
		if (d->delta < 0)
		{
			d->square = sqrt(abs((double)d->delta));
			d->result.x1 = -d->m.b / d->denominator;
			d->result.x2 = -d->m.b / d->denominator;
		}
		else if (d->delta == 0)
			d->result.x1 = (-d->m.b) / d->denominator;
		else
		{
			d->result.x1 = (-d->m.b - sqrt((double)d->delta)) / d->denominator;
			d->result.x2 = (-d->m.b + sqrt((double)d->delta)) / d->denominator;
		}
	}
}