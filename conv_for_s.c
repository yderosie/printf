/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_for_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 15:46:14 by yderosie          #+#    #+#             */
/*   Updated: 2017/02/06 15:46:18 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		conv_s(t_conv *cv, unsigned int *count, int a)
{
	int sub_for_s;

	if (cv->flags.fl == 1)
		return (conv_ss(cv, count, 0));
	cv->s = va_arg(cv->arg.ap, char*);
	if (cv->s != NULL)
	{
		if (cv->flags.point == 1 && cv->flags.p < ft_strlen(cv->s))
			sub_for_s = cv->flags.p;
		else
			sub_for_s = ft_strlen(cv->s);
		if (cv->flags.lg > 0 && cv->flags.zero == 1)
			*count += print_zero(cv->flags.lg - sub_for_s);
		if (cv->flags.lg > 0 && cv->flags.zero == 0)
			*count += print_space(cv->flags.lg - sub_for_s);
		if (cv->flags.point == 1 && cv->flags.p < ft_strlen(cv->s))
			*count += ft_putnstr(cv->s, cv->flags.p);
		else
			*count += ft_putstr(cv->s);
	}
	else if (cv->flags.zero == 1 && cv->flags.point == 1 && cv->s == NULL)
		*count += print_zero(cv->flags.lg);
	else
		*count += ft_putstr("(null)");
}

static void	conv_ss_2(t_conv *cv, unsigned int *count, int sub_for_s)
{
	if (cv->flags.point == 1 && cv->flags.p < ft_strlen_w(cv->ss))
		sub_for_s = diff_sw(cv->ss, cv->flags);
	else
		sub_for_s = ft_strlen_w(cv->ss);
	if (cv->flags.lg > 0 && cv->flags.zero == 1 && cv->flags.moins == 0)
		*count += print_zero(cv->flags.lg - sub_for_s);
	if (cv->flags.lg > 0 && cv->flags.zero == 0 && cv->flags.moins == 0)
		*count += print_space(cv->flags.lg - sub_for_s);
}

void		conv_ss(t_conv *cv, unsigned int *count, int len)
{
	int k;

	k = -1;
	cv->ss = va_arg(cv->arg.ap, wchar_t*);
	if (cv->ss == NULL)
	{
		*count += ft_putstr("(null)");
		return ;
	}
	conv_ss_2(cv, count, 0);
	while (cv->ss[++k] != '\0')
	{
		if (cv->flags.point == 0)
			len += nb_octets_write(cv->ss[k]);
		else if (cv->flags.point == 1 && len_cw(cv->ss[k], len, cv->flags)
			<= cv->flags.p)
			len += nb_octets_write(cv->ss[k]);
	}
	*count += len;
	if (cv->flags.lg > 0 && cv->flags.zero == 0 && cv->flags.moins == 1)
		*count += print_space(cv->flags.lg - ft_strlen_w(cv->ss));
}

void		conv_c(t_conv *cv, unsigned int *count, int a)
{
	if (cv->d > 0 && cv->flags.fl == 1)
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
			*count += print_space(cv->flags.lg - ft_nblen(cv->c));
		if (cv->flags.lg > 0 && cv->flags.moins == 0 && cv->flags.zero == 1)
			*count += print_zero(cv->flags.lg - ft_nblen(cv->c));
		*count += ft_putchar(cv->c);
	}
}

void		conv_cc(t_conv *conv, unsigned int *count, int a)
{
	conv->cc = va_arg(conv->arg.ap, wint_t);
	*count += nb_octets_write(conv->cc);
}
