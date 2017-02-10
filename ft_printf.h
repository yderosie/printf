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
# include <stdint.h>
# include "struct.h"

typedef void	(*t_fct)(t_conv *conv, unsigned int *count, int a);

int				ft_printf(char const *format, ...);
int				ft_putchar(char c);
int				ft_putstr(char const *s);
int				ft_putnstr(char const *s, size_t size);
size_t			ft_strlen(char const *s);
size_t			ft_strlen_w(wchar_t const *s);
void			ft_bzero(void *s, size_t n);

int				ft_atoi(char const *str);
size_t			ft_putwchar(wchar_t c);
char			*ft_inverse(char *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_strcpy(char *dst, char const *src);
int				ft_isdigit(int c);

void			conv_s(t_conv *cv, unsigned int *count, int a);
void			conv_ss(t_conv *cv, unsigned int *count, int len);
void			conv_c(t_conv *cv, unsigned int *count, int a);
void			conv_cc(t_conv *cv, unsigned int *count, int a);

void			conv_d(t_conv *cv, unsigned int *count, int sub_p);
void			conv_dd(t_conv *cv, unsigned int *count, int sub_p);
void			conv_u(t_conv *cv, unsigned int *count, int sub_p);
void			conv_uu(t_conv *cv, unsigned int *count, int sub_p);

void			conv_o(t_conv *cv, unsigned int *count, int sub_p);
void			conv_oo(t_conv *cv, unsigned int *count, int sub_p);
void			conv_x(t_conv *cv, unsigned int *count, int sub_p);
void			conv_xx(t_conv *cv, unsigned int *count, int sub_p);

void			conv_p(t_conv *cv, unsigned int *count, int a);
void			conv_pc(t_conv *cv, unsigned int *count, int a);

int				check_all_option(char c);
int				check_conv(char c);
int				check_flags(char c);

size_t			nb_octets_write(wchar_t c);

int				print_space(int i);
int				print_zero(int i);

int				diff_p(int precision, int len, int negatif);
int				len_cw(wchar_t c, unsigned int ret, t_flags flags);
int				diff_sw(wchar_t *s, t_flags flags);

size_t			binary_to_decimal(char *s);
char			*binary(unsigned int j);
void			flags_initialization(t_conv *conv);
t_ull			diff_u_return(t_conv *conv);
t_ll			diff_return(t_conv *conv);
int				flags_present(t_conv *conv, char *s1, int i);
char			*conv_octal(t_ull j);
char			*conv_hexa(t_ull j);
int				ft_nblen_u(t_ull i);
int				ft_nblen(t_ll i);
char			*conv_hexa_x(t_ull j);
int				ft_putnbr_u(t_ull n);
int				ft_putnbr(t_ll n);
unsigned int	count_c_hexa(t_ull i);

void			flags_error(t_conv *conv);

#endif
