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

void	tab_0(char *s1, char *tab)
{
	int		i;
	int		j;
	int		l;
	char	**s2;

	l = 0;
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
		binary_to_decimal(s2[l++]);
}

void	nb_octets_write_2(unsigned int i)
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
		tab_0(s1, s2);
	}
	else if (i <= 0xFFFF)
	{
		s2 = ft_strcpy(s2, tab[1]);
		tab_0(s1, s2);
	}
	else
	{
		s2 = ft_strcpy(s2, tab[2]);
		tab_0(s1, s2);
	}
}

int		nb_octets_write(wchar_t c)
{
	unsigned int i;

	i = (unsigned int)c;
	if (i <= 0x7F)
		ft_putwchar(c);
	else if (i >= 0x7F && i <= 0x1FFFFF)
		nb_octets_write_2(i);
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

	i = 0;
	k = 0;
	compteur = 0;
	s1 = (char *)format;
	s2 = (char *)malloc(sizeof(char) * ft_strlen(format) + 1);
	va_start(conv.arg.ap, format);
	va_copy(conv.arg.save, conv.arg.ap);
	while (s1[i] != '\0')
	{
		j = 0;
		ft_bzero(s2, ft_strlen(s2));
		while (s1[i] != '%' && s1[i] != '\0')
			s2[j++] = s1[i++];
		ft_putstr(s2);
		compteur += ft_strlen(s2);
		if (s1[i] == '%')
		{
			flags_initialization(&conv);
			i += flags_present(&conv, s1 + i + 1, 0);
			if (s1[i + 1] == 's')
			{
				conv.s = va_arg(conv.arg.ap, char*);
				ft_putstr(conv.s);
				if (conv.s != NULL)
				{
					compteur += ft_strlen(conv.s);
				}
				else
					compteur += 6;
				format++;
			}
			if (s1[i + 1] == 'S')
			{
				conv.ss = va_arg(conv.arg.ap, wchar_t*);
				while (conv.ss[k] != '\0')
				{
					nb_octets_write(conv.ss[k]);
					k++;
				}
				format++;
			}
			if (s1[i + 1] == 'd' || s1[i] == 'i')
			{
				conv.d = diff_return(&conv);
				if (conv.d > 0 && conv.flags.espace == 1)
					ft_putchar(' ');
				if (conv.d > 0 && conv.flags.plus == 1)
					ft_putchar('+');
				ft_nb_digit(conv.d, conv.flags);
				ft_putnbr(conv.d);
				format++;
			}
			if (s1[i + 1] == 'D')
			{
				conv.dd = va_arg(conv.arg.ap, li);
				ft_putnbr(conv.dd);
				format++;
			}
			if (s1[i + 1] == 'c')
			{
				conv.c = va_arg(conv.arg.ap, int);
				ft_putchar(conv.c);
				compteur += 1;
				format++;
			}
			if (s1[i + 1] == 'C')
			{
				conv.cc = va_arg(conv.arg.ap, wint_t);
				nb_octets_write(conv.cc);
				format++;
			}
			if (s1[i + 1] == 'u')
			{
				conv.u = diff_u_return(&conv);
				ft_nb_digit_u(conv.u, conv.flags);
				ft_putnbr_u(conv.u);
				format++;
			}
			if (s1[i + 1] == 'U')
			{
				conv.uu = va_arg(conv.arg.ap, uli);
				ft_nb_digit_u(conv.u, conv.flags);
				ft_putnbr_u(conv.uu);
				format++;
			}
			if (s1[i + 1] == 'o')
			{
				
				conv.o = diff_u_return(&conv);
				conv.o = conv_octal(conv.o);
				if (conv.o > 0 && conv.flags.htag == 1)
					ft_putchar('0');
				ft_nb_digit_u(conv.o, conv.flags);
				ft_putnbr_u(conv.o);
				format++;
			}
			if (s1[i + 1] == 'O')
			{
				conv.oo = va_arg(conv.arg.ap, uli);
				conv.oo = conv_octal(conv.oo);
				if (conv.oo > 0 && conv.flags.htag == 1)
					ft_putchar('0');
				ft_putnbr(conv.oo);
				format++;
			}
			if (s1[i + 1] == 'x')
			{
				conv.x = diff_u_return(&conv);
				if (conv_hexa(conv.x)[0] != 0 && conv.flags.htag == 1)
					ft_putstr("0x");
				ft_nb_digit_u(conv.x, conv.flags);
				ft_putstr(conv_hexa(conv.x));
				compteur += ft_strlen(conv_hexa(conv.x));
				format++;
			}
			if (s1[i + 1] == 'X')
			{
				conv.xx = diff_u_return(&conv);
				if (conv_hexa(conv.x)[0] != 0 && conv.flags.htag == 1)
					ft_putstr("0X");
				ft_nb_digit_u(conv.xx, conv.flags);
				ft_putstr(conv_hexa_X(conv.xx));
				compteur += ft_strlen(conv_hexa_X(conv.xx));
				format++;
			}
			if (s1[i + 1] == 'p')
			{
				conv.p = va_arg(conv.arg.ap, void*);
				ft_putstr("0x7fff");
				ft_putstr(conv_hexa_p_X_h(conv.p));
				format++;
			}
			if (s1[i + 1] == '%')
			{
				ft_putchar('%');
			}
			i += 2;
		}
	}
	return (compteur);
}
