/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 16:24:09 by yderosie          #+#    #+#             */
/*   Updated: 2015/02/16 16:24:11 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_nb_digit_u(ull i, t_flags flags)
{
	int	j;

	j = 0;
	while (i > 10)
	{
		i = i / 10;
		j++;
	}
	j++;
	while (flags.precision == 1 && j < flags.precision)
	{
		ft_putchar('0');
		j++;
	}
	return (j);
}

void	ft_nb_digit(ll i, t_flags flags)
{
	int	j;
	ll	k;

	k *= -i; 
	j = 0;
	while (i > 10)
	{
		i = i / 10;
		j++;
	}
	j++;
	while (flags.precision == 1 && j < flags.precision)
	{
		ft_putchar('0');
		j++;
	}
	return (j);
}

void	ft_nb_digit_c(char *s, t_flags flags)
{
	int	i;

	i = ft_strlen(s);
	while (i < flags.precision)
	{
		ft_putchar('0');
		i++;
	}
}