#include "computorv1.h"

char	*clean(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = (char *)malloc(sizeof(char) * ft_strlen(str + 1));
	while (str[i])
	{
		if (str[i] != ' ')
		{
			tmp[j] = str[i];
			j++;
		}
		i++;
	}
	return tmp;
}

int		check_chars(char *str)
{
	int					i;
	unsigned int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if ((ft_isdigit(str[i]) == 0) && str[i] != 'x' && str[i] != 'X' && str[i] != ' ')
		{
			while (SYMBOL[j] && (str[i] != SYMBOL[j]))
				j++;
			if (j == ft_strlen(SYMBOL))
			{
				return (UNDEFINED_CHAR);
			}
		}
		i++;
	}
	return 0;
}

void	parser(t_data *d, char *str)
{
	if (check_chars(str) == UNDEFINED_CHAR)
		ft_error(UNDEFINED_CHAR, d);
	str = clean(str);
	d->equ = ft_strsplit(str, '=');
	if (str[0] == '=')
	{
		d->lequ.tab = ft_strsplit2("0", '+', '-');
		d->requ.tab = (d->equ[0]) ? ft_strsplit2(d->equ[0], '+', '-') : ft_strsplit2("0", '+', '-');
	}
	else
	{
		d->lequ.tab = ft_strsplit2(d->equ[0], '+', '-');
		d->requ.tab = (d->equ[1]) ? ft_strsplit2(d->equ[1], '+', '-') : ft_strsplit2("0", '+', '-');
	}
	reduce(d);
}
