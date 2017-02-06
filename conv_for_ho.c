/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_for_ho.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 15:47:02 by yderosie          #+#    #+#             */
/*   Updated: 2017/02/06 15:47:03 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_o(t_conv *cv, unsigned int *count, int sub_p)
{
	cv->o = conv_octal(diff_u_return(cv));
	if (ft_strlen(cv->o) > 1 && cv->flags.htag == 1 && cv->flags.p == 0)
		*count += ft_putchar('0');
	if (cv->flags.point == 1)
	{
		sub_p = diff_p(cv->flags.p, ft_strlen(cv->o), 0);
		if (cv->flags.p > 0)
			*count += print_space(cv->flags.lg - (ft_strlen(cv->o) + sub_p));
		*count += print_zero(sub_p);
	}
	if (cv->flags.point == 1 && cv->flags.p <= 0 && cv->flags.htag == 0)
		;
	else
		*count += ft_putstr(cv->o);
}

void	conv_oo(t_conv *cv, unsigned int *count, int sub_p)
{
	cv->oo = conv_octal(va_arg(cv->arg.ap, uli));
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

void	conv_x(t_conv *cv, unsigned int *count, int sub_p)
{
	cv->x = diff_u_return(cv);
	if (cv->flags.lg > 0 && cv->flags.moins == 0 && cv->flags.zero == 1)
	{
		if (cv->x != 0 && cv->flags.htag == 1)
			*count += print_zero(cv->flags.lg -
				(ft_strlen(conv_hexa(cv->x)) + 2));
		else
			*count += print_zero(cv->flags.lg - ft_strlen(conv_hexa(cv->x)));
	}
	if (cv->x != 0 && cv->flags.htag == 1)
		*count += ft_putstr("0x");
	if (cv->flags.point == 1)
	{
		sub_p = diff_p(cv->flags.p, ft_strlen(conv_hexa(cv->x)), 0);
		if (cv->flags.p > 0)
			*count += print_space(cv->flags.lg -
				(ft_strlen(conv_hexa(cv->x)) + sub_p));
		*count += print_zero(sub_p);
	}
	if (cv->flags.point == 1 && cv->flags.p <= 0)
		;
	else
		*count += ft_putstr(conv_hexa(cv->x));
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
