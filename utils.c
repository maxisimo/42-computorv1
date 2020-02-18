#include "computorv1.h"

int		ft_error(int code, t_data *d)
{
	if (code == UNDEFINED_CHAR)
	{
		ft_putstr("Undefined char has been detected !\n");
		ft_putstr("Authorised chars : \"");
		ft_putstr(SYMBOL);
		ft_putstr("\"\n\nFor more informations please refer to the README.md\n");
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
	decimal *= 10e5;
	n *= 10e5;
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
	while (i > 6)
	{
		i--;
		ft_putchar(tab[i] + '0');
	}
	if (dec != 0)
	{
		ft_putchar('.');
		i = 0;
		j = 0;
		while (dec != 0)
		{
			tab2[j] = dec % 10;
			dec = dec / 10;
			j++;
		}
		if (tab2[i] == 0)
			while (tab2[i] == 0)
				i++;
		while (j > i)
		{
			j--;
			ft_putchar(tab2[j] + '0');
		}
	}
}

void	ft_adapt_putstr(char const *s, ...)
{
	int		i;
	float	nb;
	va_list	ap;

	i = 0;
	va_start(ap, s);
	nb = va_arg(ap, double);
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	ft_adapt_putnbr((float)nb);
	va_end(ap);
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

char	*ft_adapt_strsub(const char *s, unsigned int start, size_t len, int neg)
{
	size_t	i;
	size_t	j;
	char	*s1;

	i = 0;
	j = 0;
	if (neg == 1)
	{
		if (!(s1 = (char*)malloc(sizeof(*s1) * (len + 2))))
			return (NULL);
		s1[j] = '-';
		j = 1;
		len += 1;
	}
	else
		if (!(s1 = (char*)malloc(sizeof(*s1) * (len + 1))))
			return (NULL);
	while (i < len)
	{
		s1[j] = s[start + i];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}

static int	ft_size(char *s, char c, char c2)
{
	int i;

	i = 0;
	while (*s != c && *s != c2 && *s)
	{
		i++;
		s++;
	}
	return (i);
}

static int	ft_count(const char *s, char c, char c2)
{
	int nb;
	int new_word;

	nb = 0;
	new_word = 0;
	while (*s)
	{
		if (*s == c || *s == c2)
			new_word = 0;
		if (*s != c && *s != c2 && new_word == 0)
		{
			new_word = 1;
			nb++;
		}
		s++;
	}
	return (nb);
}

char		**ft_adapt_strsplit(const char *s, char c, char c2)
{
	char	**array;
	int		i;
	int		nb_words;
	int		neg;

	i = 0;
	neg = 0;
	nb_words = ft_count((char*)s, c, c2);
	array = (char **)malloc(sizeof(char*) * (nb_words + 1));
	if (!array)
		return (NULL);
	while (nb_words--)
	{
		if (*s == c2)
			neg = 1;
		while ((*s == c || *s == c2) && *s)
			s++;
		if (!(array[i] = ft_adapt_strsub(s, 0, ft_size((char*)s, c, c2), neg)))
			return (NULL);
		neg = 0;
		s = s + ft_size((char*)s, c, c2);
		i++;
	}
	array[i] = NULL;
	return (array);
}