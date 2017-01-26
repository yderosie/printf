/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 04:43:41 by yderosie          #+#    #+#             */
/*   Updated: 2015/02/13 12:29:28 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		diff_for_precision(int precision, int len, int negatif)
{
	int ret;

	ret = precision - len;
	ret = (negatif) ? ret + 1 : ret; 
	ret = (ret > 0) ? ret : 0;
	return (ret);
}

int		print_space(int i)
{
	int ret;

	ret = 0;
	while (i > 0)
	{
		ret += ft_putchar(' ');
		i--;
	}
	return (ret);
}

int		print_zero(int i)
{
	int ret;

	ret = 0;
	while (i > 0)
	{
		ret += ft_putchar('0');
		i--;
	}
	return (ret);
}

int		precision_for_s(wchar_t c, unsigned int ret, t_flags flags)
{
	if (c <= 0x7F)
		ret += 1;
	else if (c <= 0x7FF)
		ret += 2;
	else if (c <= 0xFFFF)
		ret += 3;
	else
		ret += 4;
	return (ret);
}

int		diff_precision_s(wchar_t *s, t_flags flags)
{
	int len;
	int i;

	len = 0;
	i = 1;
	if (precision_for_s(s[0], len, flags) <= flags.precision)
	{
		len = precision_for_s(s[0], len, flags);
		while (s[i] != '\0' && len <= flags.precision)
		{
			len = precision_for_s(s[i++], len, flags);
		}
		if (len > flags.precision)
		{
			len = len - precision_for_s(s[i - 1], 0, flags);
			return (flags.precision + (len - flags.precision));
		}
	}
	return (flags.precision);
}

size_t	tab_0(char *s1, char *tab)
{
	int		i;
	int		j;
	int		l;
	char	**s2;
	size_t	ret;

	l = 0;
	ret = 0;
	i = ft_strlen(tab);
	j = ft_strlen(s1) - 1;
	while (j >= 0 && --i >= 0)
	{
		if (tab[i] == 'x')
			tab[i] = s1[j--];
	}
	i = -1;
	while (tab[++i] != '\0')
	{
		if (tab[i] == 'x')
			tab[i] = '0';
	}
	s2 = ft_strsplit(tab, ' ');
	while (s2[l] != '\0')
		ret += binary_to_decimal(s2[l++]);
	return (ret);
}

size_t	nb_octets_write_2(unsigned int i)
{
	char	*tab[3];
	char	*s1;
	char	*s2;

	s2 = (char*)malloc(sizeof(char) * 36);
	tab[0] = "110xxxxx 10xxxxxx\0";
	s2 = ft_strcpy(s2, tab[0]);
	tab[1] = "1110xxxx 10xxxxxx 10xxxxxx\0";
	tab[2] = "11110xxx 10xxxxxx 10xxxxxx 10xxxxxx\0";
	s1 = binary(i);
	if (i <= 0x7FF)
		s2 = ft_strcpy(s2, tab[0]);
	else if (i <= 0xFFFF)
		s2 = ft_strcpy(s2, tab[1]);
	else
		s2 = ft_strcpy(s2, tab[2]);
	return (tab_0(s1, s2));
}

size_t		nb_octets_write(wchar_t c)
{
	unsigned int i;

	i = (unsigned int)c;
	if (i <= 0x7F)
		return (ft_putwchar(c));
	else if (i >= 0x7F && i <= 0x1FFFFF)
		return (nb_octets_write_2(i));
	else
		return (-1);
	return (0);
}

char	*ft_inverse(char *s)
{
	int		i;
	int		j;
	char	*s2;

	i = 0;
	j = ft_strlen(s) - 1;
	s2 = (char *)malloc(sizeof(char) * ft_strlen(s));
	while (j >= 0)
	{
		s2[i] = s[j];
		i++;
		j--;
	}
	return (s2);
}

int		ft_printf(char const *format, ...)
{
	char				*s1;
	int					i;
	t_conv				conv;
	char				*s2;
	int					j;
	int					k;
	unsigned int		compteur;
	int					sub_p;
	int					sub_for_s;
	int					len;

	i = 0;
	sub_p = 0;
	sub_for_s = 0;
	compteur = 0;
	s1 = (char *)format;
	s2 = (char *)malloc(sizeof(char) * ft_strlen(format) + 1);
	va_start(conv.arg.ap, format);
	va_copy(conv.arg.save, conv.arg.ap);
	while (s1[i] != '\0')
	{
		k = 0;
		if (ft_strlen(s1) == 1 && s1[0] == '%')
		{
			return(0);
		}
		j = 0;
		ft_bzero(s2, ft_strlen(s2) + 1);
		while (s1[i] != '%' && s1[i] != '\0')
		{
			s2[j++] = s1[i++];
		}
		s2[j] = '\0';
		compteur += ft_putstr(s2);
		if (s1[i] == '%' && s1[i + 1] != '\0')
		{
			flags_initialization(&conv);
			i += flags_present(&conv, s1 + i + 1, 0) + 1;
			if (check_conv(s1[i]) == 1)
			{
				if (s1[i] == 's' && conv.flags.fl == 0)
				{
					conv.s = va_arg(conv.arg.ap, char*);
					if (conv.s != NULL)
					{
						if (conv.flags.point == 1 && conv.flags.precision < ft_strlen(conv.s))
							sub_for_s = conv.flags.precision;
						else
							sub_for_s = ft_strlen(conv.s);
						if (conv.flags.largeur > 0 && conv.flags.zero == 1)
							compteur += print_zero(conv.flags.largeur - sub_for_s);
						if (conv.flags.largeur > 0 && conv.flags.zero == 0)
							compteur += print_space(conv.flags.largeur - sub_for_s);
						if (conv.flags.point == 1 && conv.flags.precision < ft_strlen(conv.s))
							compteur += ft_putnstr(conv.s, conv.flags.precision);
						else
							compteur += ft_putstr(conv.s);
					}
					else if (conv.flags.zero == 1 && conv.flags.point == 1 && conv.s == NULL)
						compteur += print_zero(conv.flags.largeur);
					else
						compteur += ft_putstr("(null)");
				}
				if (s1[i] == 'S' || (s1[i] == 's' && conv.flags.fl == 1))
				{					
					len = 0;
					conv.ss = va_arg(conv.arg.ap, wchar_t*);
					if (conv.ss != NULL)
					{
						if (conv.flags.point == 1 && conv.flags.precision < ft_strlen_for_wchar(conv.ss))
							sub_for_s = diff_precision_s(conv.ss, conv.flags);
						else
							sub_for_s = ft_strlen_for_wchar(conv.ss);
						if (conv.flags.largeur > 0 && conv.flags.zero == 1 && conv.flags.moins == 0)
							compteur += print_zero(conv.flags.largeur - sub_for_s);
						if (conv.flags.largeur > 0 && conv.flags.zero == 0 && conv.flags.moins == 0)
							compteur += print_space(conv.flags.largeur - sub_for_s);
						while (conv.ss[k] != '\0')
						{
							if (conv.flags.point == 0)
								len += nb_octets_write(conv.ss[k]);
							else if (conv.flags.point == 1 && precision_for_s(conv.ss[k], len, conv.flags) <= conv.flags.precision)
								len += nb_octets_write(conv.ss[k]);
							k++;
						}
						compteur += len;
						if (conv.flags.largeur > 0 && conv.flags.zero == 0 && conv.flags.moins == 1)
							compteur += print_space(conv.flags.largeur - ft_strlen_for_wchar(conv.ss));
					}
					else
						compteur += ft_putstr("(null)");
				}
				if (s1[i] == 'd' || s1[i] == 'i')
				{
					conv.d = diff_return(&conv);
					if (conv.d >= 0 && conv.flags.plus == 1)
						compteur += ft_putchar('+');
					if (conv.flags.point == 1)
						sub_p = diff_for_precision(conv.flags.precision, ft_nb_digit(conv.d), ((conv.d < 0) ? 1 : 0));
					if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 0)
						compteur += print_space(conv.flags.largeur - (ft_nb_digit(conv.d) + sub_p));
					if (conv.d >= 0 && conv.flags.espace == 1 && conv.flags.plus == 0)
					{
						compteur += ft_putchar(' ');
						if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 1)
							compteur += print_zero(conv.flags.largeur - (ft_nb_digit(conv.d) + 1 + sub_p));
					}
					if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 1 && conv.flags.espace == 0)
					{
						if (conv.flags.plus == 1)
							compteur += print_zero(conv.flags.largeur - (ft_nb_digit(conv.d) + 1 + sub_p));
						else if (conv.d < 0)
						{
							conv.d = conv.d * -1;
							compteur += ft_putchar('-');
							compteur += print_zero(conv.flags.largeur - (ft_nb_digit(conv.d) + 1 + sub_p));
						}
						else
						{
							if (conv.flags.point == 1)
								compteur += print_space(conv.flags.largeur - (ft_nb_digit(conv.d) + sub_p));
							else
								compteur += print_zero(conv.flags.largeur - (ft_nb_digit(conv.d) + sub_p));
						}
					}
					else if (conv.d < 0 && ft_nb_digit(conv.d) < conv.flags.precision)
					{
						conv.d = -conv.d;
						compteur += ft_putchar('-');
					}
					compteur += print_zero(sub_p);
					if (conv.flags.point == 1 && conv.flags.precision <= 0)
						;
					else
						compteur += ft_putnbr(conv.d);
					if (conv.flags.largeur > 0 && conv.flags.moins == 1)
						compteur += print_space(conv.flags.largeur - (ft_nb_digit(conv.d) + sub_p));
				}
				if (s1[i] == 'D')
				{
					conv.dd = va_arg(conv.arg.ap, li);
					if (conv.flags.point == 1)
						sub_p = diff_for_precision(conv.flags.precision, ft_nb_digit(conv.dd), ((conv.dd < 0) ? 1 : 0));
					if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 0)
						compteur += print_space(conv.flags.largeur - (ft_nb_digit(conv.dd) + sub_p));
					if (conv.dd >= 0 && conv.flags.zero == 1)
						compteur += print_zero(conv.flags.largeur - (ft_nb_digit(conv.dd) + sub_p));
					if (conv.flags.precision > 0)
						compteur += print_zero((ft_nb_digit(conv.dd) + sub_p));
					compteur += ft_putnbr(conv.dd);
				}
				if (s1[i] == 'c')
				{
					if (conv.d > 0 && conv.flags.fl == 1)
					{
						conv.cc = va_arg(conv.arg.ap, wint_t);
						if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 0)
							compteur += print_space(conv.flags.largeur - ft_nb_digit(conv.cc));
						compteur += nb_octets_write(conv.cc);
					}
					else
					{
						conv.c = va_arg(conv.arg.ap, int);
						if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 0)
							compteur += print_space(conv.flags.largeur - ft_nb_digit(conv.c));
						if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 1)
							compteur += print_zero(conv.flags.largeur - ft_nb_digit(conv.c));
						compteur += ft_putchar(conv.c);
					}	
				}
				if (s1[i] == 'C')
				{
					conv.cc = va_arg(conv.arg.ap, wint_t);
					compteur += nb_octets_write(conv.cc);
				}
				if (s1[i] == 'u')
				{
					conv.u = diff_u_return(&conv);
					if (conv.flags.point == 1)
					{
						sub_p = diff_for_precision(conv.flags.precision, ft_nb_digit_u(conv.u), 0);
						if (conv.flags.precision > 0)
							compteur += print_space(conv.flags.largeur - (ft_nb_digit_u(conv.u) + sub_p));
						compteur += print_zero(sub_p);
					}
					if (conv.flags.point == 1 && conv.flags.precision <= 0)
						;
					else
						compteur += ft_putnbr_u(conv.u);
				}
				if (s1[i] == 'U')
				{
					conv.uu = va_arg(conv.arg.ap, uli);
					if (conv.flags.point == 1)
					{
						sub_p = diff_for_precision(conv.flags.precision, ft_nb_digit_u(conv.uu), 0);
						if (conv.flags.precision > 0)
							compteur += print_space(conv.flags.largeur - (ft_nb_digit_u(conv.uu) + sub_p));
						compteur += print_zero(sub_p);
					}
					if (conv.flags.point == 1 && conv.flags.precision <= 0)
						;
					else
						compteur += ft_putnbr_u(conv.uu);
				}
				if (s1[i] == 'o')
				{
					conv.o = conv_octal(diff_u_return(&conv));
					if (ft_strlen(conv.o) > 1 && conv.flags.htag == 1 && conv.flags.precision == 0)
						compteur += ft_putchar('0');
					if (conv.flags.point == 1)
					{
						sub_p = diff_for_precision(conv.flags.precision, ft_strlen(conv.o), 0);
						if (conv.flags.precision > 0)
							compteur += print_space(conv.flags.largeur - (ft_strlen(conv.o) + sub_p));
						compteur += print_zero(sub_p);
					}
					if (conv.flags.point == 1 && conv.flags.precision <= 0 && conv.flags.htag == 0)
						;
					else
						compteur += ft_putstr(conv.o);
				}
				if (s1[i] == 'O')
				{
					conv.oo = conv_octal(va_arg(conv.arg.ap, uli));
					if (conv.flags.htag == 1)
						compteur += ft_putchar('0');
					if (conv.flags.point == 1)
					{
						sub_p = diff_for_precision(conv.flags.precision, ft_strlen(conv.oo), 0);
						if (conv.flags.precision > 0)
							compteur += print_space(conv.flags.largeur - (ft_strlen(conv.oo) + sub_p));
						compteur += print_zero(sub_p);
					}
					if (conv.flags.point == 1 && conv.flags.precision <= 0)
						;
					else
						compteur += ft_putstr(conv.oo);
				}
				if (s1[i] == 'x')
				{
					conv.x = diff_u_return(&conv);
					if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 1)
					{
						if (conv.x != 0 && conv.flags.htag == 1)
							compteur += print_zero(conv.flags.largeur - (ft_strlen(conv_hexa(conv.x)) + 2));
						else
							compteur += print_zero(conv.flags.largeur - ft_strlen(conv_hexa(conv.x)));
					}
					if (conv.x != 0 && conv.flags.htag == 1)
						compteur += ft_putstr("0x");
					if (conv.flags.point == 1)
					{
						sub_p = diff_for_precision(conv.flags.precision, ft_strlen(conv_hexa(conv.x)), 0);
						if (conv.flags.precision > 0)
							compteur += print_space(conv.flags.largeur - (ft_strlen(conv_hexa(conv.x)) + sub_p));
						compteur += print_zero(sub_p);
					}
					if (conv.flags.point == 1 && conv.flags.precision <= 0)
						;
					else
						compteur += ft_putstr(conv_hexa(conv.x));
				}
				if (s1[i] == 'X')
				{
					conv.xx = diff_u_return(&conv);
					if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 1)
						compteur += print_zero(conv.flags.largeur - ft_strlen(conv_hexa_x(conv.xx)));
					if (conv.xx != 0 && conv.flags.htag == 1)
						compteur += ft_putstr("0X");
					if (conv.flags.point == 1)
					{
						sub_p = diff_for_precision(conv.flags.precision, ft_strlen(conv_hexa_x(conv.xx)), 0);
						if (conv.flags.precision > 0)
							compteur += print_space(conv.flags.largeur - (ft_strlen(conv_hexa_x(conv.xx)) + sub_p));
						compteur += print_zero(sub_p);
					}
					if (conv.flags.point == 1 && conv.flags.precision <= 0)
						;
					else
						compteur += ft_putstr(conv_hexa_x(conv.xx));
				}
				if (s1[i] == 'p')
				{
					conv.p = va_arg(conv.arg.ap, void*);
					if (conv.p == 0)
					{

						if (conv.flags.point == 1 && conv.flags.precision < 1)
						{
							compteur += ft_putstr("0x");
						}
						else
						{
							if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 0)
								compteur += print_space(conv.flags.largeur - (ft_strlen(conv_hexa((ull)conv.p)) + 2));
							compteur += ft_putstr("0x0");
							if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 1)
								compteur += print_zero(conv.flags.largeur - (ft_strlen(conv_hexa((ull)conv.p)) + 2));
							if (conv.flags.largeur > 0 && conv.flags.moins == 1 && conv.flags.zero == 0)
								compteur += print_space(conv.flags.largeur - (ft_strlen(conv_hexa((ull)conv.p)) + 2));
							if (conv.flags.point == 1 && conv.flags.precision > 0)
								compteur += print_zero(conv.flags.precision - ft_strlen(conv_hexa((ull)conv.p)));
						}
					}
					else
					{
						if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 0)
							compteur += print_space(conv.flags.largeur - (ft_strlen(conv_hexa((ull)conv.p)) + 2));
						compteur += ft_putstr("0x");
						if (conv.flags.point == 1 && conv.flags.precision > 0)
							compteur += print_zero(conv.flags.precision - ft_strlen(conv_hexa((ull)conv.p)));
						if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 1)
							compteur += print_zero(conv.flags.largeur - (ft_strlen(conv_hexa((ull)conv.p)) + 2));
						compteur += ft_putstr(conv_hexa((ull)conv.p));
						if (conv.flags.largeur > 0 && conv.flags.moins == 1 && conv.flags.zero == 0)
							compteur += print_space(conv.flags.largeur - (ft_strlen(conv_hexa((ull)conv.p)) + 2));
					}
				}
				if (s1[i] == '%')
				{
					if (conv.flags.largeur > 0 && conv.flags.zero == 1)
						compteur += print_zero(conv.flags.largeur - 1);
					if (conv.flags.largeur > 0 && conv.flags.zero == 0)
						compteur += print_space(conv.flags.largeur - 1);
					compteur += ft_putchar('%');
				}
			}
			
			if (s1[i] == ' ' && check_all_option(s1[i]) != 1)
				i++;
			else if (s1[i] == '\0')
			{
				ft_putchar('\n');
				return (compteur);
			}
			else if (check_all_option(s1[i]) == 0)
			{
				if (conv.flags.largeur > 0 && conv.flags.zero == 1)
					compteur += print_zero(conv.flags.largeur - 1);
				if (conv.flags.largeur > 0 && conv.flags.zero == 0 && conv.flags.moins == 0)
					compteur += print_space(conv.flags.largeur - 1);
				compteur += ft_putchar(s1[i]);
				if (conv.flags.largeur > 0 && conv.flags.zero == 0 && conv.flags.moins == 1)
					compteur += print_space(conv.flags.largeur - 1);
				i++;
			}
			else
				i++;
		}
	}
	return (compteur);
}
