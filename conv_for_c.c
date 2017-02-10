/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_for_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:09:02 by yderosie          #+#    #+#             */
/*   Updated: 2017/02/10 17:09:05 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		conv_c(t_conv *cv, unsigned int *count, int a)
{
	if (cv->flags.fl == 1)
	{
		cv->cc = va_arg(cv->arg.ap, wint_t);
		if (cv->flags.lg > 0 && cv->flags.moins == 0 && cv->flags.zero == 0)
			*count += print_space(cv->flags.lg - ft_nblen(cv->cc));
		*count += nb_octets_write(cv->cc);
	}
	else
	{
		cv->c = va_arg(cv->arg.ap, int);
		if (cv->flags.lg > 0 && cv->flags.moins == 0 && cv->flags.zero == 0)
			*count += print_space(cv->flags.lg - 1);
		if (cv->flags.lg > 0 && cv->flags.moins == 0 && cv->flags.zero == 1)
			*count += print_zero(cv->flags.lg - 1);
		*count += ft_putchar(cv->c);
		if (cv->flags.lg > 0 && cv->flags.moins == 1 && cv->flags.zero == 0)
			*count += print_space(cv->flags.lg - 1);
	}
}

void		conv_cc(t_conv *conv, unsigned int *count, int a)
{
	conv->cc = va_arg(conv->arg.ap, wint_t);
	*count += nb_octets_write(conv->cc);
}
