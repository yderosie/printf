/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:54:26 by yderosie          #+#    #+#             */
/*   Updated: 2017/01/26 16:54:27 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_space(int i)
{
	int ret;

	ret = 0;
	while (i > 0)
	{
		ret += ft_putchar(' ');
		i--;
	}
	return (ret);
}

int		print_zero(int i)
{
	int ret;

	ret = 0;
	while (i > 0)
	{
		ret += ft_putchar('0');
		i--;
	}
	return (ret);
}
