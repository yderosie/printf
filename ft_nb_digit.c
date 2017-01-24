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

int		ft_nb_digit_u(ull i)
{
	int	j;

	j = 0;
	while (i > 9)
	{
		i = i / 10;
		j++;
	}
	j++;
	return (j);
}

int		ft_nb_digit(ll i)
{
	int	j;
	ll	k;

	j = 0;
	k = i;
	if (i < 0)
	{
		k = -i;
		j++;
	}
	while (k > 9)
	{
		k = k / 10;
		j++;
	}
	j++;
	return (j);
}
