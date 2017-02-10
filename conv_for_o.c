/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_for_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:08:57 by yderosie          #+#    #+#             */
/*   Updated: 2017/02/10 17:08:58 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		conv_o2(t_conv *cv, unsigned int *count, int sub_p)
{
	if (cv->flags.lg > 0 && cv->flags.moins == 0 && cv->flags.zero == 1
		&& cv->flags.point == 0)
		*count += print_zero(cv->flags.lg - (ft_strlen(cv->o)));
	if (ft_strlen(cv->o) > 1 && cv->flags.htag == 1 && cv->flags.p == 0)
		*count += ft_putchar('0');
	if (cv->flags.point == 1)
	{
		if (cv->flags.p > 0 && cv->flags.moins == 0)
			*count += print_space(cv->flags.lg - (ft_strlen(cv->o) + sub_p));
		*count += print_zero(sub_p);
	}
}

void			conv_o(t_conv *cv, unsigned int *count, int sub_p)
{
	int add;

	add = 0;
	cv->o = conv_octal(diff_u_return(cv));
	if (cv->flags.htag == 1)
		add = 1;
	sub_p = diff_p(cv->flags.p, ft_strlen(cv->o), 0);
	if (cv->flags.lg > 0 && cv->flags.moins == 0 && cv->flags.zero == 0
		&& cv->flags.p <= 0)
		*count += print_space(cv->flags.lg - (ft_strlen(cv->o) + add + sub_p));
	conv_o2(cv, count, sub_p);
	if (cv->flags.point == 1 && cv->flags.p <= 0 && cv->flags.htag == 0)
	{
		if (cv->flags.lg > 0)
			*count += ft_putchar(' ');
	}
	else
		*count += ft_putstr(cv->o);
	if (cv->flags.lg > 0 && cv->flags.moins == 1)
		*count += print_space(cv->flags.lg - (ft_strlen(cv->o) + add + sub_p));
}

void			conv_oo(t_conv *cv, unsigned int *count, int sub_p)
{
	cv->oo = conv_octal(va_arg(cv->arg.ap, t_uli));
	if (cv->flags.htag == 1)
		*count += ft_putchar('0');
	if (cv->flags.point == 1)
	{
		sub_p = diff_p(cv->flags.p, ft_strlen(cv->oo), 0);
		if (cv->flags.p > 0)
			*count += print_space(cv->flags.lg -
				(ft_strlen(cv->oo) + sub_p));
		*count += print_zero(sub_p);
	}
	if (cv->flags.point == 1 && cv->flags.p <= 0)
		;
	else
		*count += ft_putstr(cv->oo);
}
