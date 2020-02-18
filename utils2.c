#include "computorv1.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s1;
	size_t			i;

	i = 0;
	s1 = s;
	while (i < n)
	{
		s1[i] = '\0';
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != c)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char*)s);
}

void	ft_putstr(char const *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_putnbr(int n)
{
	long	nb;
	int		tab[100];
	int		i;

	i = 0;
	if (n == 0)
		ft_putchar('0');
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	while (nb != 0)
	{
		tab[i] = nb % 10;
		nb = nb / 10;
		i++;
	}
	while (i > 0)
	{
		i--;
		ft_putchar(tab[i] + '0');
	}
}

static int		ft_nb_char(char const *str, int deb, char c)
{
	int		i;


	i = 0;
	while (str[deb] && str[deb] != c)
		deb++;
	if (i == 0 && str[deb] == c)
	{
		i = 1;
		deb++;
	}
	return (deb);
}

static int		ft_nb_words(char const *str, char c)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] != c)
		{
			i++;
			j = 1;
		}
		if (str[i] == c || str[i] == '\0')
		{
			if (j == 1)
				count += 1;
		}
		j = 0;
		(str[i] == '\0') ? 0 : i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!s || !(tab = (char**)malloc(sizeof(char*) * (ft_nb_words(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			k = 0;
			if (!(tab[j] = (char*)malloc(sizeof(char) * ft_nb_char(s, i, c))))
				return (0);
			while (s[i] && s[i] != c)
				tab[j][k++] = s[i++];
			tab[j++][k] = '\0';
		}
	}
	tab[j] = NULL;
	return (tab);
}
