/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_for_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:09:24 by yderosie          #+#    #+#             */
/*   Updated: 2017/02/10 17:09:27 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		conv_u(t_conv *cv, unsigned int *count, int sub_p)
{
	cv->u = diff_u_return(cv);
	sub_p = diff_p(cv->flags.p, ft_nblen_u(cv->u), 0);
	if (cv->flags.lg > 0 && cv->flags.moins == 0 && cv->flags.zero == 0 &&
		cv->flags.point == 0)
		*count += print_space(cv->flags.lg - (ft_nblen_u(cv->u) + sub_p));
	if (cv->flags.lg > 0 && cv->flags.moins == 0 && cv->flags.zero == 1 &&
		cv->flags.point == 0)
		*count += print_zero(cv->flags.lg - (ft_nblen_u(cv->u) + sub_p));
	if (cv->flags.point == 1)
	{
		if (cv->flags.p > 0)
			*count += print_space(cv->flags.lg -
				(ft_nblen_u(cv->u) + sub_p));
		*count += print_zero(sub_p);
	}
	if (cv->flags.point == 1 && cv->flags.p <= 0)
		;
	else
		*count += ft_putnbr_u(cv->u);
	if (cv->flags.lg > 0 && cv->flags.moins == 1 && cv->flags.zero == 0 &&
		cv->flags.point == 0)
		*count += print_space(cv->flags.lg - (ft_nblen_u(cv->u) + sub_p));
}

void		conv_uu(t_conv *cv, unsigned int *count, int sub_p)
{
	cv->uu = va_arg(cv->arg.ap, t_uli);
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
