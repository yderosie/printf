/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_for_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 15:49:01 by yderosie          #+#    #+#             */
/*   Updated: 2017/02/06 15:49:02 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_p(t_conv *cv, unsigned int *count)
{
	cv->p = va_arg(cv->arg.ap, void*);
	if (cv->flags.point == 1 && cv->flags.p < 1 && cv->p == 0)
	{
		*count += ft_putstr("0x");
		return ;
	}
	if (cv->flags.lg > 0 && cv->flags.moins == 0 && cv->flags.zero == 0)
		*count += print_space(cv->flags.lg -
			(ft_strlen(conv_hexa((ull)cv->p)) + 2));
	if (cv->p == 0)
		*count += ft_putstr("0x0");
	else
		*count += ft_putstr("0x");
	if (cv->flags.point == 1 && cv->flags.p > 0)
		*count += print_zero(cv->flags.p -
			ft_strlen(conv_hexa((ull)cv->p)));
	if (cv->flags.lg > 0 && cv->flags.moins == 0 && cv->flags.zero == 1)
		*count += print_zero(cv->flags.lg -
			(ft_strlen(conv_hexa((ull)cv->p)) + 2));
	if (!(cv->p == 0))
		*count += ft_putstr(conv_hexa((ull)cv->p));
	if (cv->flags.lg > 0 && cv->flags.moins == 1 && cv->flags.zero == 0)
		*count += print_space(cv->flags.lg -
			(ft_strlen(conv_hexa((ull)cv->p)) + 2));
}

void	conv_pc(t_conv *cv, unsigned int *count)
{
	if (cv->flags.lg > 0 && cv->flags.zero == 1)
		*count += print_zero(cv->flags.lg - 1);
	if (cv->flags.lg > 0 && cv->flags.zero == 0)
		*count += print_space(cv->flags.lg - 1);
	*count += ft_putchar('%');
}
