/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 11:54:08 by yderosie          #+#    #+#             */
/*   Updated: 2014/12/27 16:42:24 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr(t_ll n)
{
	int rt;

	rt = 0;
	if (n == (-9223372036854775807 - 1))
	{
		return (ft_putstr("-9223372036854775808"));
	}
	else
	{
		if (n < 0)
		{
			rt += ft_putchar('-');
			n = -n;
		}
		if (n >= 10)
		{
			rt += ft_putnbr(n / 10);
			rt += ft_putnbr(n % 10);
		}
		else
			return (ft_putchar(48 + n) + rt);
	}
	return (rt);
}

int		ft_putnbr_u(t_ull n)
{
	int rt;

	rt = 0;
	if (n >= 10)
	{
		rt += ft_putnbr_u(n / 10);
		rt += ft_putnbr_u(n % 10);
	}
	else
		return (ft_putchar(48 + n) + rt);
	return (rt);
}
