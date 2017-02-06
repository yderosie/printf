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
	unsigned int		count;

	i = 0;
	count = 0;
	s1 = (char *)format;
	s2 = (char *)malloc(sizeof(char) * ft_strlen(format) + 1);
	va_start(conv.arg.ap, format);
	va_copy(conv.arg.save, conv.arg.ap);
	while (s1[i] != '\0')
	{
		if (ft_strlen(s1) == 1 && s1[0] == '%')
			return (0);
		j = 0;
		ft_bzero(s2, ft_strlen(s2) + 1);
		while (s1[i] != '%' && s1[i] != '\0')
			s2[j++] = s1[i++];
		s2[j] = '\0';
		count += ft_putstr(s2);
		if (s1[i] == '%' && s1[i + 1] != '\0')
		{
			flags_initialization(&conv);
			i += flags_present(&conv, s1 + i + 1, 0) + 1;
			if (check_conv(s1[i]) == 1)
			{
				if (s1[i] == 's' && conv.flags.fl == 0)
					conv_s(&conv, &count);
				if (s1[i] == 'S' || (s1[i] == 's' && conv.flags.fl == 1))
					conv_ss(&conv, &count, 0);
				if (s1[i] == 'd' || s1[i] == 'i')
					conv_d(&conv, &count, 0);
				if (s1[i] == 'D')
					conv_dd(&conv, &count, 0);
				if (s1[i] == 'c')
					conv_c(&conv, &count);
				if (s1[i] == 'C')
					conv_cc(&conv, &count);
				if (s1[i] == 'u')
					conv_u(&conv, &count, 0);
				if (s1[i] == 'U')
					conv_uu(&conv, &count, 0);
				if (s1[i] == 'o')
					conv_o(&conv, &count, 0);
				if (s1[i] == 'O')
					conv_oo(&conv, &count, 0);
				if (s1[i] == 'x')
					conv_x(&conv, &count, 0);
				if (s1[i] == 'X')
					conv_xx(&conv, &count, 0);
				if (s1[i] == 'p')
					conv_p(&conv, &count);
				if (s1[i] == '%')
					conv_pc(&conv, &count);
			}
			if (s1[i] == ' ' && check_all_option(s1[i]) != 1)
				i++;
			else if (s1[i] == '\0')
			{
				ft_putchar('\n');
				return (count);
			}
			else if (check_all_option(s1[i]) == 0)
			{
				if (conv.flags.lg > 0 && conv.flags.zero == 1)
					count += print_zero(conv.flags.lg - 1);
				if (conv.flags.lg > 0 && conv.flags.zero == 0 && conv.flags.moins == 0)
					count += print_space(conv.flags.lg - 1);
				count += ft_putchar(s1[i]);
				if (conv.flags.lg > 0 && conv.flags.zero == 0 && conv.flags.moins == 1)
					count += print_space(conv.flags.lg - 1);
				i++;
			}
			else
				i++;
		}
	}
	return (count);
}
