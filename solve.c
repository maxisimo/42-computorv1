#include "computorv1.h"

void	solve(t_data *d)
{
	if (d->degree == 1)
	{
		d->result.x1 = (d->m.c == 0) ? 0 : (-d->m.c) / d->m.b;
	}
	else if (d->degree == 2)
	{
		d->delta = (d->m.b * d->m.b) - 4 * d->m.a * d->m.c;
		if (d->delta < 0)
			printf("Can't solve it yet\n");
		else if (d->delta == 0)
			d->result.x1 = (-d->m.b) / 2 * d->m.a;
		else
		{
			d->result.x1 = (-d->m.b - sqrt((double)d->delta)) / (2 * d->m.a);
			d->result.x2 = (-d->m.b + sqrt((double)d->delta)) / (2 * d->m.a);
		}
	}
}