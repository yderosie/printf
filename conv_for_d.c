/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_for_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 15:46:38 by yderosie          #+#    #+#             */
/*   Updated: 2017/02/06 15:46:39 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	conv_d_2(t_conv *cv, unsigned int *count, int sub_p)
{
	if (cv->flags.lg > 0 && cv->flags.moins == 0 && cv->flags.zero == 1 &&
		cv->flags.espace == 0)
	{
		if (cv->flags.plus == 1)
			*count += print_zero(cv->flags.lg - (ft_nblen(cv->d) + 1 + sub_p));
		else if (cv->d < 0)
		{
			cv->d = cv->d * -1;
			*count += ft_putchar('-');
			*count += print_zero(cv->flags.lg - (ft_nblen(cv->d) + 1 + sub_p));
		}
		else
		{
			if (cv->flags.point == 1)
				*count += print_space(cv->flags.lg - (ft_nblen(cv->d) + sub_p));
			else
				*count += print_zero(cv->flags.lg - (ft_nblen(cv->d) + sub_p));
		}
	}
	else if (cv->d < 0 && ft_nblen(cv->d) < cv->flags.p)
	{
		cv->d = -cv->d;
		*count += ft_putchar('-');
	}
}

void		conv_d(t_conv *cv, unsigned int *count, int sub_p)
{
	cv->d = diff_return(cv);
	if (cv->d >= 0 && cv->flags.plus == 1)
		*count += ft_putchar('+');
	if (cv->flags.point == 1)
		sub_p = diff_p(cv->flags.p, ft_nblen(cv->d), ((cv->d < 0) ? 1 : 0));
	if (cv->flags.lg > 0 && cv->flags.moins == 0 && cv->flags.zero == 0)
		*count += print_space(cv->flags.lg - (ft_nblen(cv->d) + sub_p));
	if (cv->d >= 0 && cv->flags.espace == 1 && cv->flags.plus == 0)
	{
		*count += ft_putchar(' ');
		if (cv->flags.lg > 0 && cv->flags.moins == 0 && cv->flags.zero == 1)
			*count += print_zero(cv->flags.lg - (ft_nblen(cv->d) + 1 + sub_p));
	}
	conv_d_2(cv, count, sub_p);
	*count += print_zero(sub_p);
	if (cv->flags.point == 1 && cv->flags.p <= 0)
		;
	else
		*count += ft_putnbr(cv->d);
	if (cv->flags.lg > 0 && cv->flags.moins == 1)
		*count += print_space(cv->flags.lg - (ft_nblen(cv->d) + sub_p));
}

void		conv_dd(t_conv *cv, unsigned int *count, int sub_p)
{
	cv->dd = va_arg(cv->arg.ap, li);
	if (cv->flags.point == 1)
		sub_p = diff_p(cv->flags.p, ft_nblen(cv->dd), ((cv->dd < 0) ? 1 : 0));
	if (cv->flags.lg > 0 && cv->flags.moins == 0 && cv->flags.zero == 0)
		*count += print_space(cv->flags.lg - (ft_nblen(cv->dd) + sub_p));
	if (cv->dd >= 0 && cv->flags.zero == 1)
		*count += print_zero(cv->flags.lg - (ft_nblen(cv->dd) + sub_p));
	if (cv->flags.p > 0)
		*count += print_zero((ft_nblen(cv->dd) + sub_p));
	*count += ft_putnbr(cv->dd);
}

void		conv_u(t_conv *conv, unsigned int *count, int sub_p)
{
	conv->u = diff_u_return(conv);
	if (conv->flags.point == 1)
	{
		sub_p = diff_p(conv->flags.p, ft_nblen_u(conv->u), 0);
		if (conv->flags.p > 0)
			*count += print_space(conv->flags.lg -
				(ft_nblen_u(conv->u) + sub_p));
		*count += print_zero(sub_p);
	}
	if (conv->flags.point == 1 && conv->flags.p <= 0)
		;
	else
		*count += ft_putnbr_u(conv->u);
}

void		conv_uu(t_conv *cv, unsigned int *count, int sub_p)
{
	cv->uu = va_arg(cv->arg.ap, uli);
	if (cv->flags.point == 1)
	{
		sub_p = diff_p(cv->flags.p, ft_nblen_u(cv->uu), 0);
		if (cv->flags.p > 0)
			*count += print_space(cv->flags.lg - (ft_nblen_u(cv->uu) + sub_p));
		*count += print_zero(sub_p);
	}
	if (cv->flags.point == 1 && cv->flags.p <= 0)
		;
	else
		*count += ft_putnbr_u(cv->uu);
}
