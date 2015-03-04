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

typedef long int			li;
typedef unsigned long int	uli;
typedef long long int		ll;
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
void	ft_putnbr(int n);
size_t	ft_strlen(char const *s);
void	ft_bzero(void *s, size_t n);
void	ft_putnbr_u(unsigned int n);
int		ft_atoi(char const *str);
void	ft_putnbr_uli(uli n);
void	ft_putnbr_li(li n);
void	ft_putwstr(wchar_t const *s);
void	ft_putwchar(wchar_t c);
char	*ft_inverse(char *s);
char	**ft_strsplit(char const *s, char c);
char	*ft_strcpy(char *dst, char const *src);
char	*ft_itoa(int n);
char	*ft_itoa_u(unsigned int n);
char	*ft_itoa_uli(uli n);
int		ft_isdigit(int c);
void	ft_nb_digit(int i, t_flags flags);
void	ft_nb_digit_uli(uli i, t_flags flags);
void	ft_nb_digit_u(unsigned int i, t_flags flags);
void	ft_nb_digit_c(char *s, t_flags flags);

#endif
