#ifndef COMPUTORV1_H
# define COMPUTORV1_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <stdarg.h>

# define SYMBOL "0123456789xX +-=^*."
# define UNDEFINED_CHAR 1
# define UNDEFINED_POWER 2

# define STEP1 1

typedef struct	s_result
{
	float		x1;
	float		x2;
}				t_result;


typedef struct	s_monomials
{
	float		a;
	float		b;
	float		c;
}				t_monomials;

typedef struct	s_requ
{
	char		**tab;
	t_monomials m;
}				t_requ;

typedef struct	s_lequ
{
	char		**tab;
	t_monomials m;
}				t_lequ;

typedef struct	s_data
{
	int			degree;
	float		delta;
	float		denominator;
	double		square;
	char		**equ;
	char		**tab;
	char		*current_monomial;
	t_monomials	m;
	t_result	result;
	t_requ		requ;
	t_lequ		lequ;
}				t_data;

/* Parser functions */
char			*clean(char *str);
int				check_chars(char *str);
void    		parser(t_data *d, char *str);

void			reduce(t_data *d);

/* Display functions */
void			display_degree_0(t_data *d);
void			display_degree_1(t_data *d);
void			display_degree_2(t_data *d);

void			solve(t_data *d);

/* Adapted functions from my libft and utils functions*/
int				ft_error(int code, t_data *d);
void			ft_adapt_putnbr(float n);
void			ft_adapt_putstr(char const *s, ...);
double			ft_adapt_atoi(char const *str);
char			**ft_adapt_strsplit(const char *s, char c, char c2);

/* Utils functions from my Libft */
void			ft_bzero(void *s, size_t n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *str);
void			ft_putnbr(int n);
char			**ft_strsplit(const char *s, char c);

#endif
