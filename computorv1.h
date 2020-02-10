#ifndef COMPUTORV1_H
# define COMPUTORV1_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define SYMBOL "+-=^*."
# define UNDEFINED_CHAR 1
# define UPPER_DEGREE 2

# define STEP1 1

typedef struct	s_monomials
{
	float		a;
	float		b;
	float		c;
}				t_monomials;

typedef struct	s_requ
{
	t_monomials m;
	char		**tab;
}				t_requ;

typedef struct	s_lequ
{
	t_monomials m;
	char		**tab;
}				t_lequ;

typedef struct	s_data
{
	int			degree;
	char		**equ;
	char		**tab;
	t_monomials	m;
	t_requ		requ;
	t_lequ		lequ;
}				t_data;

/* Parser functions */
char			*clean(char *str);
int				check_chars(char *str);
void    		parser(t_data *d, char *str);

/* Reduce functions */
void			reduce(t_data *d);

/* Display functions */
void			display_degree_0(t_data *d);
void			display_degree_1(t_data *d);
void			display_degree_2(t_data *d);

/* Adapted functions from my libft and utils functions*/
int				ft_error(int code);
void			ft_adapt_putnbr(float n);

/* Utils functions from my Libft */
void			ft_bzero(void *s, size_t n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
char			*ft_strchr(const char *s, int c);
char			**ft_strsplit(const char *s, char c);
char			**ft_strsplit2(const char *s, char c, char c2);
size_t			ft_strlen(const char *str);
int				ft_isdigit(int c);
double			ft_atoi(char const *str);
void			ft_putnbr(int n);

#endif