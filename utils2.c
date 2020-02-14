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

int		ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
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

static int		ft_nb_char(char const *str, int deb, char c)
{
	while (str[deb] && str[deb] != c)
		deb++;
	return (deb);
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

static int		ft_nb_char2(char const *str, int deb, char c, char c2)
{
	int		i;

	i = 0;
	while (str[deb] && str[deb] != c && str[deb] != c2)
		deb++;
	if (i == 0 && str[deb] == c2)
	{
		i = 1;
		deb++;
	}
	return (deb);
}

static int		ft_nb_words2(char const *str, char c, char c2)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] != c && str[i] != c2)
		{
			i++;
			j = 1;
		}
		if (str[i] == c || str[i] == c2|| str[i] == '\0')
		{
			if (j == 1)
				count += 1;
		}
		j = 0;
		(str[i] == '\0') ? 0 : i++;
	}
	return (count);
}

char			**ft_strsplit2(char const *s, char c, char c2)
{
	char	**tab;
	int		i;
	int		j;
	int		k;
	int		negative;

	i = 0;
	j = 0;
	negative = 0;
	if (!s || !(tab = (char**)malloc(sizeof(char*) * (ft_nb_words2(s, c, c2) + 1))))
		return (NULL);
	while (s[i])
	{
		if (s[i] == c2)
			negative = 1;
		while (s[i] == c || s[i] == c2)
			i++;
		if (s[i])
		{
			if (!(tab[j] = (char*)malloc(sizeof(char) * ft_nb_char2(s, i, c, c2))))
				return (0);
			if (negative == 0)
				k = 0;
			else
			{
				k = 1;
				tab[j][0] = '-';
				negative = 0;
			}
			while (s[i] && s[i] != c && s[i] != c2)
				tab[j][k++] = s[i++];
			tab[j++][k] = '\0';
		}
	}
	tab[j] = NULL;
	return (tab);
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
