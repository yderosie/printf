/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_for_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:08:43 by yderosie          #+#    #+#             */
/*   Updated: 2017/02/10 17:08:49 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_x2(t_conv *cv, unsigned int *count, int sub_p)
{
	if (cv->x != 0 && cv->flags.htag == 1)
		*count += ft_putstr("0x");
	if (cv->flags.lg > 0 && cv->flags.moins == 0 && cv->flags.zero == 1)
	{
		if (cv->x != 0 && cv->flags.htag == 1)
			*count += print_zero(cv->flags.lg -
				(ft_strlen(conv_hexa(cv->x)) + 2));
		else
			*count += print_zero(cv->flags.lg - ft_strlen(conv_hexa(cv->x)));
	}
	if (cv->flags.point == 1)
	{
		if (cv->flags.p > 0)
			*count += print_space(cv->flags.lg -
				(ft_strlen(conv_hexa(cv->x)) + sub_p));
		*count += print_zero(sub_p);
	}
}

void	conv_x(t_conv *cv, unsigned int *count, int sub_p)
{
	int add;

	add = 0;
	cv->x = diff_u_return(cv);
	if (cv->flags.htag == 1)
		add = 2;
	if (cv->flags.point == 1)
		sub_p = diff_p(cv->flags.p, ft_strlen(conv_hexa(cv->x)), 0);
	if (cv->flags.lg > 0 && cv->flags.moins == 0 && cv->flags.zero == 0 &&
		cv->flags.p <= 0)
		*count += print_space(cv->flags.lg - (ft_strlen(conv_hexa(cv->x))
			+ add));
	conv_x2(cv, count, sub_p);
	if (cv->flags.point == 1 && cv->flags.p <= 0)
	{
		if (cv->flags.lg > 0)
			*count += ft_putchar(' ');
	}
	else
		*count += ft_putstr(conv_hexa(cv->x));
	if (cv->flags.lg > 0 && cv->flags.moins == 1)
		*count += print_space(cv->flags.lg - (ft_strlen(conv_hexa(cv->x))
			+ add));
}

void	conv_xx(t_conv *cv, unsigned int *count, int sub_p)
{
	cv->xx = diff_u_return(cv);
	if (cv->flags.lg > 0 && cv->flags.moins == 0 && cv->flags.zero == 1)
		*count += print_zero(cv->flags.lg - ft_strlen(conv_hexa_x(cv->xx)));
	if (cv->xx != 0 && cv->flags.htag == 1)
		*count += ft_putstr("0X");
	if (cv->flags.point == 1)
	{
		sub_p = diff_p(cv->flags.p, ft_strlen(conv_hexa_x(cv->xx)), 0);
		if (cv->flags.p > 0)
			*count += print_space(cv->flags.lg -
				(ft_strlen(conv_hexa_x(cv->xx)) + sub_p));
		*count += print_zero(sub_p);
	}
	if (cv->flags.point == 1 && cv->flags.p <= 0)
		;
	else
		*count += ft_putstr(conv_hexa_x(cv->xx));
}
