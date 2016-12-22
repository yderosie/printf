/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 21:37:41 by yderosie          #+#    #+#             */
/*   Updated: 2015/02/18 17:04:33 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <locale.h>
# include <stdarg.h>
# include <wchar.h>

typedef long int			li;
typedef unsigned long int	uli;
typedef long long			ll;
typedef unsigned long long	ull;

typedef struct	s_arg
{
	va_list ap;
	va_list save;
}				t_arg;

typedef struct 	s_flags
{
	int		htag;
	int		zero;
	int		espace;
	int		moins;
	int		plus;
	int		precision;
	int		fhh;
	int		fh;
	int		fl;
	int		fll;
	int		j;
	int		z;
}				t_flags;

typedef struct	s_conv
{
	char			*s;
	wchar_t			*ss;
	ll				d;
	char			dhh;
	li				dd;
	char			c;
	wchar_t			cc;
	ull				o;
	uli				oo;
	void			*p;
	ull				x;
	ull				xx;
	ull				u;
	uli				uu;
	t_arg			arg;
	t_flags			flags;
}				t_conv;

int		ft_printf(char const *format, ...);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
size_t	ft_strlen(char const *s);
void	ft_bzero(void *s, size_t n);

int		ft_atoi(char const *str);
void	ft_putnbr_uli(uli n);
void	ft_putnbr_li(li n);
void	ft_putwstr(wchar_t const *s);
size_t	ft_putwchar(wchar_t c);
char	*ft_inverse(char *s);
char	**ft_strsplit(char const *s, char c);
char	*ft_strcpy(char *dst, char const *src);
char	*ft_itoa(ll n);
char	*ft_itoa_u(ull n);
int		ft_isdigit(int c);
void	ft_nb_digit_c(char *s, t_flags flags);

int				check_flag(char c);

size_t			binary_to_decimal(char *s);
char			*binary(unsigned int j);
void			flags_initialization(t_conv *conv);
ull				diff_u_return(t_conv *conv);
ll				diff_return(t_conv *conv);
int				flags_present(t_conv *conv, char *s1, int i);
ull				conv_octal(ull j);
char			*conv_hexa(unsigned int j);
int				ft_nb_digit_u(ull i, t_flags flags);
int				ft_nb_digit(ll i, t_flags flags);
char			*conv_hexa_X(unsigned int j);
char			*conv_hexa_p_X_h(unsigned int j);
void			ft_putnbr_u(ull n);
void			ft_putnbr(ll n);
unsigned int	count_c_hexa(unsigned int i);
char			if_forest_hexa_X(unsigned int k);
char			if_forest_hexa(unsigned int k);

#endif
