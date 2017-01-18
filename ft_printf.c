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

int		print_space(int i)
{
	int rt;

	rt = 0;
	while (i > 0)
	{
		rt += ft_putchar(' ');
		i--;
	}
	return (rt);
}

int		print_zero(int i)
{
	int rt;

	rt = 0;
	while (i > 0)
	{
		rt += ft_putchar('0');
		i--;
	}
	return (rt);
}

char	if_forest_hexa_X(unsigned int k)
{
	if (k < 10)
		return (k + '0');
	else if (k == 10)
		return ('A');
	else if (k == 11)
		return ('B');
	else if (k == 12)
		return ('C');
	else if (k == 13)
		return ('D');
	else if (k == 14)
		return ('E');
	else
		return ('F');
}

char	if_forest_hexa(unsigned int k)
{
	if (k < 10)
		return (k + '0');
	else if (k == 10)
		return ('a');
	else if (k == 11)
		return ('b');
	else if (k == 12)
		return ('c');
	else if (k == 13)
		return ('d');
	else if (k == 14)
		return ('e');
	else
		return ('f');
}

int		precision_for_S(wchar_t c, unsigned int rt, t_flags flags)
{
	if (c <= 0x7F)
		rt += 1;
	else if (c <= 0x7FF)
		rt += 2;
	else if (c <= 0xFFFF)
		rt += 3;
	else
		rt += 4;
	return (rt);
}

int		diff_precision_s(wchar_t *s, t_flags flags)
{
	int len;
	int i;

	len = 0;
	i = 1;
	if (precision_for_S(s[0], len, flags) <= flags.precision)
	{
		len = precision_for_S(s[0], len, flags);
		//printf("{(len 0 = %d) c = %C}\n", len, s[0]);
		while (s[i] != '\0' && len <= flags.precision)
		{
			len = precision_for_S(s[i++], len, flags);
			//printf("{[ i == %d]}\n", i);
		}
		//printf("{(len 1 = %d) c = %C}\n", len, s[i - 1]);
		if (len > flags.precision)
		{
			len = len - precision_for_S(s[i - 1], 0, flags);
			return (flags.precision + (len - flags.precision));
		}
		//printf("(len 2 = %d)\n", len);
	}
	//printf("{return = %d}\n", len + (flags.precision - len));
	return (flags.precision);

}

size_t	tab_0(char *s1, char *tab)
{
	int		i;
	int		j;
	int		l;
	char	**s2;
	size_t	rt;

	l = 0;
	rt = 0;
	i = ft_strlen(tab) - 1;
	j = ft_strlen(s1) - 1;
	while (j >= 0 && i >= 0)
	{
		if (tab[i] == 'x')
			tab[i--] = s1[j--];
		else
			i--;
	}
	i = 0;
	while (tab[i] != '\0')
	{
		if (tab[i] == 'x')
			tab[i] = '0';
		i++;
	}
	s2 = ft_strsplit(tab, ' ');
	while (s2[l] != '\0')
		rt += binary_to_decimal(s2[l++]);
	return (rt);
}

size_t	nb_octets_write_2(unsigned int i)
{
	char	**tab;
	char	*s1;
	char	*s2;

	s2 = (char*)malloc(sizeof(char) * 37);
	tab = (char**)malloc(sizeof(char *) * 3);
	tab[0] = "110xxxxx 10xxxxxx";
	s2 = ft_strcpy(s2, tab[0]);
	tab[1] = "1110xxxx 10xxxxxx 10xxxxxx";
	tab[2] = "11110xxx 10xxxxxx 10xxxxxx 10xxxxxx";
	s1 = binary(i);
	if (i <= 0x7FF)
	{
		s2 = ft_strcpy(s2, tab[0]);
		return (tab_0(s1, s2));
	}
	else if (i <= 0xFFFF)
	{
		s2 = ft_strcpy(s2, tab[1]);
		return (tab_0(s1, s2));
	}
	else
	{
		s2 = ft_strcpy(s2, tab[2]);
		return (tab_0(s1, s2));
	}
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
	return(0);
}

char *ft_inverse(char *s)
{
	int i;
	int j;
	char *s2;

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
			//printf("(avant i == %d)\n", i);
			i += flags_present(&conv, s1 + i + 1, 0) + 1;
			//printf("(qpres i == %d, %c)\n", i, s1[i]);
			if (check_flag(s1[i]) == 1)
			{
				if (s1[i] == 's' && conv.flags.fl == 0)
				{
					//printf("%c\n", 's');
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
					{
						compteur += print_zero(conv.flags.largeur);
					}
					else
						compteur += ft_putstr("(null)");
					format++;
				}
				if (s1[i] == 'S' || (s1[i] == 's' && conv.flags.fl == 1))
				{
					//printf("%c\n", 'S');
					int len;
					len = 0;
					conv.ss = va_arg(conv.arg.ap, wchar_t*);
					if (conv.ss != NULL)
					{
						if (conv.flags.point == 1 && conv.flags.precision < ft_strlen_for_wchar(conv.ss))
							sub_for_s = /*conv.flags.precision;*/ diff_precision_s(conv.ss, conv.flags);
						else
							sub_for_s = ft_strlen_for_wchar(conv.ss);
						if (conv.flags.largeur > 0 && conv.flags.zero == 1 && conv.flags.moins == 0)
							compteur += print_zero(conv.flags.largeur - sub_for_s);
						if (conv.flags.largeur > 0 && conv.flags.zero == 0 && conv.flags.moins == 0)
							compteur += print_space(conv.flags.largeur - sub_for_s);
						//printf("%d\n", sub_for_s);
						while (conv.ss[k] != '\0')
						{
							if (conv.flags.point == 0)
								len += nb_octets_write(conv.ss[k]);
							else if (conv.flags.point == 1 && precision_for_S(conv.ss[k], len, conv.flags) <= conv.flags.precision)
								len += nb_octets_write(conv.ss[k]);
							k++;
						}
						compteur += len;
						if (conv.flags.largeur > 0 && conv.flags.zero == 0 && conv.flags.moins == 1)
							compteur += print_space(conv.flags.largeur - ft_strlen_for_wchar(conv.ss));
					}
					else
					{
						compteur += ft_putstr("(null)");
					}
					format++;
				}
				if (s1[i] == 'd' || s1[i] == 'i')
				{
					//printf("%c\n", 'd');
					conv.d = diff_return(&conv);
					//printf("%d %d %d %d\n",conv.flags.zero, conv.flags.moins, conv.flags.largeur, conv.flags.precision);
					if (conv.d >= 0 && conv.flags.plus == 1)
						compteur += ft_putchar('+');
					if (conv.flags.point == 1)
					{
						sub_p = conv.flags.precision - ft_nb_digit(conv.d, conv.flags);
						sub_p = (conv.d < 0) ? sub_p + 1 : sub_p; 
						sub_p = (sub_p > 0) ? sub_p : 0;
					}
					if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 0)
						compteur += print_space(conv.flags.largeur - (ft_nb_digit(conv.d, conv.flags) + sub_p));
					if (conv.d >= 0 && conv.flags.espace == 1 && conv.flags.plus == 0)
					{
						compteur += ft_putchar(' ');
						if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 1)
						{
							compteur += print_zero(conv.flags.largeur - (ft_nb_digit(conv.d, conv.flags) + 1 + sub_p));
						}
					}
					if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 1 && conv.flags.espace == 0)
					{
						if (conv.flags.plus == 1)
							compteur += print_zero(conv.flags.largeur - (ft_nb_digit(conv.d, conv.flags) + 1 + sub_p));
						else if (conv.d < 0)
						{
							conv.d = conv.d * -1;
							compteur += ft_putchar('-');
							compteur += print_zero(conv.flags.largeur - (ft_nb_digit(conv.d, conv.flags) + 1 + sub_p));
						}
						else
						{
							if (conv.flags.point == 1)
							{
								compteur += print_space(conv.flags.largeur - (ft_nb_digit(conv.d, conv.flags) + sub_p));
							}
							else
								compteur += print_zero(conv.flags.largeur - (ft_nb_digit(conv.d, conv.flags) + sub_p));
						}
					}
					else if (conv.d < 0 && conv.d > -9223372036854775807 - 1)
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
						compteur += print_space(conv.flags.largeur - (ft_nb_digit(conv.d, conv.flags) + sub_p));
					format++;
				}
				if (s1[i] == 'D')
				{
					//printf("%c\n", 'D');
					conv.dd = va_arg(conv.arg.ap, li);
					compteur += ft_putnbr(conv.dd);
					if (conv.dd == (-9223372036854775807 - 1))
						compteur = 20;
					format++;
				}
				if (s1[i] == 'c')
				{
					//printf("%c\n", 'c');
					if (conv.d > 0 && conv.flags.fl == 1)
					{
						conv.cc = va_arg(conv.arg.ap, wint_t);
						if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 0)
							compteur += print_space(conv.flags.largeur - ft_nb_digit(conv.cc, conv.flags));
						compteur += nb_octets_write(conv.cc);
					}
					else
					{
						conv.c = va_arg(conv.arg.ap, int);
						if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 0)
							compteur += print_space(conv.flags.largeur - ft_nb_digit(conv.c, conv.flags));
						if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 1)
							compteur += print_zero(conv.flags.largeur - ft_nb_digit(conv.c, conv.flags));
						compteur += ft_putchar(conv.c);
					}
					format++;
				}
				if (s1[i] == 'C')
				{
					//printf("%c\n", 'C');
					conv.cc = va_arg(conv.arg.ap, wint_t);
					compteur += nb_octets_write(conv.cc);
					format++;
				}
				if (s1[i] == 'u')
				{
					//printf("%c\n", 'u');
					conv.u = diff_u_return(&conv);
					if (conv.flags.point == 1)
					{
						//printf("%s\n", "test");
						sub_p = conv.flags.precision - ft_nb_digit(conv.u, conv.flags);
						sub_p = (sub_p > 0) ? sub_p : 0;
						if (conv.flags.precision > 0)
							compteur += print_space(conv.flags.largeur - (ft_nb_digit_u(conv.u, conv.flags) + sub_p));
						compteur += print_zero(sub_p);
					}

					//printf("%lu\n", conv.u);
					if (conv.flags.point == 1 && conv.flags.precision <= 0)
						;
					else
						compteur += ft_putnbr_u(conv.u);
					format++;
				}
				if (s1[i] == 'U')
				{
					//printf("%c\n", 'U');
					conv.uu = va_arg(conv.arg.ap, uli);
					ft_nb_digit_u(conv.u, conv.flags);
					compteur += ft_putnbr_u(conv.uu);
					format++;
				}
				if (s1[i] == 'o')
				{
					//printf("%c\n", 'o');
					//printf("[%llu]\n", va_arg(conv.arg.ap, ull));
					conv.o = diff_u_return(&conv);
					if (conv.o == 18446744073709551615)
					{
						compteur += ft_putstr("1777777777777777777777");
					}
					else
					{
						conv.o = conv_octal(conv.o);
						if (conv.o > 0 && conv.flags.htag == 1 && conv.flags.precision == 0)
							compteur += ft_putchar('0');
						if (conv.flags.point == 1)
						{
							sub_p = conv.flags.precision - ft_nb_digit(conv.o, conv.flags);
							sub_p = (sub_p > 0) ? sub_p : 0;
							if (conv.flags.precision > 0)
								compteur += print_space(conv.flags.largeur - (ft_nb_digit_u(conv.o, conv.flags) + sub_p));
							compteur += print_zero(sub_p);
						}
						if (conv.flags.point == 1 && conv.flags.precision <= 0 && conv.flags.htag == 0)
							;
						else
							compteur += ft_putnbr_u(conv.o);
						format++;
					}
				}
				if (s1[i] == 'O')
				{
					conv.oo = va_arg(conv.arg.ap, uli);
					if (conv.oo == 9223372036854775806 + 1)
					{
						compteur += ft_putstr("777777777777777777777");
					}
					else if (conv.oo == -9223372036854775808)
					{
						compteur += ft_putstr("1000000000000000000000");
					}
					else
					{
						conv.oo = conv_octal(conv.oo);
						if (conv.flags.htag == 1)
							compteur += ft_putchar('0');
						if (conv.flags.point == 1)
						{
							sub_p = conv.flags.precision - ft_nb_digit(conv.oo, conv.flags);
							sub_p = (sub_p > 0) ? sub_p : 0;
							if (conv.flags.precision > 0)
								compteur += print_space(conv.flags.largeur - (ft_nb_digit_u(conv.oo, conv.flags) + sub_p));
							compteur += print_zero(sub_p);
						}
						if (conv.flags.point == 1 && conv.flags.precision <= 0)
							;
						else
							compteur += ft_putnbr_u(conv.oo);
					}
					format++;
				}
				if (s1[i] == 'x')
				{
					//printf("%c\n", 'x');
					conv.x = diff_u_return(&conv);
					if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 1)
					{
						if (conv.x != 0 && conv.flags.htag == 1)
							compteur += print_zero(conv.flags.largeur - (ft_strlen(conv_hexa_X(conv.x)) + 2));
						else
							compteur += print_zero(conv.flags.largeur - ft_strlen(conv_hexa_X(conv.x)));
					}
					if (conv.x != 0 && conv.flags.htag == 1)
						compteur += ft_putstr("0x");
					if (conv.flags.point == 1)
					{
						sub_p = conv.flags.precision - ft_strlen(conv_hexa_X(conv.x));
						sub_p = (sub_p >= 0) ? sub_p : 0;
						if (conv.flags.precision > 0)
							compteur += print_space(conv.flags.largeur - (ft_strlen(conv_hexa_X(conv.x)) + sub_p));
						compteur += print_zero(sub_p);
					}
					if (conv.flags.point == 1 && conv.flags.precision <= 0)
						;
					else
						compteur += ft_putstr(conv_hexa(conv.x));
					format++;
				}
				if (s1[i] == 'X')
				{
					//printf("%c\n", 'X');
					conv.xx = diff_u_return(&conv);
					if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 1)
						compteur += print_zero(conv.flags.largeur - ft_strlen(conv_hexa_X(conv.xx)));
					if (conv.xx != 0 && conv.flags.htag == 1)
						compteur += ft_putstr("0X");
					if (conv.flags.point == 1)
					{
						sub_p = conv.flags.precision - ft_strlen(conv_hexa_X(conv.xx));
						sub_p = (sub_p > 0) ? sub_p : 0;
						if (conv.flags.precision > 0)
							compteur += print_space(conv.flags.largeur - (ft_strlen(conv_hexa_X(conv.xx)) + sub_p));
						compteur += print_zero(sub_p);
					}
					//printf("{s = %s}\n", conv_hexa_X(conv.xx));
					if (conv.flags.point == 1 && conv.flags.precision <= 0)
						;
					else
						compteur += ft_putstr(conv_hexa_X(conv.xx));
					format++;
				}
				if (s1[i] == 'p')
				{
					//printf("%c\n", 'p');
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
								compteur += print_space(conv.flags.largeur - (ft_strlen(conv_hexa((unsigned int)conv.p)) + 2));
							compteur += ft_putstr("0x0");
							if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 1)
								compteur += print_zero(conv.flags.largeur - (ft_strlen(conv_hexa((unsigned int)conv.p)) + 2));
							if (conv.flags.largeur > 0 && conv.flags.moins == 1 && conv.flags.zero == 0)
								compteur += print_space(conv.flags.largeur - (ft_strlen(conv_hexa((unsigned int)conv.p)) + 2));
							if (conv.flags.point == 1 && conv.flags.precision > 0)
								compteur += print_zero(conv.flags.precision - ft_strlen(conv_hexa((unsigned int)conv.p)));
						}
					}
					else if (conv.flags.fl == 1 || conv.flags.espace == 1 || conv.flags.plus == 1)
					{
						if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 0)
							compteur += print_space(conv.flags.largeur - (ft_strlen(conv_hexa((unsigned int)conv.p)) + 2));
						compteur += ft_putstr("0x");
						if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 1)
							compteur += print_zero(conv.flags.largeur - (ft_strlen(conv_hexa((unsigned int)conv.p)) + 2));
						compteur += ft_putstr(conv_hexa((ull)conv.p));
						if (conv.flags.largeur > 0 && conv.flags.moins == 1 && conv.flags.zero == 0)
							compteur += print_space(conv.flags.largeur - (ft_strlen(conv_hexa((unsigned int)conv.p)) + 2));
					}
					else if (conv.flags.point == 1 && conv.flags.precision > 1)
					{
						if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 0)
							compteur += print_space(conv.flags.largeur - (ft_strlen(conv_hexa((unsigned int)conv.p)) + 2));
						compteur += ft_putstr("0x");
						if (conv.flags.point == 1 && conv.flags.precision > 0)
								compteur += print_zero(conv.flags.precision - ft_strlen(conv_hexa((unsigned int)conv.p)));
						if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 1)
							compteur += print_zero(conv.flags.largeur - (ft_strlen(conv_hexa((unsigned int)conv.p)) + 2));
						compteur += ft_putstr(conv_hexa((ull)conv.p));
						if (conv.flags.largeur > 0 && conv.flags.moins == 1 && conv.flags.zero == 0)
							compteur += print_space(conv.flags.largeur - (ft_strlen(conv_hexa((unsigned int)conv.p)) + 2));
					}
					else
					{
						if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 0)
							compteur += print_space(conv.flags.largeur - (ft_strlen(conv_hexa((unsigned int)conv.p)) + 6));
						compteur += ft_putstr("0x");
						if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 1)
							compteur += print_zero(conv.flags.largeur - (ft_strlen(conv_hexa((unsigned int)conv.p)) + 6));
						compteur += ft_putstr(conv_hexa((ull)conv.p));
						if (conv.flags.largeur > 0 && conv.flags.moins == 1 && conv.flags.zero == 0)
							compteur += print_space(conv.flags.largeur - (ft_strlen(conv_hexa((unsigned int)conv.p)) + 6));
					}
					format++;
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
			//printf("[%c, %d]\n", s1[i], i);
			if (s1[i] == ' ' && s1[i + 2] == '%')
			{
				compteur += ft_putchar('%');
				i += 3;
			}
			else if (s1[i] == ' ' && check_flag(s1[i]) != 1)
			{
				i++;
			}
			else if (s1[i] == '\0')
			{
				ft_putchar('\n');
				return (compteur);
			}
			else if (check_flag(s1[i]) == 0)
			{
				if (conv.flags.largeur > 0 && conv.flags.zero == 1)
					compteur += print_zero(conv.flags.largeur - 1);
				if (conv.flags.largeur > 0 && conv.flags.zero == 0 && conv.flags.moins == 0)
					compteur += print_space(conv.flags.largeur - 1);
				//printf("[%c, %d]\n", s1[i], i);
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
