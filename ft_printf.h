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

typedef long int				li;		/* t_li */
typedef unsigned long int		uli;	/* t_uli */
typedef long long int			ll;		/* t_ll */
typedef unsigned long long int	ull;	/* t_ull */

typedef struct	s_arg
{
	va_list ap;
	va_list save;
}				t_arg;

typedef struct	s_flags
{
	int		htag;
	int		zero;
	int		espace;
	int		moins;
	int		plus;
	int		precision;
	int		point;
	int		largeur;
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
	char			*o;
	char			*oo;
	void			*p;
	ull				x;
	ull				xx;
	ull				u;
	uli				uu;
	t_arg			arg;
	t_flags			flags;
}				t_conv;

int		ft_printf(char const *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char const *s);
int		ft_putnstr(char const *s, size_t size);
size_t	ft_strlen(char const *s);
size_t	ft_strlen_for_wchar(wchar_t const *s);
void	ft_bzero(void *s, size_t n);

int		ft_atoi(char const *str);
//void	ft_putnbr_uli(uli n);
//void	ft_putnbr_li(li n);
//void	ft_putwstr(wchar_t const *s);
size_t	ft_putwchar(wchar_t c);
char	*ft_inverse(char *s);
char	**ft_strsplit(char const *s, char c);
char	*ft_strcpy(char *dst, char const *src);
//char	*ft_itoa(ll n);
//char	*ft_itoa_u(ull n);
int		ft_isdigit(int c);
//void	ft_nb_digit_c(char *s, t_flags flags);

int				check_all_option(char c);
int				check_conv(char c);
int				check_flags(char c);

size_t			binary_to_decimal(char *s);
char			*binary(unsigned int j);
void			flags_initialization(t_conv *conv);
ull				diff_u_return(t_conv *conv);
ll				diff_return(t_conv *conv);
int				flags_present(t_conv *conv, char *s1, int i);
char			*conv_octal(ull j);
char			*conv_hexa(ull j);
int				ft_nb_digit_u(ull i);
int				ft_nb_digit(ll i);
char			*conv_hexa_x(ull j);
int				ft_putnbr_u(ull n);
int				ft_putnbr(ll n);
unsigned int	count_c_hexa(ull i);

#endif
