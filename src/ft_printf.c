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

static void		setup(t_fct *fct)
{
	ft_bzero(fct, 255);
	fct['s'] = &conv_s;
	fct['S'] = &conv_ss;
	fct['i'] = &conv_d;
	fct['d'] = &conv_d;
	fct['D'] = &conv_dd;
	fct['u'] = &conv_u;
	fct['U'] = &conv_uu;
	fct['o'] = &conv_o;
	fct['O'] = &conv_oo;
	fct['x'] = &conv_x;
	fct['X'] = &conv_xx;
	fct['p'] = &conv_p;
	fct['c'] = &conv_c;
	fct['C'] = &conv_cc;
	fct['%'] = &conv_pc;
}

static void		parse_2(char c, t_conv *conv, unsigned int *count)
{
	static t_fct	fct[255];
	static int		init = 0;

	if (init == 0)
	{
		setup(fct);
		init = 1;
	}
	if (fct[(int)c] != NULL)
		fct[(int)c](conv, count, 0);
}

static int		parse(t_conv *cv, unsigned int *count, int *i, char *s1)
{
	flags_initialization(cv);
	*i += flags_present(cv, s1 + *i + 1, 0) + 1;
	if (cv->flags.error == 1 || s1[*i] == '\0')
		return (0);
	if (check_conv(s1[*i]) == 1)
		parse_2(s1[*i], cv, count);
	if (s1[*i] == ' ' && check_all_option(s1[*i]) != 1)
		(*i)++;
	else if (check_all_option(s1[*i]) == 0)
	{
		if (cv->flags.lg > 0 && cv->flags.zero == 1)
			*count += print_zero(cv->flags.lg - 1);
		if (cv->flags.lg > 0 && cv->flags.zero == 0 && cv->flags.moins == 0)
			*count += print_space(cv->flags.lg - 1);
		*count += ft_putchar(s1[*i]);
		if (cv->flags.lg > 0 && cv->flags.zero == 0 && cv->flags.moins == 1)
			*count += print_space(cv->flags.lg - 1);
		(*i)++;
	}
	else
		(*i)++;
	return (1);
}

static void		print_s(unsigned int *count, int *i, char *s1)
{
	int		j;
	char	*s2;

	j = 0;
	s2 = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	ft_bzero(s2, ft_strlen(s1) + 1);
	while (s1[*i] != '%' && s1[*i] != '\0')
		s2[j++] = s1[(*i)++];
	s2[j] = '\0';
	*count += ft_putstr(s2);
}

int				ft_printf(char const *format, ...)
{
	char				*s1;
	int					i;
	t_conv				conv;
	unsigned int		count;
	int					error;

	i = 0;
	count = 0;
	s1 = (char *)format;
	va_start(conv.arg.ap, format);
	va_copy(conv.arg.save, conv.arg.ap);
	while (s1[i] != '\0')
	{
		if (ft_strlen(s1) == 1 && s1[0] == '%')
			return (0);
		print_s(&count, &i, s1);
		if (s1[i] == '%' && s1[i + 1] != '\0')
			error = parse(&conv, &count, &i, s1);
		else
			return (count);
		if (error == 0)
			return (0);
	}
	return (count);
}
