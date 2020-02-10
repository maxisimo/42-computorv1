#include "computorv1.h"

int		main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		ft_bzero(&data, sizeof(t_data));
		parser(&data, av[1]);
	}
	else
		ft_putstr("usage: ./computorv1 <equation>\n");
	return 0;
}