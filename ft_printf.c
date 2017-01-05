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

	i = 0;
	sub_p = 0;
	compteur = 0;	s1 = (char *)format;
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
		//printf("debut i =%d, %zu\n", i, ft_strlen(s1));
		j = 0;
		ft_bzero(s2, ft_strlen(s2) + 1);
		while (s1[i] != '%' && s1[i] != '\0')
		{
			//printf("[s2 = %c, s1 = %c ]\n", s2[j], s1[i]);
			s2[j++] = s1[i++];
		}
		//printf("s1 = %s , j = %d, i = %d\n",s1,j, i);

		s2[j] = '\0';
		compteur += ft_putstr(s2);
		//printf("i =% d, %d\n", i, compteur);
		//printf("s1 = %s, s2 = %s\n", s1, s2);
		if (s1[i] == '%' && s1[i + 1] != '\0')
		{
			flags_initialization(&conv);
			i += flags_present(&conv, s1 + i + 1, 0);
			//printf("if start i =%d %s\n", i, &s1[i]);
			if (s1[i + 1] == 's')
			{
				conv.s = va_arg(conv.arg.ap, char*);
				if (conv.flags.largeur > 0 && conv.flags.zero == 1)
					compteur += print_zero(conv.flags.largeur - ft_strlen(conv.s));
				if (conv.s != NULL)
					compteur += ft_putstr(conv.s);
				else
					compteur += ft_putstr("(null)");
				format++;
			}
			if (s1[i + 1] == 'S')
			{
				conv.ss = va_arg(conv.arg.ap, wchar_t*);
				if (conv.ss != NULL)
				{
					while (conv.ss[k] != '\0')
					{
						compteur += nb_octets_write(conv.ss[k]);
						k++;
					}
				}
				else
				{
					compteur += ft_putstr("(null)");
				}
				format++;
			}
			if (s1[i + 1] == 'd' || s1[i + 1] == 'i')
			{
				conv.d = diff_return(&conv);
				//printf("%d %d %d %d\n",conv.flags.zero, conv.flags.moins, conv.flags.largeur, conv.flags.precision);
				if (conv.d >= 0 && conv.flags.plus == 1)
					compteur += ft_putchar('+');
				//printf("\n %d - %d = %d \n", conv.flags.largeur, ft_nb_digit(conv.d, conv.flags), conv.flags.largeur - ft_nb_digit(conv.d, conv.flags));
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
						compteur += print_zero(conv.flags.largeur - (ft_nb_digit(conv.d, conv.flags) + 1 + sub_p));
				}
				if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 1 && conv.flags.espace == 0)
				{
					if (conv.flags.plus == 1)
						compteur += print_zero(conv.flags.largeur - (ft_nb_digit(conv.d, conv.flags) + 1 + sub_p));
					else if (conv.d < 0)
					{
						//printf("%s\n", "test");
						conv.d = -conv.d;
						compteur += ft_putchar('-');
						compteur += print_zero(conv.flags.largeur - (ft_nb_digit(conv.d, conv.flags) + 1 + sub_p));
					}
					else
						compteur += print_zero(conv.flags.largeur - (ft_nb_digit(conv.d, conv.flags) + sub_p));
				}
				else if (conv.d < 0)
				{
					conv.d = -conv.d;
					compteur += ft_putchar('-');
				}
				
				compteur += print_zero(sub_p);
				if (conv.flags.point == 1 && conv.flags.precision <= 0)
					;
				else
					compteur += ft_putnbr(conv.d);
				if (conv.flags.largeur > 0 && conv.flags.moins == 1 /*&& conv.flags.zero == 0*/)
					compteur += print_space(conv.flags.largeur - (ft_nb_digit(conv.d, conv.flags) + sub_p));
				format++;
			}
			if (s1[i + 1] == 'D')
			{
				conv.dd = va_arg(conv.arg.ap, li);
				compteur += ft_putnbr(conv.dd);
				if (conv.dd == (-9223372036854775807 - 1))
					compteur = 20;
				format++;
			}
			if (s1[i + 1] == 'c')
			{
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
					compteur += ft_putchar(conv.c);
				}
				format++;
			}
			if (s1[i + 1] == 'C')
			{
				conv.cc = va_arg(conv.arg.ap, wint_t);
				compteur += nb_octets_write(conv.cc);
				format++;
			}
			if (s1[i + 1] == 'u')
			{
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
				//ft_nb_digit_u(conv.u, conv.flags);
				if (conv.flags.point == 1 &&conv.flags.precision <= 0)
					;
				else
					compteur += ft_putnbr(conv.u);
				//compteur += ft_putnbr_u(conv.u);
				format++;
			}
			if (s1[i + 1] == 'U')
			{
				conv.uu = va_arg(conv.arg.ap, uli);
				ft_nb_digit_u(conv.u, conv.flags);
				compteur += ft_putnbr_u(conv.uu);
				format++;
			}
			if (s1[i + 1] == 'o')
			{
				
				conv.o = diff_u_return(&conv);
				conv.o = conv_octal(conv.o);
				if (conv.o > 0 && conv.flags.htag == 1)
					compteur += ft_putchar('0');
				ft_nb_digit_u(conv.o, conv.flags);
				compteur += ft_putnbr_u(conv.o);
				format++;
			}
			if (s1[i + 1] == 'O')
			{
				conv.oo = va_arg(conv.arg.ap, uli);
				if (conv.oo == 9223372036854775807)
				{
					ft_putstr("777777777777777777777");
					compteur += 21;
				}
				else
				{
					conv.oo = conv_octal(conv.oo);
					if (conv.oo > 0 && conv.flags.htag == 1)
						compteur += ft_putchar('0');
					compteur += ft_putnbr(conv.oo);
				}
				format++;
			}
			if (s1[i + 1] == 'x')
			{
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
				ft_nb_digit_u(conv.x, conv.flags);
				compteur += ft_putstr(conv_hexa(conv.x));
				format++;
			}
			if (s1[i + 1] == 'X')
			{
				conv.xx = diff_u_return(&conv);
				if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 1)
					compteur += print_zero(conv.flags.largeur - ft_strlen(conv_hexa_X(conv.xx)));
				if (conv.xx != 0 && conv.flags.htag == 1)
					compteur += ft_putstr("0X");
				ft_nb_digit_u(conv.xx, conv.flags);
				compteur += ft_putstr(conv_hexa_X(conv.xx));
				format++;
			}
			if (s1[i + 1] == 'p')
			{
				conv.p = va_arg(conv.arg.ap, void*);
				if (conv.p == 0)
				{
					if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 0)
						compteur += print_space(conv.flags.largeur - (ft_strlen(conv_hexa((unsigned int)conv.p)) + 2));
					ft_putstr("0x0");
					if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 1)
						compteur += print_zero(conv.flags.largeur - (ft_strlen(conv_hexa((unsigned int)conv.p)) + 2));
					if (conv.flags.largeur > 0 && conv.flags.moins == 1 && conv.flags.zero == 0)
						compteur += print_space(conv.flags.largeur - (ft_strlen(conv_hexa((unsigned int)conv.p)) + 2));
					compteur += 3;
				}
				else if (conv.flags.fl == 1)
				{
					if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 0)
						compteur += print_space(conv.flags.largeur - (ft_strlen(conv_hexa((unsigned int)conv.p)) + 2));
					compteur += ft_putstr("0x");
					if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 1)
						compteur += print_zero(conv.flags.largeur - (ft_strlen(conv_hexa((unsigned int)conv.p)) + 2));
					compteur += ft_putstr(conv_hexa((unsigned int)conv.p));
					if (conv.flags.largeur > 0 && conv.flags.moins == 1 && conv.flags.zero == 0)
						compteur += print_space(conv.flags.largeur - (ft_strlen(conv_hexa((unsigned int)conv.p)) + 2));
				}
				else
				{
					if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 0)
						compteur += print_space(conv.flags.largeur - (ft_strlen(conv_hexa((unsigned int)conv.p)) + 6));
					compteur += ft_putstr("0x7fff");
					if (conv.flags.largeur > 0 && conv.flags.moins == 0 && conv.flags.zero == 1)
						compteur += print_zero(conv.flags.largeur - (ft_strlen(conv_hexa((unsigned int)conv.p)) + 6));
					compteur += ft_putstr(conv_hexa((unsigned int)conv.p));
					if (conv.flags.largeur > 0 && conv.flags.moins == 1 && conv.flags.zero == 0)
						compteur += print_space(conv.flags.largeur - (ft_strlen(conv_hexa((unsigned int)conv.p)) + 6));
				}
				format++;
			}
			if (s1[i + 1] == '%')
			{
				compteur += ft_putchar('%');
			}
			//printf("test2 %d / %d\n", check_flag(s1[i]), ft_isdigit(s1[i]));
			if (s1[i + 1] == ' ' && s1[i + 2] == '%')
			{
				compteur += ft_putchar('%');
				i += 3;
			}
			else if (s1[i] == ' ' && check_flag(s1[i + 1]) != 1)
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
				compteur += ft_putchar(s1[i]);
				i++;
			}
			else
				i += 2;
			//printf("ifend i = %d\n", i);
		}
		//printf("fin i = %d\n", i);
	}
	return (compteur);
}
