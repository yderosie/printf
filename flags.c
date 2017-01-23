/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:43:13 by yderosie          #+#    #+#             */
/*   Updated: 2017/01/23 11:43:14 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_all_option(char c)
{
	if (c != 'h' && c != 'l' && c != 'j' && c != '#' && c != '+' && c != ' ' &&
		c != 'z' && c != 's' && c != 'S' && c != 'p' && c != 'd' && c != 'D' &&
		c != 'i' && c != 'o' && c != 'O' && c != 'u' && c != 'U' && c != 'x' &&
		c != 'X' && c != 'c' && c != 'C' && c != '\0' && c != '%' && c != '	' &&
		ft_isdigit(c) == 0 && c != '.' && c != '-')
	{
		return (0);
	}
	else
		return (1);
}

int		check_conv(char c)
{
	if (c != 's' && c != 'S' && c != 'p' && c != 'd' && c != 'D' && c != 'i' &&
		c != 'o' && c != 'O' && c != 'u' && c != 'U' && c != 'x' && c != 'X' &&
		c != 'c' && c != 'C' && c != '\0' && c != '%')
	{
		return (0);
	}
	else
		return (1);
}

void	flags_present_2(t_conv *conv, char *s1, int i)
{
	if (s1[i] == 'h' && s1[i + 1] != 'h')
		conv->flags.fh = 1;
	if (s1[i] == 'h' && s1[i + 1] == 'h')
	{
		conv->flags.fhh = 1;
		i += 1;
	}
	if (s1[i] == 'l' && s1[i + 1] != 'l')
		conv->flags.fl = 1;
	if (s1[i] == 'l' && s1[i + 1] == 'l')
	{
		conv->flags.fll = 1;
		i += 1;
	}
	if (s1[i] == 'j')
		conv->flags.j = 1;
	if (s1[i] == '#')
		conv->flags.htag = 1;
	if (s1[i] == '+')
		conv->flags.plus = 1;
	if (s1[0] == ' ')
		conv->flags.espace = 1;
	if (s1[i] == 'z')
		conv->flags.z = 1;
}

int		flags_present(t_conv *conv, char *s1, int i)
{
	char	*s2;
	char	*s3;
	int		j;
	int		k;

	j = -1;
	k = 0;
	s2 = (char *)malloc(sizeof(char) * ft_strlen(s1));
	s3 = (char *)malloc(sizeof(char) * ft_strlen(s1));
	if ((s1[i] == ' ' || s1[i] == '	' || s1[i] == '\0') &&
		check_all_option(s1[i] != 1))
		return (i);
	while (check_conv(s1[i]) == 0 && check_all_option(s1[i]) == 1)
	{
		if (s1[i] == '0' && ft_isdigit(s1[i - 1]) == 0)
			conv->flags.zero = 1;
		if (s1[i] == '.')
		{
			conv->flags.point = 1;
			while (ft_isdigit(s1[i + ++j + 1]))
				s2[j] = s1[i + j + 1];
			conv->flags.precision = ft_atoi(s2);
			i += j;
		}
		else if (ft_isdigit(s1[i]) != 0)
			s3[k++] = s1[i];
		if (s1[i] == '-')
			conv->flags.moins = 1;
		flags_present_2(conv, s1, i);
		i++;
	}
	conv->flags.largeur = ft_atoi(s3);
	return (i);
}

void	flags_initialization(t_conv *conv)
{
	conv->flags.zero = 0;
	conv->flags.htag = 0;
	conv->flags.espace = 0;
	conv->flags.moins = 0;
	conv->flags.plus = 0;
	conv->flags.point = 0;
	conv->flags.precision = 0;
	conv->flags.largeur = 0;
	conv->flags.fhh = 0;
	conv->flags.fh = 0;
	conv->flags.fl = 0;
	conv->flags.fll = 0;
	conv->flags.j = 0;
	conv->flags.z = 0;
}

ll		diff_return(t_conv *conv)
{
	if (conv->flags.fhh == 1)
		return ((char)va_arg(conv->arg.ap, int));
	if (conv->flags.fh == 1)
		return ((short)va_arg(conv->arg.ap, int));
	if (conv->flags.fl == 1)
		return (va_arg(conv->arg.ap, li));
	if (conv->flags.fll == 1)
		return (va_arg(conv->arg.ap, ll));
	if (conv->flags.j == 1)
		return (va_arg(conv->arg.ap, intmax_t));
	if (conv->flags.z == 1)
		return (va_arg(conv->arg.ap, size_t));
	else
		return (va_arg(conv->arg.ap, int));
}

ull		diff_u_return(t_conv *conv)
{
	if (conv->flags.fhh == 1)
		return ((unsigned char)va_arg(conv->arg.ap, unsigned int));
	if (conv->flags.fh == 1)
		return ((unsigned short)va_arg(conv->arg.ap, unsigned int));
	if (conv->flags.fl == 1)
		return (va_arg(conv->arg.ap, uli));
	if (conv->flags.fll == 1)
		return (va_arg(conv->arg.ap, ull));
	if (conv->flags.j == 1)
		return (va_arg(conv->arg.ap, uintmax_t));
	if (conv->flags.z == 1)
		return (va_arg(conv->arg.ap, ssize_t));
	else
		return (va_arg(conv->arg.ap, unsigned int));
}
