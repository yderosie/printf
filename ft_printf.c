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

unsigned int	count_c_bin(unsigned int i)
{
	unsigned int j;
	unsigned int k;

	j = 0;
	while (i >= 2)
	{
		k = i;
		i = i / 2;
		k = (k % 2);
		j++;
	}
	j += 2;
	return (j);
}

void		binary_to_decimal(char *s)
{
	char	*s1;
	int		i;
	int		j;
	int		k;
	int		l;

	i = 0;
	j = 0;
	k = 0;
	l = 1;
	s1 = ft_inverse(s);
	while (s1[i] != '\0')
	{
		if (s1[i] == '1')
		{
			while (k < i)
			{
				l = l * 2;
				k++;
			}
			j = j + l;
		}
		i++;
	}
	write(1, &j, 1);
}

char	*binary(unsigned int j)
{
	char			*s1;
	int				i;
	unsigned int	k;
	char			*s2;

	i = 0;
	s1 = (char *)malloc(sizeof(char) * (count_c_bin(j)));
	while  (j >= 2)
	{
		k = j;
		j = j / 2;
		k = (k % 2);
		s1[i] = k + '0';
		i++;
	}
	s1[i] = j + '0';
	s2 = ft_inverse(s1);
	return (s2);
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

unsigned int	count_c_hexa(unsigned int i)
{
	unsigned int j;
	unsigned int k;

	j = 0;
	while (j >= 16)
	{
		k = i;
		i = i / 16;
		k = (k % 16);
		j++;
	}
	j += 2;
	return (j);
}

uli		count_c_octal_O(uli i)
{
	uli j;
	uli k;

	j = 0;
	while (j >= 8)
	{
		k = i;
		i = i / 8;
		k = (k % 8);
		j++;
	}
	j += 2;
	return (j);
}

unsigned int	count_c_octal(unsigned int i)
{
	unsigned int j;
	unsigned int k;

	j = 0;
	while (j >= 8)
	{
		k = i;
		i = i / 8;
		k = (k % 8);
		j++;
	}
	j += 2;
	return (j);
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

char	*conv_hexa_p_X_h(void *j)
{
	char			*s1;
	int				i;
	unsigned int	*m;
	char			*s2;
	unsigned int	l;
	unsigned int	k;

	m = (unsigned int*)j;
	l = m[1];
	i = 0;
	s1 = (char *)malloc(sizeof(char) * (count_c_hexa(l)));
	while  (l >= 16)
	{
		k = l;
		l = l / 16;
		k = (k % 16);
		s1[i] = if_forest_hexa(k);
		i++;
	}
	s1[i] = if_forest_hexa(l);
	s2 = ft_inverse(s1);
	free(s1);
	return (s2);
}

char	*conv_hexa_X(unsigned int j)
{
	char			*s1;
	int				i;
	unsigned int	k;
	char			*s2;

	i = 0;
	s1 = (char *)malloc(sizeof(char) * (count_c_hexa(j)));
	while  (j >= 16)
	{
		k = j;
		j = j / 16;
		k = (k % 16);
		s1[i] = if_forest_hexa_X(k);
		i++;
	}
	s1[i] = if_forest_hexa_X(j);
	s2 = ft_inverse(s1);
	return (s2);
}

char	*conv_hexa(unsigned int j)
{
	char			*s1;
	int				i;
	unsigned int	k;
	char			*s2;

	i = 0;
	s1 = (char *)malloc(sizeof(char) * (count_c_hexa(j)));
	while  (j >= 16)
	{
		k = j;
		j = j / 16;
		k = (k % 16);
		s1[i] = if_forest_hexa(k);
		i++;
	}
	s1[i] = if_forest_hexa(j);
	
	s2 = ft_inverse(s1);
	return (s2);
}

unsigned int	conv_octal_O(uli j)
{
	char			*s1;
	int				i;
	uli				k;
	char			*s2;

	i = 0;
	s1 = (char *)malloc(sizeof(char) * (count_c_octal_O(j)));
	while  (j >= 8)
	{
		k = j;
		j = j / 8;
		k = (k % 8);
		s1[i] = k + '0';
		i++;
	}
	s1[i] = j + '0';
	s2 = ft_inverse(s1);
	j = ft_atoi(s2);
	return (j);
}

unsigned int	conv_octal(unsigned int j)
{
	char			*s1;
	int				i;
	unsigned int	k;
	char			*s2;

	i = 0;
	s1 = (char *)malloc(sizeof(char) * (count_c_octal(j)));
	while  (j >= 8)
	{
		k = j;
		j = j / 8;
		k = (k % 8);
		s1[i] = k + '0';
		i++;
	}
	s1[i] = j + '0';
	s2 = ft_inverse(s1);
	j = ft_atoi(s2);
	return (j);
}

void	flags_present_2(t_conv *conv, char *s1, int i, int j)
{
	j = 0;
	if (s1[i] == 'h' && s1[i + 1] != 'h')
		conv->flags.fh = 1;
	if (s1[i] == 'h' && s1[i + 1] == 'h')
	{
		conv->flags.fhh = 1;
		i +=1;
	}
	if (s1[i] == 'l' && s1[i + 1] != 'l')
		conv->flags.fl= 1;
	if (s1[i] == 'l' && s1[i + 1] == 'l')
	{
		conv->flags.fll = 1;
		i += 1;
	}
	if (s1[i] == 'j')
		conv->flags.j = 1;
	
	if (s1[i] == '.')
	{
		while (ft_isdigit(s1[i + j + 1]))
			s2[j] = s1[i + (j++) + 1];
		conv->flags.precision = ft_atoi(s2);
	}
}

int		flags_present(t_conv *conv, char *s1, int i)
{
	char	*s2;
	int		j;

	s2 = (char *)malloc(sizeof(char) * ft_strlen(s1));
	while (s1[i] != 's' && s1[i] != 'S' && s1[i] != 'p' && s1[i] != 'd'
		&& s1[i] != 'D' && s1[i] != 'i' && s1[i] != 'o' && s1[i] != 'O'
			&& s1[i] != 'u' && s1[i] != 'U' && s1[i] != 'x' && s1[i] != 'X' &&
			s1[i] != 'c' && s1[i] != 'C' && s1[i] != '\0' && s1[i] != '%')
	{
		if (s1[i] == '0')
			conv->flags.zero = 1; 
		if (s1[i] == '#')
			conv->flags.htag = 1;
		if (s1[i] == '+')
			conv->flags.plus = 1;
		if (s1[i] == ' ')
			conv->flags.espace = 1;
		if (s1[i] == 'z')
			conv->flags.z = 1;
		if (s1[i] == '-')
			conv->flags.moins = 1;
		flags_present_2(conv, s1, i, j);
		i++;
	}
	return (i);
}

void	flags_initialization(t_conv *conv)
{
	conv->flags.zero = 0;
	conv->flags.htag = 0;
	conv->flags.espace = 0;
	conv->flags.moins = 0;
	conv->flags.plus = 0;
	conv->flags.precision = 0;
	conv->flags.fhh = 0;
	conv->flags.fh = 0;
	conv->flags.fl = 0;
	conv->flags.fll = 0;
	conv->flags.j = 0;
	conv->flags.z = 0;
}

ull		diff_return(t_conv  conv)
{
	
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
			i += flags_present(&conv, s1, i + 1);
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
				if (conv.flags.fhh == 1)
					conv.d = (char)va_arg(conv.arg.ap, int);
				else if (conv.flags.fh == 1)
					conv.d = (short)va_arg(conv.arg.ap, int);
				else
					conv.d = va_arg(conv.arg.ap, int);
				if (conv.d > 0 && conv.flags.espace == 1)
					ft_putchar(' ');
				if (conv.d > 0 && conv.flags.plus == 1)
					ft_putchar('+');
				if (conv.flags.precision > 0)
					ft_nb_digit(conv.d, conv.flags);
				ft_putnbr(conv.d);
				format++;
			}
			if (s1[i + 1] == 'D')
			{
				conv.dd = va_arg(conv.arg.ap, li);
				ft_putnbr_li(conv.dd);
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
				conv.cc = va_arg(conv.arg.ap, wchar_t);
				nb_octets_write(conv.cc);
				format++;
			}
			if (s1[i + 1] == 'u')
			{
				if (conv.flags.fhh == 1)
					conv.u = (unsigned char) va_arg(conv.arg.ap, unsigned int);
				else if (conv.flags.fh == 1)
					conv.u = (unsigned short) va_arg(conv.arg.ap, unsigned int);
				else
					conv.u = va_arg(conv.arg.ap, unsigned int);
				if (conv.flags.precision > 0)
					ft_nb_digit_u(conv.u, conv.flags);
				ft_putnbr_u(conv.u);
				format++;
			}
			if (s1[i + 1] == 'U')
			{
				conv.uu = va_arg(conv.arg.ap, uli);
				if (conv.flags.precision > 0)
					ft_nb_digit(conv.u, conv.flags);
				ft_putnbr_uli(conv.uu);
				format++;
			}
			if (s1[i + 1] == 'o')
			{
				
				if (conv.flags.fhh == 1)
					conv.o = (unsigned char) va_arg(conv.arg.ap, unsigned int);
				else if (conv.flags.fh == 1)
					conv.o = (unsigned short) va_arg(conv.arg.ap, unsigned int);
				else
					conv.o = va_arg(conv.arg.ap, unsigned int);
				conv.o = conv_octal(conv.o);
				if (conv.o > 0 && conv.flags.htag == 1)
					ft_putchar('0');
				if (conv.flags.precision > 0)
					ft_nb_digit_u(conv.o, conv.flags);
				ft_putnbr_u(conv.o);
				format++;
			}
			if (s1[i + 1] == 'O')
			{
				conv.oo = va_arg(conv.arg.ap, uli);
				conv.oo = conv_octal_O(conv.oo);
				if (conv.oo > 0 && conv.flags.htag == 1)
					ft_putchar('0');
				ft_putnbr_li(conv.oo);
				format++;
			}
			if (s1[i + 1] == 'x')
			{
				if (conv.flags.fhh == 1)
					conv.x = (unsigned char) va_arg(conv.arg.ap, unsigned int);
				else if (conv.flags.fh == 1)
					conv.x = (unsigned short) va_arg(conv.arg.ap, unsigned int);
				else
					conv.x = va_arg(conv.arg.ap, unsigned int);
				if (conv_hexa(conv.x)[0] != 0 && conv.flags.htag == 1)
					ft_putstr("0x");
				if (conv.flags.precision > 0)
					ft_nb_digit_u(conv.x, conv.flags);
				ft_putstr(conv_hexa(conv.x));
				compteur += ft_strlen(conv_hexa(conv.x));
				format++;
			}
			if (s1[i + 1] == 'X')
			{
				conv.xx = va_arg(conv.arg.ap, unsigned int);
				if (conv_hexa(conv.x)[0] != 0 && conv.flags.htag == 1)
					ft_putstr("0X");
				if (conv.flags.precision > 0)
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
